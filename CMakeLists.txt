cmake_minimum_required(VERSION 3.12)
project(chat_room)

#执行框架的cmake
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/JKYi)

include(JKYi/cmake/utils.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined")

#添加头文件的查找
include_directories(.)
include_directories(/usr/local/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/JKYi)

link_directories(/usr/local/lib)

#加载下载的一些的一下开源库
find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

find_package(OpenSSL REQUIRED)
if(OPNESSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

set (LIB_SRC
      chat/my_module.cc
      chat/resource_servlet.cc
      chat/protocol.cc
      chat/chat_servlet.cc
    )

add_library(chat_room SHARED ${LIB_SRC})
force_redefine_file_macro_for_sources(chat_room)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


