cmake_minimum_required(VERSION 2.8)

project(ds)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include/ds)
include_directories(include/sort)

aux_source_directory(src/ds DS_SRC_FILES) 
aux_source_directory(src/sort SORT_SRC_FILES) 

add_executable(test_list test/test_list.c ${DS_SRC_FILES})
add_executable(test_bitree test/test_bitree.c ${DS_SRC_FILES})
add_executable(test_clist test/test_clist.c ${DS_SRC_FILES})
add_executable(test_dlist test/test_dlist.c ${DS_SRC_FILES})
add_executable(test_heap test/test_heap.c ${DS_SRC_FILES})
add_executable(test_queue test/test_queue.c ${DS_SRC_FILES})
add_executable(test_set test/test_set.c ${DS_SRC_FILES})
add_executable(test_stack test/test_stack.c ${DS_SRC_FILES})

add_executable(test_sort test/test_sort.c ${SORT_SRC_FILES})

