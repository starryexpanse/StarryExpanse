#!/usr/bin/env python3

from __future__ import print_function

import csv
import fileinput
import re
import sys

class Item(object):
  def __init__(self, name):
    self.name = name
    self.parent = None
    self.child_names = []
    self.children = dict()
    self.link = None
    self.positions = None
    self.raw_positions = None
    self.power = None
    self.lock = None
    self.notes = None

  @staticmethod
  def ProcessNumbers(str):
    """Process 'foo [1..2]' and return ['foo 1', 'foo 2'].

    >>> Item.ProcessNumbers('foo [1..2]')
    ['foo 1', 'foo 2']
    >>> Item.ProcessNumbers('Hatch')
    ['Hatch']
    >>> Item.ProcessNumbers('foobar 1')
    ['foobar 1']
    >>> Item.ProcessNumbers('Door[1..2]')
    ['Door1', 'Door2']
    """
    p = re.compile(r'^(.*)\[(\d+)\.\.(\d+)\](.*)$', re.IGNORECASE)
    m = p.match(str)
    if m:
      before = m.group(1)
      minval = int(m.group(2))
      maxval = int(m.group(3))
      after = m.group(4)
      if maxval <= minval:
        raise Exception('Min must be less than max')
      return ['%s%d%s' % (before, i, after) for i in range(minval, maxval+1)]
    else:
      return [str]

  def AddChild(self, child):
    if child.name in self.children:
      raise Exception('%s already has child %s' % (self.name, child.name))
    self.child_names.append(child.name)
    self.children[child.name] = child
    child.parent = self

  def IsMoveable(self):
    return self.positions and len(self.positions) > 0

  def SetLink(self, value):
    self.link = value

  def SetPositions(self, value):
    if not value:
      return
    self.raw_positions = value
    if '/' in value:
      self.positions = value.split('/')
    elif ',' in value:
      self.positions = value.split(',')
    else:
      self.positions = Item.ProcessNumbers(value)

  def SetPower(self, value):
    if value == ['']:
      return
    self.power = value

  def SetLock(self, value):
    if value == ['']:
      return
    self.lock = value

  def SetNotes(self, value):
    self.notes = value

  def GetEnumBaseString(self):
    if self.name:
      return ''.join(self.name.split())
    else:
      return None

  def GetEnumString(self):
    if self.parent:
      parent_name = self.parent.GetEnumString()
      if parent_name:
        return '%s_%s' % (parent_name, self.GetEnumBaseString())
      else:
        return self.GetEnumBaseString()
    else:
      return self.GetEnumBaseString()

  def Flatten(self):
    all_children = [self]
    for child_name in self.child_names:
      all_children.extend(self.children[child_name].Flatten())
    return all_children

  def NumMoveables(self):
    num_moveable = 0
    for item in self.Flatten():
      if item.IsMoveable():
        num_moveable += 1
    return num_moveable

  def Depth(self):
    if self.parent:
      return self.parent.Depth() + 1
    return 0

  def WantsToBeHeading(self):
    """Does this item want to be a heading?"""
    if len(self.children) > 0:
      return True
    return not self.IsMoveable()

  def MakeAllChildrenHeadings(self):
    """Should *all* of this item's children be headings?"""
    if len(self.children) == 0:
      return False
    for child_name in self.child_names:
      child = self.children[child_name]
      if not child.WantsToBeHeading():
        return False
    return True

  @staticmethod
  def DuplicateChar(ch, num_times):
    return ''.join(ch for i in range(num_times))

  def WikiSuffixText(self):
    items = []
    if self.positions:
      if len(self.positions) <= 2:
        items.append('[' + '/'.join(self.positions) + ']')
      else:
        items.append('[' + self.raw_positions + ']')
    if self.power:
      items.append('[' + '/'.join(self.power) + ']')
    if self.lock:
      items.append('[' + '/'.join(self.lock) + ']')
    if self.notes:
      items.append('(%s)' % self.notes)
    return ', '.join(items)

  def PrintWiki(self, list_depth):
    depth = self.Depth()
    if self.link:
      name = '[%s %s]' % (self.link, self.name)
    else:
      name = self.name

    if list_depth >= 0:
      # myself and all children need to be lists.
      list_depth += 1
      v = Item.DuplicateChar('*', list_depth)
      suffix = self.WikiSuffixText()
      if suffix:
        print(v, name, suffix)
      else:
        print(v, name)
    else:
      # I'm a heading.
      v = Item.DuplicateChar('=', depth + 1)
      print(v, name, v)
      if not self.MakeAllChildrenHeadings():
        list_depth = 0
      if self.notes:
        print(self.notes)

    for child_name in self.child_names:
      child = self.children[child_name]
      child.PrintWiki(list_depth)

