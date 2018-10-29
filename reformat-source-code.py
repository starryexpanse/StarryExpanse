# vim: set et,sts=3,ts=3,ai

import json
import subprocess
import os
import sys

platform = sys.platform

with open('../Config/LocalConfig.json', 'r') as f:
        config = json.load(f)

failed = 0
succeeded = 0

CLANGABLE = ('cpp', 'h')
DOS2UNIXABLE = CLANGABLE + ('json', 'sh', 'py')

ALL_PROCESSABLE = CLANGABLE + DOS2UNIXABLE

for root, dirs, files in os.walk('./'):
    for candidate in files:
        extension = candidate.rpartition('.')[2].lower()
        if extension in ALL_PROCESSABLE:
            path = os.path.join(root, candidate)
            print('Formatting', path, '...')

            cmds = []
            if extension in CLANGABLE:
                cmds.append([config['paths'][platform]['clang-format'], '-i', path])
            if extension in DOS2UNIXABLE:
                cmds.append([config['paths'][platform]['dos2unix'], path])

            for cmd in cmds:
                result = subprocess.check_call(cmd)
                if result != 0:
                    print('Failed!')
                    failed += 1
                else:
                    succeeded += 1

if failed > 0:
    print('Several commands failed (%d).' % failed)
else:
    print('Done, no failures.')

if len(sys.argv) >= 2 and sys.argv[1] == '--no-interactive':
    pass
else:
    while True: pass
