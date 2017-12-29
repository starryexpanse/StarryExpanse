try:
	from builtins import input
except:
	pass
import subprocess
import sys

cog_command = []
if sys.platform == 'darwin':
    cog_command = ['cog.py']
else:
    cog_command = ['python', r'C:\Python36\Scripts\cog.py']

files = [
    'LoadGroups/LoadGroupInfo.cpp',
    'LoadGroups/ELoadGroups.h',
    'SaveGame/RivenSaveGame.cpp',
    'SaveGame/RivenSaveGame.h',
    'SaveGame/ESaveGameField.cpp',
    'SaveGame/ESaveGameField.h',
]

try:
    subprocess.check_call(cog_command + ['-r'] + files)
except Exception as e:
    print(e.message)

print("Complete!")

try:
    raw_input()
except NameError:
    input()
