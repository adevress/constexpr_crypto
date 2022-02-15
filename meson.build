project('constexpr_meson', 'cpp',
 version : '0.1',
 default_options : ['warning_level=3', 'cpp_std=c++17'])




incdir = include_directories('include')


th = executable('test_hash', 'src/tests/test_hash.cpp', include_directories : incdir)


test('test hash', th)
