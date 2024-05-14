speed_exe = executable('speed', 'speed.c',
     include_directories: inc,
     link_with: lib)

test('speed', speed_exe,
     args: ['../files/The Adventures of Sherlock Holmes.txt'])
