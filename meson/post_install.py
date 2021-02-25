import os, gettext, subprocess

schemadir = os.path.join(os.environ['MESON_INSTALL_PREFIX'], 'share', 'schemas')

if not os.environ.get('DESTDIR'):
    print('Compiling schemas...')
    subprocess.call(['cpp-compile-schemas', schemadir])
