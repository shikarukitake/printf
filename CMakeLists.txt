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
file(GLOB_RECURSE MU_FILES "${PROJECT_SOURCE_DIR}/test/libmu/*.c")
add_library(mu STATIC ${MU_FILES})
target_include_directories(mu PUBLIC BEFORE test/libmu/)

function(ADD_EXECUTABLE_MU_TEST EXEC_NAME PATH)
    add_executable(${EXEC_NAME}.mt ${PATH})
    target_link_libraries(${EXEC_NAME}.mt ${PROJECT_BINARY_DIR}/libmu.a)
    target_link_libraries(${EXEC_NAME}.mt ${PROJECT_BINARY_DIR}/libftprintf.a)
    add_dependencies(${EXEC_NAME}.mt mu ft ftprintf)
endfunction(ADD_EXECUTABLE_MU_TEST)

ADD_EXECUTABLE_MU_TEST(general_test test/basic/basic_test.c)
ADD_EXECUTABLE_MU_TEST(str_test test/s_tests/simple_s_test.c)
ADD_EXECUTABLE_MU_TEST(num_test test/basic/nums_test.c)
ADD_EXECUTABLE_MU_TEST(percent_test test/basic/percent_test.c)
ADD_EXECUTABLE_MU_TEST(d_simple_test test/d_tests/simple_d_test.c)
ADD_EXECUTABLE_MU_TEST(x_simple_test test/x_tests/simple_x_test.c)
ADD_EXECUTABLE_MU_TEST(u_simple_test test/u_tests/simple_u_test.c)
ADD_EXECUTABLE_MU_TEST(p_simple_test test/p_tests/simple_p_test.c)
ADD_EXECUTABLE_MU_TEST(f_simple_test test/f_tests/simple_f_test.c)
ADD_EXECUTABLE_MU_TEST(wrong_test test/wrong/spec_error.c)
ADD_EXECUTABLE_MU_TEST(return_value_test test/basic/return_value.c)
ADD_EXECUTABLE_MU_TEST(wiki_test test/basic/wiki_test.c)
ADD_EXECUTABLE_MU_TEST(utf8_test test/s_tests/utf8_test.c)
ADD_EXECUTABLE_MU_TEST(d_norm_test test/d_tests/norm_d_test.c)
ADD_EXECUTABLE_MU_TEST(x_norm_test test/x_tests/norm_x_test.c)
ADD_EXECUTABLE_MU_TEST(s_norm_test test/s_tests/norm_s_test.c)
ADD_EXECUTABLE_MU_TEST(c_simple_test test/c_tests/simple_c_test.c)
ADD_EXECUTABLE_MU_TEST(o_simple_test test/o_tests/simple_o_test.c)
ADD_EXECUTABLE_MU_TEST(wh_flag_d_test test/d_tests/wh_flag_d_test.c)
ADD_EXECUTABLE_MU_TEST(short_d_test test/d_tests/short_d_test.c)
ADD_EXECUTABLE_MU_TEST(ll_d_test test/d_tests/ll_d_test.c)
ADD_EXECUTABLE_MU_TEST(checker_d_test test/d_tests/checker_d_test.c)
ADD_EXECUTABLE_MU_TEST(i_simple_test test/i_tests/simple_i_test.c)
ADD_EXECUTABLE_MU_TEST(wildcard_test test/bonus/wildcard_test.c)
ADD_EXECUTABLE_MU_TEST(pft_x_test test/x_tests/pft_x_test.c)
ADD_EXECUTABLE_MU_TEST(pft_o_test test/o_tests/pft_o_test.c)
ADD_EXECUTABLE_MU_TEST(norm_f_test test/f_tests/norm_f_test.c)

function(ADD_EXECUTABLE_MAIN_TEST EXEC_NAME PATH)
    add_executable(${EXEC_NAME} ${PATH})
    target_link_libraries(${EXEC_NAME} ${PROJECT_BINARY_DIR}/libmu.a)
    target_link_libraries(${EXEC_NAME} ${PROJECT_BINARY_DIR}/libftprintf.a)
    add_dependencies(${EXEC_NAME} mu ft ftprintf)
endfunction(ADD_EXECUTABLE_MAIN_TEST)


ADD_EXECUTABLE_MAIN_TEST(MAIN_TEST test/general/main_test.c)
ADD_EXECUTABLE_MAIN_TEST(COLOR_TEST test/bonus/color_test.c)

add_executable(ManualTesting test/manual_test/manual_usage.c)
target_link_libraries(ManualTesting ${PROJECT_BINARY_DIR}/libftprintf.a)
add_dependencies(ManualTesting mu ft ftprintf)

add_executable(HexPlay test/x_tests/hex_play.c)
add_executable(HexPlay2 test/x_tests/hex_convert_play.c)


add_executable(BufferTest test/buffer_test/b1_test.c)
target_link_libraries(BufferTest ${PROJECT_BINARY_DIR}/libftprintf.a)
add_dependencies(BufferTest mu ft ftprintf)

# Usage example of floating point numbers
add_executable(Float other/float_usage.c)
target_link_libraries(Float ${PROJECT_BINARY_DIR}/libft.a)
add_dependencies(Float ft)