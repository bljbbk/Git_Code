
project(src)

include_directories(
	${PROJECT_SOURCE_DIR}/.
	${PROJECT_SOURCE_DIR}/../../../build_libs/boost/include/
	${PROJECT_SOURCE_DIR}/../../../build_libs/log4cpp/include/
)

link_directories(
	${PROJECT_SOURCE_DIR}/../../../build_libs/boost/static/lib
	${PROJECT_SOURCE_DIR}/../../../build_libs/log4cpp/lib
)


#set(SEC_LIST test.cpp)

aux_source_directory(${PROJECT_SOURCE_DIR}/./ DIR_SRCS)

add_executable(test ${DIR_SRCS})

#target_link_libraries(test)
