project('aoc2020', 'cpp')

cmake = import('cmake')

# For using C++20 ranges
ranges_proj = cmake.subproject('range-v3')
ranges = ranges_proj.dependency('range-v3')

fmt_dep = dependency('fmt')
inc_dir = include_directories('include')

executable('day6', sources: ['src/day6.cpp'], dependencies: [fmt_dep, ranges], include_directories: inc_dir, override_options: ['cpp_std=c++20'])
