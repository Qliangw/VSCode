cmake_minimum_required(VERSION 3.17)
 
project(Demo)
# 代码路径
aux_source_directory(. DIR_TOOT_SRCS)
# 添加子目录
add_subdirectory(myString)
add_subdirectory(array)
add_subdirectory(sort)
# debug 模式
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


include_directories( 
    ${PROJECT_SOURCE_DIR}/myString
    ${PROJECT_SOURCE_DIR}/array
    ${PROJECT_SOURCE_DIR}/sort
)

# 生成可执行的文件
add_executable(Demo ${DIR_TOOT_SRCS})
# 添加链接库
target_link_libraries(Demo myString)
target_link_libraries(Demo array)
target_link_libraries(Demo sort)

# 需要链接额外的动态库时：
# target_link_libraries(${PROJECT_NAME}
# /usr/lib/i386-linux-gnu/libboost_system.so