cmake_minimum_required(VERSION 3.13)
project(Official C)

# ============================== Build Options ============================== #
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ===================== Directories to Include ===================== #
# ----------------- Library ----------------- #
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/include)
# ----------------- Exercise ----------------- #
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exercise/include)

# ===================== Setting Paths ===================== #
#set(cmake_library_output_directory ${cmake_current_source_dir}/${cmake_build_type}/${cmake_system_name}/lib/shared)
#set(cmake_archive_output_directory ${cmake_current_source_dir}/${cmake_build_type}/${cmake_system_name}/lib/archive)
#set(cmake_runtime_output_directory ${cmake_current_source_dir}/${cmake_build_type}/${cmake_system_name}/out)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/archive)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

message("# ============================== PATH ============================== #")
message("src dir:       ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin dir:       ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ")
message("lib dir:       ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("archive dir:   ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} ")

# ============================== Build the Libraries  ============================== #

message("# ============================== LIB ============================== #")
# ----------------- Project Std ----------------- #
message("Building Project Standard Libraries")

# Utility Libraries
message("Building Utility Library")
add_library(lutil SHARED
            lib/src/Util/integer.c
            lib/src/Util/mathematics.c
            #            lib/src/Algos/linkedList.c

            lib/src/Util/String/string.c
            lib/src/Util/String/snprintf.c
            )
message("Library Built: lutil|Utility")

# Console Buffer Library
message("Building Console Buffer Library")
add_library(lconsoleBuffer SHARED lib/src/Console/Buffer.c lib/include/Console/Buffer.h)
target_link_libraries(lconsoleBuffer lutil)
message("Library Built: lconsoleBuffer|Console Buffer")

# Data Structures
message("Building Data Structure Library")
add_library(ldtstrct SHARED lib/src/DataStruct/node.c)
target_link_libraries(ldtstrct lutil)
message("Library Built: ldtstrct|Data Structure")

# Algorithms
message("Building Algorithms Library")
add_library(lalgo SHARED lib/src/Algos/BinarySearchTree.c)
target_link_libraries(lalgo ldtstrct)
message("Library Built: lalgo|Algorithms")


# ----------------- Exercises ----------------- #
# Temperature
message("Building Exercise Libraries")
add_library(ltempr Exercise/src/Temperature/celsiusNFahrenheit.c)
message("Library Built: ltempr|Temperature")

# ============================== Building Executables ============================== #
message("# ============================== EXE ============================== #")
message("Building Executables")
# ---------- Main ---------- #
message("Building Main Executables")
add_executable(Main main.c)
message("EXEcutable Built: Main")
target_link_libraries(Main)

# ----------------- Utility Tests ----------------- #

# Console Buffer Testing
add_executable(T_ConsoleBuffer Test/Console/CBufferTest.c)
message("EXEcutable Built: T_Consolebuffer")
target_link_libraries(T_ConsoleBuffer lconsoleBuffer)

# String Testing
add_executable(T_String Test/String/StringTest.c)
message("EXEcutable Built: T_String")
target_link_libraries(T_String lutil)

# Integer Testing
add_executable(T_Integer Test/Integer/IntegerTest.c)
message("EXEcutable Built: T_Integer")
target_link_libraries(T_Integer lutil)

# Math Testing
add_executable(T_Math Test/Math/MathTest.c)
message("EXEcutable Built: T_Math")
target_link_libraries(T_Math lutil)

# ----------------- Other Library Tests ----------------- #

# Temperature Conversion
message("Building Test Executables")
add_executable(T_Tempr Test/Temperature/TempConv.c)
message("EXEcutable Built: T_Tempr")
target_link_libraries(T_Tempr ltempr)

# ----------------- Data Structure Tests ----------------- #
# Linked List Testing
#add_executable(T_LinkedList Test/LinkedList/LList.c)
#message("EXEcutable Built: T_LinkedList")
#target_link_libraries(T_LinkedList lutil)

# Node Testing
add_executable(T_Node Test/DataStrctAlgos/NodeTest.c)
message("EXEcutable Built: T_Node")
target_link_libraries(T_Node ldtstrct)

# ----------------- Algorithms Tests ----------------- #

# Binary Search Tree Testing
add_executable(T_BST Test/DataStrctAlgos/BSTTest.c)
message("EXEcutable Built: T_BST")
target_link_libraries(T_BST lalgo)
