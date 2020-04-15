cmake_minimum_required(VERSION 3.17)
 
project(Demo)
# 代码路径
aux_source_directory(./array DIR_TOOT_SRCS)
# debug 模式
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
# 生成可执行的文件
add_executable(Demo ${DIR_TOOT_SRCS})