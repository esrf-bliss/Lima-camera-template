import re
import sys

PROJECT_REGEX = r'^[_a-zA-Z][_a-zA-Z0-9]+$'

project_name = '{{ cookiecutter.project_name }}'
if not re.match(PROJECT_REGEX, project_name):
    print('ERROR: %s is not a valid Project module name!' % project_name)
    sys.exit(1)

build_for_windows = bool('{{ cookiecutter.build_for_windows }}')
if not isinstance(build_for_windows, bool):
    print('ERROR: %s is not a valid value [true | false]!' % build_for_windows)
    sys.exit(1)

build_for_linux = bool('{{ cookiecutter.build_for_linux }}')
if not isinstance(build_for_linux, bool):
    print('ERROR: %s is not a valid value [true | false]!' % build_for_linux)
    sys.exit(1)
