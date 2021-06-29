project('aoc2020', 'cpp')

cmake = import('cmake')

# For using C++20 ranges
ranges_proj = cmake.subproject('range-v3')
ranges_dep = ranges_proj.dependency('range-v3')

# For better formatting
fmt_proj = subproject('fmt')
fmt_dep = fmt_proj.get_variable('fmt_dep')

executable('day6', sources: ['src/day6.cpp'], dependencies: [fmt_dep, ranges_dep], override_options: ['cpp_std=c++20'])
