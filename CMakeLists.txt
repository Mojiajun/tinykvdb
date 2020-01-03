cmake_minimum_required(VERSION 3.2)

# 整个项目的名称
project(tinykvdb)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# CMAKE_INSTALL_PREFIX 类似./configure --prefix里的prefix
# 在本项目为了测试, 只是安装到了PROJECT_SOURCE_DIR
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(TINYKVDB_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(TINYKVDB_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(TINYKVDB_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# src里面的子模块的头文件搜索路径
# set(TINYKVDB_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)
# message("PROJECT_SOURCE_DIR is : ${PROJECT_SOURCE_DIR}")

# set(TINYKVDB_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)

# include_directories(${TINYKVDB_INSTALL_INCLUDE_DIR})
# include_directories(${TINYKVDB_HEADERS_DIR})

add_subdirectory(src)
add_subdirectory(test)