class Interactable(object):
  def __init__(self, csv_stream):
    # No name is required for root item.
    self.riven = Item(None)
    self.LoadFromStream(csv_stream)

  def LoadFromStream(self, csv_stream):
    parent_stack = [self.riven]
    column_names = ['Island', 'L2', 'L3', 'L4', 'L5']
    row_num = 1  # Start at 1 for ignored header row.
    try:
      reader = csv.DictReader(csv_stream)
      for row in reader:
        row_num += 1
        item_name = None
        for column_name in column_names:
          if row[column_name]:
            item_name = row[column_name]
            parent_stack = parent_stack[:1+column_names.index(column_name)]
            break
        if not item_name:
          msg = 'must have a value in one and only %s' % str(column_names)
          raise Exception(msg)
        parent = parent_stack[-1]
        item = None
        for iname in Item.ProcessNumbers(item_name):
          item = Item(iname)
          parent.AddChild(item)
          if 'Link' in row:
            item.SetLink(row['Link'])
          if 'Positions' in row:
            item.SetPositions(row['Positions'])
          if 'Power' in row:
            item.SetPower(row['Power'].split('/'))
          if 'Lock' in row:
            item.SetLock(row['Lock'].split('/'))
          if 'Notes' in row:
            item.SetNotes(row['Notes'])
        parent_stack.append(item)
    except Exception as e:
      new_msg = 'CSV line %d: %s' % (row_num, str(e))
      raise Exception(new_msg)

  def PrintEnums(self):
    enums = []
    for item in self.riven.Flatten():
      if True or item.IsMoveable():
        name = item.GetEnumString()
        if name:
          enums.append(name)
    for enum in sorted(enums):
      print(enum)

  def PrintWiki(self):
    script_url = 'https://github.com/starryexpanse/StarryExpanse/blob/master/process-devices.py'
    with open('spreadsheet_url.txt', 'r') as f:
      spreadsheet_url = f.readline()
    msg = """'''Do not edit this document directly'''. It is automatically generated by [%s a script]. To change this document make changes to [%s the spreadsheet] and re-run the script.""" % (script_url, spreadsheet_url)
    banner = '{{Note|note=%s}}' % msg
    print(banner)

    # Print the statistics
    print('== Statistics ==')
    print('{| class="wikitable"')
    print('|-')
    print('! Island || Movable Devices')
    total_moveable = 0
    for child_name in self.riven.child_names:
      child = self.riven.children[child_name]
      print('|-')
      print('|', child.name)
      print('| style="text-align:right;" |', child.NumMoveables())
      total_moveable += child.NumMoveables()
    print('|-')
    print('! Total || style="text-align:right;" | %d' % total_moveable)
    print('|}')

    # Now the island wiki text
    for island_name in self.riven.child_names:
      island = self.riven.children[island_name]
      island.PrintWiki(-1)

if __name__ == '__main__':
  import doctest
  doctest.testmod()
  try:
    interactable = Interactable(fileinput.input())
    #interactable.PrintEnums()
    interactable.PrintWiki()
  except Exception as e:
    raise
    print('ERROR: %s' % str(e), file=sys.stderr)
    sys.exit(1)
