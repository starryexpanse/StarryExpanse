import json
import subprocess
import os

with open('../Config/LocalConfig.json', 'r') as f:
	config = json.load(f)

failed = 0
succeeded = 0

for root, dirs, files in os.walk('./StarryExpanse'):
	candidates = [file for file in files if (file.lower().endswith('.cpp') or file.lower().endswith('.h'))]
	for candidate in candidates:
		path = os.path.join(root, candidate)
		print('Formatting', path, '...')
		for cmd in ([config['paths']['dos2unix'], path], [config['paths']['clang-format'], '-i', path]):
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

while True: pass
