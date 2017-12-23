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

vars = []

for island, areas in root.items():
    for area, atoms in areas.items():
        for atom_name in atoms.keys():
            name = island + '_' + area + ('_' if area else '') + atom_name
            for atom in atoms[atom_name]:
                vars.append([
                    atom['type'],
                    name + '_' + atom['name'],
                    stringify(atom['initial']),
                ])

def p(x):
    # Easy hack to make the line endings consistently DOS-style
    cog.outl(x)
