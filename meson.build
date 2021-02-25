project('CTEngine', 'cpp',
  version : '0.1',
  license : 'ISC',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

add_global_arguments('-lstdc++', '-O', language : 'cpp')

sources = ['src/main.cpp', 'src/spec/uci.cpp']
pkgmod = import('pkgconfig')

incdir = include_directories(['src',
							  'src/spec'])

exe = executable('ctengine', 'src/main.cpp',
  install : false)

test('basic', exe)
