cmake_minimum_required(VERSION 2.8)

project(ds)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include/ds)

aux_source_directory(src/ds SRC_FILES) 

add_executable(test_list test/test_list.c ${SRC_FILES})
add_executable(test_bitree test/test_bitree.c ${SRC_FILES})
add_executable(test_clist test/test_clist.c ${SRC_FILES})
add_executable(test_dlist test/test_dlist.c ${SRC_FILES})
add_executable(test_heap test/test_heap.c ${SRC_FILES})
add_executable(test_queue test/test_queue.c ${SRC_FILES})
add_executable(test_set test/test_set.c ${SRC_FILES})
add_executable(test_stack test/test_stack.c ${SRC_FILES})

