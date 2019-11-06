cmake_minimum_required(VERSION 3.14)
project(printf C)
set(CMAKE_C_STANDARD 11)

#includes
include_directories(general)
include_directories(test)
include_directories(general/libft/includes)

# Usage example of original printf
add_executable(Usage other/main_usage.c)

# Libft with getline
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libft/ft_*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${PROJECT_SOURCE_DIR}/general/libft/get_next_line.c)
add_library(ft STATIC ${LIBFT_FILES})


#printf
set(PRINTF_FILES general/ft_printf.c)
add_library(ftprintf STATIC ${PRINTF_FILES} ${LIBFT_FILES})



#printf general test
add_executable(printf_general_test test/test_general.c)
target_link_libraries(printf_general_test ${PROJECT_BINARY_DIR}/libmu.a)
target_link_libraries(printf_general_test ${PROJECT_BINARY_DIR}/libftprintf.a)

# minunit

add_library(mu STATIC test/minunit.c)
