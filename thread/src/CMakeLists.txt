
project(src)

include_directories(${PROJECT_SOURCE_DIR}/.
  ${PROJECT_SOURCE_DIR}/../../../boost_libs/shared/include/boost-1_67
)

link_directories(${PROJECT_SOURCE_DIR}/../../../boost_libs/static/lib)


#set(SEC_LIST test.cpp)

aux_source_directory(${PROJECT_SOURCE_DIR}/./ DIR_SRCS)

add_executable(main ${DIR_SRCS})

#target_link_libraries(main)
