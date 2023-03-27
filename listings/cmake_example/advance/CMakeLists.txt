cmake_minimum_required(VERSION 3.0)
project(test)

# 自定义 DEBUG 宏
add_definitions(-D DEBUG) # add_definitions(-DDEBUG)也可以

set(CMAKE_CXX_STANDARD 11) # 设置C++版本

# 定义变量
# 根节点 CMakeLists.txt 中的变量全局有效
# 静态库生成的路径
set(LIB_PATH ${CMAKE_BINARY_DIR}/lib) # CMAKE_BINARY_DIR表示项目实际构建的目录 即build文件夹
# 测试程序生成的路径
set(EXEC_PATH ${CMAKE_BINARY_DIR}/bin)

# 头文件目录
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
# 静态库的名字
set(CALC_LIB calc)
set(SORT_LIB sort)
# 可执行程序的名字
set(APP_NAME_1 test1)
set(APP_NAME_2 test2)
# 添加子目录
add_subdirectory(calc) # 嵌套的 CMake 也是一个树状结构，最顶层的 CMakeLists.txt 是根节点，其次都是子节点 	
add_subdirectory(sort)
add_subdirectory(test1)
add_subdirectory(test2)
