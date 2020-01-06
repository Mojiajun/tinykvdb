cmake_minimum_required(VERSION 3.2)
project(tinykvdb_server)

# 自己会去编译
add_subdirectory(division)
set(SOURCE_FILES db.cpp)

message(${EXTERN_INCLUDE_PATH})
include_directories(${EXTERN_INCLUDE_PATH})
# link_directories(${EXTERN_LIB_PATH})

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

#add_executable(tinykvdb_server ${SOURCE_FILES})

#target_link_libraries(tinykvdb_server
#        ${GLOG_LIB})

#install(TARGETS tinykvdb_server DESTINATION ${TINYKVDB_INSTALL_BIN_DIR})
