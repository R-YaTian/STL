cmake_minimum_required(VERSION 3.15)
project(vcstl_simple_tests LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# Building test
add_executable(test_codecvt_ids test_codecvt_ids.cpp)
target_compile_definitions(test_codecvt_ids PRIVATE _SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING)
target_compile_options(test_codecvt_ids PRIVATE /utf-8)

add_executable(test_memory_resource test_memory_resource.cpp)
target_compile_options(test_memory_resource PRIVATE /utf-8)

add_executable(test_spec_math test_spec_math.cpp)
target_compile_options(test_spec_math PRIVATE /utf-8)

add_executable(test_atomic_wait test_atomic_wait.cpp)
target_compile_options(test_atomic_wait PRIVATE /utf-8)
