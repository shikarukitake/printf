#!/bin/bash

dir="~/ft_printf/"
if [ -n "$1" ]
then    
    dir=$1
fi

SRC="${dir}srcs/" 
echo ${SRC}
echo 'DEBUG'
cp general/srcs/*.c ${SRC}
cp general/includes/*.h ${dir}/includes/
cp -r general/libft ${dir}/libft
cp general/Makefile ${dir}/

