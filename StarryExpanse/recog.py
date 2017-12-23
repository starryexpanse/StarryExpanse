import subprocess
import sys

cog_command = []
if sys.platform == 'darwin':
    cog_command = ['cog.py']
else:
    cog_command = ['python', 'C:\Python36\Scripts\cog.py']

files = [
    'LoadGroups/LoadGroupInfo.cpp',
    'LoadGroups/ELoadGroups.h',
    'SaveGame/RivenSaveGame.cpp',
    'SaveGame/RivenSaveGame.h',
    'SaveGame/ESaveGameField.cpp',
    'SaveGame/ESaveGameField.h',
]

subprocess.call(cog_command + ['-r'] + files)

print("Complete!")
input()
