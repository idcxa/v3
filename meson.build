project('ct', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

exe = executable('ct', 'src/ct.c++',
  install : false)

test('basic', exe)
