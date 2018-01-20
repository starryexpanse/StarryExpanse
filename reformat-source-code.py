import json
import subprocess
import os

with open('../Config/LocalConfig.json', 'r') as f:
	config = json.load(f)

for root, dirs, files in os.walk('Source/StarryExpanse'):
	candidates = [file for file in files if (file.lower().endswith('.cpp') or file.lower().endswith('.h'))]
	for candidate in candidates:
		path = os.path.join(root, candidate)
		print('Formatting', path, '...')
		subprocess.check_call([config['paths']['clang-format'], '-i', path])

print('All done!')
while True: pass