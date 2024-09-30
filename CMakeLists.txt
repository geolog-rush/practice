cmake_minimum_required(VERSION 3.28)

project(practice VERSION 1.0 LANGUAGES CXX)
add_compile_options(-Wpedantic
                    -Wall
                    -Wextra
                    -Werror
                    -Wno-long-long
                    -Wno-variadic-macros)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Debug")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(8_power_of_two 8_power_of_two.cpp)
add_executable(c_2_print_uint32 c_2_print_uint32.cpp)

set(targets
        1_circle_buf
        2_bit_multiply
        3_seeding_random
        4_linked_list
        5_number_missing
        6_constant_O_array
        10_palindrome
        c_1_binary_tree
        c_3_black_white_sort

        instant_array
        print_fibonacci
   )

foreach(binary IN LISTS targets)
    set(target_lib "")
    if (EXISTS "${CMAKE_SOURCE_DIR}/${binary}.cpp")
        add_library(${binary} ${binary}.cpp)
        set(target_lib ${binary})
    endif()

    if (EXISTS "${CMAKE_SOURCE_DIR}/${binary}_test.cpp")
        set(binary_test ${binary}_test)
        add_executable(${binary_test} ${binary_test}.cpp)
        target_link_libraries(${binary_test} GTest::gtest_main ${target_lib})
        gtest_discover_tests(${binary_test})
    endif()
endforeach()
