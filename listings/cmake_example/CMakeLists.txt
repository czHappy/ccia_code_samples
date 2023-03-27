# version1
# cmake_minimum_required(VERSION 3.0)
# project(CALC)
# add_executable(app add.c div.c main.c mult.c sub.c)


# version2 多文件夹常规版本
# cmake_minimum_required(VERSION 3.0)
# project(CALC) #设置工程名称
# set(CMAKE_CXX_STANDARD 11) # 设置C++版本
# set(HOME .) #设定HOME变量为当前目录下 
# set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin/) #设置可执行文件输出路径
# include_directories(${PROJECT_SOURCE_DIR}/include) #设置include头文件目录
# file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c) # 取出所有c文件名称到SRC_LIST变量 GLOB_RECURSE递归搜索
# # aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST) # 搜索 src 目录下的源文件，可替代上面写法

# # MESSAGE( STATUS "CMAKE_CXX_STANDARD = ${CMAKE_CXX_STANDARD}.")
# # MESSAGE( STATUS "EXECUTABLE_OUTPUT_PATH = ${EXECUTABLE_OUTPUT_PATH}.")
# # MESSAGE( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}.")
# # MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}.")
# # MESSAGE( STATUS "SRC_LIST = ${SRC_LIST}.")
# # MESSAGE( STATUS "HOME = ${SRC_LIST}.")

# add_executable(app  ${SRC_LIST}) # 由源文件输出可执行文件 名称为app





# 生成库文件 并链接
cmake_minimum_required(VERSION 3.0)
project(CALC) #设置工程名称

# 自定义 DEBUG 宏
add_definitions(-D DEBUG) # add_definitions(-DDEBUG)也可以

set(CMAKE_CXX_STANDARD 11) # 设置C++版本
set(HOME ${CMAKE_BINARY_DIR}) #设定HOME变量为build当前目录下 
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin/) #设置可执行文件输出路径

include_directories(${PROJECT_SOURCE_DIR}/include) #设置include头文件目录

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c) # 取出所有c文件名称到SRC_LIST变量 GLOB_RECURSE递归搜索
# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST) # 搜索 src 目录下的源文件，可替代上面写法

# 设置动态库/静态库生成路径
# set(LIBRARY_OUTPUT_PATH ${HOME}/lib)
# # # 生成动态库
# add_library(calc SHARED ${SRC_LIST})
# 生成静态库
# add_library(calc STATIC ${SRC_LIST})

# 指定要链接的动态库的路径
link_directories(${HOME}/lib) #这里不加这句话其实也能找到 之前calc名字已经定义了，后续target_link_libraries能找到;如果之前没有生成动态库语句就要加
message(status "lib_path=${HOME}/lib")
# add_executable(app  ${SRC_LIST}) # 由源文件输出可执行文件 名称为app
add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/main.c) # 由源文件输出可执行文件 名称为app

target_link_libraries(app calc)