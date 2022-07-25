import os
import sys

REMOVE_PATHS = [
    '{% if not cookiecutter.build_for_windows %} conda\camera\bld.bat {% endif %}',
    '{% if not cookiecutter.build_for_windows %} conda\tango\bld.bat {% endif %}',
    '{% if not cookiecutter.build_for_linux %} conda\camera\build.sh {% endif %}',
    '{% if not cookiecutter.build_for_linux %} conda\tango\build.sh {% endif %}',
]

for path in REMOVE_PATHS:
    path = path.strip()
    if path and os.path.exists(path):
        if os.path.isdir(path):
            os.rmdir(path)
        else:
            os.unlink(path)
