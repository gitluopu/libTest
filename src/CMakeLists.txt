# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#

#工程名定义
project ("LIBTEST")

#CMake版本约束声明
if(WIN32)
	cmake_minimum_required(VERSION 3.7)
else()
	cmake_minimum_required(VERSION 2.8)
endif()

#设置默认编译版本，Debug或者Release
IF(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE INTERNAL "默认选择Debug")
ENDIF()

#设置不同版本的编译参数
if(WIN32)
#Windows下不同版本编译参数调优
IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /Od /bigobj" CACHE INTERNAL "Windows调试版本参数")
	if("${MSVC_RUNTIME_LIBRARY_CONFIG}" STREQUAL "")
		set(MSVC_RUNTIME_LIBRARY_CONFIG "/MDd" CACHE INTERNAL "Windows运行库")
	endif()
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /O2 /bigobj" CACHE INTERNAL "Windows发行版本优化参数")

	if("${MSVC_RUNTIME_LIBRARY_CONFIG}" STREQUAL "")
		set(MSVC_RUNTIME_LIBRARY_CONFIG "/MTd" CACHE INTERNAL "Windows运行库")
	endif()
ENDIF()

  foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
    if("${MSVC_RUNTIME_LIBRARY_CONFIG}" STREQUAL "/MTd")
      string(REPLACE "/MDd" "/MTd" ${flag_var} "${${flag_var}}")
    elseif("${MSVC_RUNTIME_LIBRARY_CONFIG}" STREQUAL "/MD")
      string(REPLACE "/MTd" "/MDd" ${flag_var} "${${flag_var}}")
    else()
      string(REPLACE "/MDd" "${MSVC_RUNTIME_LIBRARY_CONFIG}" ${flag_var} "${${flag_var}}")
      string(REPLACE "/MTd" "${MSVC_RUNTIME_LIBRARY_CONFIG}" ${flag_var} "${${flag_var}}")
    endif()
  endforeach()

  add_definitions(-D_WIN64)
  add_definitions(-DWIN32)
  add_definitions(-D_WINDOWS)
else()
#Linux下不同版本编译参数调优
  IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -g")
  else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wall -Wextra -g -O3")
  ENDIF()
endif(WIN32)

#设置开启C++11支持
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#设置全局的头文件路径变量，以便在子项目中使用
set(LIBTEST_SRC_INCLUDES ${PROJECT_SOURCE_DIR}  CACHE INTERNAL "LCE的src路径")
set(ACE_INCLUDES ${PROJECT_SOURCE_DIR}/../thirdparty/ACE_wrappers  CACHE INTERNAL "ACE_wrappers的头文件路径")
set(RAPIDJSON_INCLUDES ${PROJECT_SOURCE_DIR}/../thirdparty/rapidjson/include  CACHE INTERNAL "rapidjson的头文件路径")


#设置全局的可执行文件和动态库编译输出路径
if(WIN32)
if(NOT ARCHIVE_OUTPUT_PATH)
	set(ARCHIVE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/win CACHE INTERNAL "存档文件路径")
endif()
if(NOT EXECUTABLE_OUTPUT_PATH)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/win CACHE INTERNAL "可执行程序生成路径")
endif()
if(NOT LIBRARY_OUTPUT_PATH)
	set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/win CACHE INTERNAL "动态库生成路径")
endif()
IF(NOT COMPILE_PDB_OUTPUT_DIRECTORY)
	set(COMPILE_PDB_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin/win CACHE INTERNAL "Windows PDB生成路径")
ENDIF()
#unix
else()
if(NOT ARCHIVE_OUTPUT_PATH)
	set(ARCHIVE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/unix CACHE INTERNAL "存档文件路径")
endif()
if(NOT EXECUTABLE_OUTPUT_PATH)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/unix CACHE INTERNAL "可执行程序生成路径")
endif()
if(NOT LIBRARY_OUTPUT_PATH)
	set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/unix CACHE INTERNAL "动态库生成路径")
endif()
IF(NOT COMPILE_PDB_OUTPUT_DIRECTORY)
	set(COMPILE_PDB_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin/unix CACHE INTERNAL "Windows PDB生成路径")
ENDIF()
endif()



#声明全局的动态库链接路径
IF(WIN32)
	SET(LINK_PATH ${PROJECT_SOURCE_DIR}/../bin/win)
else()
	SET(LINK_PATH ${PROJECT_SOURCE_DIR}/../bin/unix)
ENDIF()
LINK_DIRECTORIES(${LINK_PATH} )

# 包含子项目。
add_subdirectory ("Main")
add_subdirectory ("Common")
add_subdirectory ("AceWrap")
add_subdirectory ("Rpjson")
