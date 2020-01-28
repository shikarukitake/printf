#!/bin/bash

dir="~/ft_printf"
if [ -n "$1" ]
then
    dir=$1
fi

cp -f ./general/srcs/*.c ${dir}"/srcs/"
cp -f ./general/includes/*.h ${dir}"/includes/
cp -f ./general/libftprintf.a  ${dir}/
cp -rf ./general/libft/*     ${dir}/libft/
cp -f ./general/Makefile ${dir}/