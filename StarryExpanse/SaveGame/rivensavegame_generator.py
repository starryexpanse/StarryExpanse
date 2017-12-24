from __future__ import print_function

import cog
import sys
import yaml

root = None

with open("./Config/save_game_structure.yaml", 'r') as stream:
    try:
        root = yaml.load(stream)
    except yaml.YAMLError as exc:
        print(exc, file=sys.stderr)
   
def stringify(val):
    if type(val) == type(True):
        return str(val).lower()
    return str(val)

def underscorify(path):
    return '_'.join([section for section in path if section != ''])

path = []
vars = []

for island, areas in root.items():
    path.append(island)
    for area, atoms in areas.items():
        path.append(area)
        for atom_key in atoms.keys():
            path.append(atom_key)
            for atom in atoms[atom_key]:
                path.append(atom['name'])
                vars.append([
                    atom['type'],
                    underscorify(path),
                    stringify(atom['initial']),
                ])
                path.pop()
            path.pop()
        path.pop()
    path.pop()

def p(x):
    # Easy hack to make the line endings consistently DOS-style
    cog.outl(x)
