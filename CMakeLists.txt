cmake_minimum_required(VERSION 3.13)
project(Official C)

# ============================== Build Options ============================== #
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ===================== Directories to Include ===================== #
# ----------------- Library ----------------- #
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# ----------------- Exercise ----------------- #
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exercise/include)

# ===================== Setting Paths ===================== #
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/lib/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/lib/archive)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/out)

message("# ============================== PATH ============================== #")
message("src dir:       ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin dir:       ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ")
message("lib dir:       ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("archive dir:   ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} ")
# ===================== Build the Libraries ===================== #
message("# ============================== LIB ============================== #")
# ----------------- Project Std ----------------- #
message("Building Project Standard Libraries")

# ----------------- Exercises ----------------- #
# Temperature
message("Building Exercise Libraries")
set(LIB_TEMPR_SRC Exercise/src/Temperature/celsiusNFahrenheit.c)
add_library(ltempr SHARED ${LIB_TEMPR_SRC})
message("Library Built: ltempr|Temperature")

# ===================== Executables ===================== #
message("# ============================== EXE ============================== #")
message("Building Executables")
# ---------- Main ---------- #
message("Building Main Executables")
add_executable(Main main.c)
message("Executable Built: Main")
target_link_libraries(Main)

# ----------------- Tests ----------------- #
# Temperature Conversion
message("Building Test Executables")
set(TEST_TEMP_SRC Test/Temperature/TempConv.c)
add_executable(T_Temp ${TEST_TEMP_SRC})
message("Executable Built: T_Temp")
target_link_libraries(T_Temp ltempr)
