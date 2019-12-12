cmake_minimum_required(VERSION 3.14)
project(printf C)
set(CMAKE_C_STANDARD 11)


set(CMAKE_CXX_FLAGS "-Wall -Werror")

#includes
include_directories(general)
include_directories(test)
include_directories(general/libft/includes)
include_directories(general/includes)
include_directories(test/libmu)

# Usage example of original printf
add_executable(Usage other/main_usage.c)

# Libft with getline
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libft/ft_*.c")
file(GLOB_RECURSE LIBFT_ADD_FILES "${PROJECT_SOURCE_DIR}/general/libft/ft_*/ft_*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
set(LIBFT_FILES ${LIBFT_FILES} ${PROJECT_SOURCE_DIR}/general/libft/get_next_line.c)
add_library(ft STATIC ${LIBFT_FILES})

#printf
file(GLOB_RECURSE PRINTF_FILES "${PROJECT_SOURCE_DIR}/general/srcs/*.c")
add_library(ftprintf STATIC ${PRINTF_FILES} ${LIBFT_FILES} general/srcs/get_p.c)
add_dependencies(ftprintf ft)

# minunit
add_library(mu STATIC test/libmu/minunit.c test/libmu/capture.c)

function(ADD_EXECUTABLE_MU_TEST EXEC_NAME PATH)
    add_executable(${EXEC_NAME} ${PATH})
    target_link_libraries(${EXEC_NAME} ${PROJECT_BINARY_DIR}/libmu.a)
    target_link_libraries(${EXEC_NAME} ${PROJECT_BINARY_DIR}/libftprintf.a)
    add_dependencies(${EXEC_NAME} mu ft ftprintf)
endfunction(ADD_EXECUTABLE_MU_TEST)

ADD_EXECUTABLE_MU_TEST(printf_general test/basic/test_test.c)
ADD_EXECUTABLE_MU_TEST(printf_simple_str_test test/s_tests/simple_s_test.c)
ADD_EXECUTABLE_MU_TEST(printf_simple_num_test test/basic/nums_test.c)
ADD_EXECUTABLE_MU_TEST(just_percent_test test/basic/percent_test.c)
ADD_EXECUTABLE_MU_TEST(d_simple_test test/d_tests/simple_d_test.c)
ADD_EXECUTABLE_MU_TEST(x_simple_test test/x_tests/simple_x_test.c)
ADD_EXECUTABLE_MU_TEST(u_simple_test test/u_tests/simple_u_test.c)
ADD_EXECUTABLE_MU_TEST(p_simple_test test/p_tests/simple_p_test.c)


