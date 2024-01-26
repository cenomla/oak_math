project('oak_math', 'cpp', default_options : ['cpp_std=c++17', 'warning_level=3', 'werror=true'])

includes = include_directories('include')
oak_math_dep = declare_dependency(include_directories: includes)
reflection_sources = files(['include/oak_math/vec.h', 'include/oak_math/quat.h', 'include/oak_math/mat.h'])
