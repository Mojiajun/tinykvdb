cmake_minimum_required(VERSION 3.2)

# 整个项目的名称
project(tinykvdb VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# CMAKE_INSTALL_PREFIX 类似./configure --prefix里的prefix
# 在本项目为了测试, 只是安装到了PROJECT_SOURCE_DIR
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(TINYKVDB_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(TINYKVDB_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(TINYKVDB_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# -- PROJECT_SOURCE_DIR is [/tmp/tmp.QCfAIMZXp8]
# -- STATUS  加了有什么用? 就多了一个--
message(STATUS "PROJECT_SOURCE_DIR is " [${PROJECT_SOURCE_DIR}])

#add_custom_command(OUTPUT
#        COMMAND echo "Generating log.txt file..."
#        COMMAND echo "welcome"
#        COMMENT  "This is a test"
#        )
#add_custom_target(T1 ALL DEPENDS ${LOG})

set(EXTERN_INCLUDE_PATH ~/.tinykvdb_deps/include)
set(EXTERN_LIB_PATH ~/.tinykvdb_deps/lib)

include_directories(${EXTERN_INCLUDE_PATH})

# src里面的子模块的头文件搜索路径
# set(TINYKVDB_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)
# message("PROJECT_SOURCE_DIR is : ${PROJECT_SOURCE_DIR}")

# set(TINYKVDB_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)

# include_directories(${TINYKVDB_INSTALL_INCLUDE_DIR})
# include_directories(${TINYKVDB_HEADERS_DIR})

# add external libraries
# 暂时还是一个一个编译吧...
# include(deps/deps.cmake)

add_subdirectory(src)
add_subdirectory(test)
