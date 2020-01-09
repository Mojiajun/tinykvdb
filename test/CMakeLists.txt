cmake_minimum_required(VERSION 3.2)
project(tinykvdb_tests)

# 添加googletest的位置 不需要了吧
# add_subdirectory(../deps/googletest)

# 要测试的文件的头文件的位置
include_directories(${TINYKVDB_INSTALL_INCLUDE_DIR})
include_directories(${EXTERN_INCLUDE_PATH})

# 找gtest
find_library(
        GTEST_LIB
        NAMES gtest libgtest libgtest_main # what to look for
        HINTS "${EXTERN_LIB_PATH}" # where to look
        NO_DEFAULT_PATH # do not search system default paths
)

# check if we found the library
message(STATUS "GTEST_LIB: [${GTEST_LIB}]")

if (NOT GTEST_LIB)
    message(SEND_ERROR "Did not find libgtest")
endif ()

# 找glog
find_library(
        GLOG_LIB
        NAMES glog libglog # what to look for
        HINTS "${EXTERN_LIB_PATH}" # where to look
        NO_DEFAULT_PATH # do not search system default paths
)

# check if we found the library
message(STATUS "GLOG_LIB: [${GLOG_LIB}]")

if (NOT GLOG_LIB)
    message(SEND_ERROR "Did not find libglog")
endif ()

# 第1处添加位置
set(ENV_TEST_SOURCE_FILES main.cpp env_test.cpp)
set(DB_TEST_SOURCE_FILES main.cpp db_test.cpp)
set(FILE_TEST_SOURCE_FILES main.cpp file_test.cpp)
set(CODING_TEST_SOURCE_FILES main.cpp coding_test.cpp)

# 第2处添加位置
add_executable(env_test ${ENV_TEST_SOURCE_FILES})
add_executable(db_test ${DB_TEST_SOURCE_FILES})
add_executable(file_test ${FILE_TEST_SOURCE_FILES})
add_executable(coding_test ${CODING_TEST_SOURCE_FILES})

set(TEST_SRC_LINK
        tinykvdb
        pthread  # 在Linux上得这样, 不知道是不是gtest.a是静态库的问题,然后又因为它依赖于pthread的问题
        ${GLOG_LIB}
        ${GTEST_LIB}
        )

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Darwin")
else ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif (CMAKE_SYSTEM_NAME MATCHES "Linux")

# 第3处添加位置
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "linking in ${CMAKE_SYSTEM_NAME} platform")
    target_link_libraries(env_test
            -Wl,--start-group
            ${TEST_SRC_LINK}
            -Wl,--end-group)

    target_link_libraries(db_test
            -Wl,--start-group
            ${TEST_SRC_LINK}
            -Wl,--end-group)

    target_link_libraries(file_test
            -Wl,--start-group
            ${TEST_SRC_LINK}
            -Wl,--end-group)

    target_link_libraries(coding_test
            -Wl,--start-group
            ${TEST_SRC_LINK}
            -Wl,--end-group)
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
        MESSAGE(STATUS "linking in ${CMAKE_SYSTEM_NAME} platform")
        target_link_libraries(env_test
                ${TEST_SRC_LINK})
        target_link_libraries(db_test
                ${TEST_SRC_LINK})
        target_link_libraries(file_test
                ${TEST_SRC_LINK})
        target_link_libraries(coding_test
                ${TEST_SRC_LINK})
endif(CMAKE_SYSTEM_NAME MATCHES "Linux")

# 第4处添加位置
set(TEST_INSTALL_BIN
        db_test
        env_test
        file_test
        coding_test)

install(TARGETS ${TEST_INSTALL_BIN} DESTINATION bin)
