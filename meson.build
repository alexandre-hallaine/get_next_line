project('GetNextLine', 'c', version: '1.0.0')

src = files('src/get_next_line.c')

inc = include_directories('include')

lib = static_library('gnl', src,
    include_directories: inc,
    install: true
)

dep = declare_dependency(
    include_directories: inc,
    link_with: lib
)

install_headers('include/get_next_line.h')

subdir('tests')
