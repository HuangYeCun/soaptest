cmake_minimum_required(VERSION 2.8)

project(testserver)

aux_source_directory(soap DIR)

include_directories(soap)
link_directories(${CMAKE_CURRENT_CURRENT_DIR}/)

#set(EXTRA_LIBS ${EXTRA_LIBS} gsoap++)

add_executable(${PROJECT_NAME} "main.cpp" ${DIR})

#target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
