cmake_minimum_required(VERSION 3.13)
project(Official C)

# ============================== Build Options ============================== #
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ===================== Directories to Include ===================== #
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# ===================== Setting Paths ===================== #
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/lib/shared/${CMAKE_SYSTEM_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/lib/archive/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/out/${CMAKE_SYSTEM_NAME})

message("src dir: ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin dir: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ")
message("lib dir: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("archive dir: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} ")

# ===================== Build the Libraries ===================== #

# ===================== Executables ===================== #
# ---------- Main ---------- #
add_executable(Main main.c)
target_link_libraries(Main)


