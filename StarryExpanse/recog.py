import os
import sys

try:
	from builtins import input
except:
	pass
import subprocess
import sys

cog_command = []

if 'COG_BIN' in os.environ:
    cog_py_path = os.environ['COG_BIN']
    cog_command = [sys.executable, cog_py_path]
else:
    if sys.platform == 'darwin':
        cog_command = ['cog.py']
    else:
        cog_py_path = os.path.join(os.path.dirname(sys.executable), 'Scripts', 'cog.py')
        cog_command = [sys.executable, cog_py_path]

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
