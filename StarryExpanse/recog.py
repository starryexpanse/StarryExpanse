import os
import sys

try:
	from builtins import input
except:
	pass
import subprocess

def find_how_to_run_cog():
    script_path = cog_py_path = os.path.join(os.path.dirname(sys.executable), 'Scripts', 'cog.py')
    possible_commands = [
        'cog.py',
        'cog'
    ]
    if os.path.isfile(script_path):
        return ('using_python', script_path)

    if sys.platform.startswith('win'):
        test_func = 'where'
    else:
        test_func = 'which'
    
    for command in possible_commands:
        if os.popen('%s %s' % (test_func, command)):
            return ('command', command)

cog_approach = find_how_to_run_cog()
if not cog_approach:
    print('Could not find cog :(')

if cog_approach[0] == 'using_python':
    cog_command = ['python', cog_py_path]
elif cog_approach[0] == 'command':
    cog_command = [cog_approach[1]]

files = [
    'LoadGroups/LoadGroupInfo.cpp',
    'LoadGroups/ELoadGroups.h',
    'SaveGame/RivenSaveGame.cpp',
    'SaveGame/RivenSaveGame.h',
    'SaveGame/ESaveGameField.cpp',
    'SaveGame/ESaveGameField.h',
]

realpath_here = os.path.dirname(os.path.realpath(__file__))
os.chdir(realpath_here)

try:
    subprocess.check_call(cog_command + ['-r'] + files)
except Exception as e:
    print(str(e))

print("Complete!")

try:
    raw_input()
except NameError:
    input()
