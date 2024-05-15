project('get_next_line', 'c', version: '1.0.0')

src = files('src/get_next_line.c')

inc = include_directories('include')

lib = library('gnl', src,
    include_directories: inc,
    install: true)

install_headers('include/get_next_line.h')

subdir('tests')
