cmake_minimum_required(VERSION 3.14)
project(printf C)
set(CMAKE_C_STANDARD 11)

#includes
include_directories(general)
include_directories(test)
include_directories(general/libft/includes)
include_directories(general/includes)

# Usage example of original printf
add_executable(Usage other/main_usage.c)

# Libft with getline
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libft/ft_*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${PROJECT_SOURCE_DIR}/general/libft/get_next_line.c)
add_library(ft STATIC ${LIBFT_FILES})


#printf
file(GLOB_RECURSE PRINTF_FILES "${PROJECT_SOURCE_DIR}/general/srcs/*.c")
add_library(ftprintf STATIC ${PRINTF_FILES} ${LIBFT_FILES})



#printf general test
add_executable(printf_test_test test/test_test.c)
target_link_libraries(printf_test_test ${PROJECT_BINARY_DIR}/libmu.a)
target_link_libraries(printf_test_test ${PROJECT_BINARY_DIR}/libftprintf.a)

#printf simple str test
add_executable(printf_simple_str_test test/simple_str_test.c)
target_link_libraries(printf_simple_str_test ${PROJECT_BINARY_DIR}/libmu.a)
target_link_libraries(printf_simple_str_test ${PROJECT_BINARY_DIR}/libftprintf.a)

#printf simple num test
add_executable(printf_simple_num_test test/nums_test.c)
target_link_libraries(printf_simple_num_test ${PROJECT_BINARY_DIR}/libmu.a)
target_link_libraries(printf_simple_num_test ${PROJECT_BINARY_DIR}/libftprintf.a)

#printf only procent test
add_executable(just_percent_test test/just_percent_test.c)
target_link_libraries(just_percent_test ${PROJECT_BINARY_DIR}/libmu.a)
target_link_libraries(just_percent_test ${PROJECT_BINARY_DIR}/libftprintf.a)


#add_executable(all_tests test/all_tests.c)
#add_dependencies(all_tests just_percent_test printf_simple_num_test printf_simple_str_test printf_test_test)

# minunit
add_library(mu STATIC test/minunit.c test/capture.c)
