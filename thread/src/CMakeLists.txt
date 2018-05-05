
project(src)

include_directories(${PROJECT_SOURCE_DIR}/.
  ${PROJECT_SOURCE_DIR}/../../../build_libs/boost/include/
)

link_directories(${PROJECT_SOURCE_DIR}/../../../build_libs/boost/static/lib)


#set(SEC_LIST test.cpp)

aux_source_directory(${PROJECT_SOURCE_DIR}/./ DIR_SRCS)

add_executable(main ${DIR_SRCS})

#target_link_libraries(main)
