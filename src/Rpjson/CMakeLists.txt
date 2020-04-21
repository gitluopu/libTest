# CMakeList.txt: LCE 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

#项目模块名,每个工程有自己的名字
set(PROJECT Rpjson)
project(${PROJECT} CXX)

#扫描.当前目录下的所有源文件
aux_source_directory(. DIR_SRCS)
#指定生成目标，生成动态库
add_library (${PROJECT} SHARED ${DIR_SRCS})

IF(WIN32)
	add_definitions(-DLIBTEST_RPJSON_EXPORTS)
ENDIF()

#设置头模块的文件路径,能引用全局定义好的第三方库则直接使用第三方库变量即可
INCLUDE_DIRECTORIES(${RAPIDJSON_INCLUDES})
INCLUDE_DIRECTORIES(${LIBTEST_SRC_INCLUDES})
#设置链接动态库等参数,Debug和Release的链接名称或有不同

#Windows需要指定生成pdb调试文件
IF(WIN32)
	set_target_properties(${PROJECT} PROPERTIES COMPILE_PDB_NAME ${PROJECT})
ENDIF()


#设置编译生成文件名样式

# TODO: 如有需要，请添加测试并安装目标。

#设置链接动态库等参数,Debug和Release的链接名称或有不同

#if(WIN32)
#  target_link_libraries(${PROJECT} ACEd   )
#else()
#target_link_libraries(${PROJECT} ACE  pthread)
#endif()


#Windows需要指定生成pdb调试文件
IF(WIN32)
	set_target_properties(${PROJECT} PROPERTIES COMPILE_PDB_NAME ${PROJECT})
ENDIF()


#设置编译生成文件名样式

# TODO: 如有需要，请添加测试并安装目标。
