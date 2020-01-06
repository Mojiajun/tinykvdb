cmake_minimum_required(VERSION 3.2)
project(tinykvdb_tests)

# 添加googletest的位置 不需要了吧
# add_subdirectory(../deps/googletest)

# 要测试的文件的头文件的位置
include_directories(${TINYKVDB_INSTALL_INCLUDE_DIR})
include_directories(${EXTERN_INCLUDE_PATH})

find_library (
        GTEST_LIB
        NAMES gtest libgtest libgtest_main # what to look for
        HINTS "${EXTERN_LIB_PATH}" # where to look
        NO_DEFAULT_PATH # do not search system default paths
)

# check if we found the library
message(STATUS "GTEST_LIB: [${GTEST_LIB}]")

if (NOT GTEST_LIB)
    message(SEND_ERROR "Did not find libgtest")
endif()


set(DIVIDER_TEST_SOURCE_FILES main.cpp divider_tests.cpp)
set(DB_TEST_SOURCE_FILES main.cpp db_test.cpp ../src/db.cpp)


find_library (
        GLOG_LIB
        NAMES glog libglog # what to look for
        HINTS "${EXTERN_LIB_PATH}" # where to look
        NO_DEFAULT_PATH # do not search system default paths
)

# check if we found the library
message(STATUS "GLOG_LIB: [${GLOG_LIB}]")

if (NOT GLOG_LIB)
    message(SEND_ERROR "Did not find libglog")
endif()

add_executable(divider_tests ${DIVIDER_TEST_SOURCE_FILES})
add_executable(db_tests ${DB_TEST_SOURCE_FILES})

target_link_libraries(divider_tests
        division  # 这种情况会因为在src/CMakeLists.txt里有add_subdirectory(division), 所以能链接上
        # 但是这一步还没安装啊?whyTODO
        ${GTEST_LIB})

target_link_libraries(db_tests
        ${GLOG_LIB}
        ${GTEST_LIB})

install(TARGETS divider_tests DESTINATION bin)
install(TARGETS db_tests DESTINATION bin)
