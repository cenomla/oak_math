sources = [
	'func.cpp',
	'mat.cpp',
	'quat.cpp',
	'vec.cpp',
]

oak_math = library('oakmath', sources, include_directories: includes, install : true)

oak_math_dep = declare_dependency(link_with: oak_math, include_directories: includes)
