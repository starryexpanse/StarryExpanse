name = input('Enum name, PascalCase:')
desc = input('Description of what it represents:')

contents = ''
i = 0
while True:
	i += 1
	comp_desc = input('PascalCase name of component #' + str(i) + ' (leave empty if done):')
	if comp_desc == '':
		break
	comp_disp = input('In-Editor display name for component #' + str(i) + ':')
	disp = repr(comp_disp) if comp_disp != '' else comp_desc
	if i != 0:
		contents += ',\n'
	contents += '  ' + '%s UMETA(DisplayName = %s),' % (comp_desc, disp)

vars = { 'desc': desc, 'name': name, 'contents': contents }

body = u"""
//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#include "Enums/E{name}.h"
#include "StarryExpanse.h"

"""

header = u"""
//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

// Description: {desc}

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "E{name}.generated.h"

UENUM(BlueprintType)
enum class E{name} : uint8 {{
{contents}
}};

""" % vars

with open('StarryExpanse/Enums/E%s.cpp' % name, 'w') as f:
	f.write(body.format(**vars))

with open('StarryExpanse/Enums/E%s.h' % name, 'w') as f:
	f.write(header.format(**vars))
