cmake_minimum_required(VERSION 3.17)
project(2gnl C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(gnl)

add_executable(2gnl
		gnl/get_next_line.c
		gnl/get_next_line.h
		libft.h
		main.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -D BUFFER_SIZE=32")