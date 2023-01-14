cmake_minimum_required (VERSION 3.5)

project(subprojects)

# Add sub directories
add_subdirectory(library)
add_subdirectory(speedtest)
add_subdirectory(example)
add_subdirectory(tests)
