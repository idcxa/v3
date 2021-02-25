project(
	'CTEngine', 
	'cpp', 'rust',
  	version : '0.3',
  	license : 'ISC',
  	default_options : ['warning_level=3',
                       'cpp_std=c++20']
)

i18n = import('i18n')

add_global_arguments(
	'-lstdc++', '-O', 
	language : 'cpp'
)

conf_data = configuration_data()
conf_data.set('PROJECT_NAME', meson.project_name())
conf_data.set('EXEC_NAME', meson.project_name())
conf_data.set('VERSION', meson.project_version())

sources = ['src/main.cpp', 
			'src/spec/uci.cpp',
			'src/spec/position.cpp']
pkgmod = import('pkgconfig')


exe = executable('ctengine', sources,
  install : false)

test('basic', exe)

# meson.add_install_script('meson/post_install.py')
