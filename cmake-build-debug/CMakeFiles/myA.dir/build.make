# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/anonyman637/IDE/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/anonyman637/IDE/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/anonyman637/CoreProgramming/CProjects/Official

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/anonyman637/CoreProgramming/CProjects/Official/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/myA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myA.dir/flags.make

CMakeFiles/myA.dir/src/a.c.o: CMakeFiles/myA.dir/flags.make
CMakeFiles/myA.dir/src/a.c.o: ../src/a.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/anonyman637/CoreProgramming/CProjects/Official/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myA.dir/src/a.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myA.dir/src/a.c.o   -c /media/anonyman637/CoreProgramming/CProjects/Official/src/a.c

CMakeFiles/myA.dir/src/a.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myA.dir/src/a.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/anonyman637/CoreProgramming/CProjects/Official/src/a.c > CMakeFiles/myA.dir/src/a.c.i

CMakeFiles/myA.dir/src/a.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myA.dir/src/a.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/anonyman637/CoreProgramming/CProjects/Official/src/a.c -o CMakeFiles/myA.dir/src/a.c.s

# Object files for target myA
myA_OBJECTS = \
"CMakeFiles/myA.dir/src/a.c.o"

# External object files for target myA
myA_EXTERNAL_OBJECTS =

../Debug/lib/shared/Linux/libmyA.so: CMakeFiles/myA.dir/src/a.c.o
../Debug/lib/shared/Linux/libmyA.so: CMakeFiles/myA.dir/build.make
../Debug/lib/shared/Linux/libmyA.so: CMakeFiles/myA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/anonyman637/CoreProgramming/CProjects/Official/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library ../Debug/lib/shared/Linux/libmyA.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myA.dir/build: ../Debug/lib/shared/Linux/libmyA.so

.PHONY : CMakeFiles/myA.dir/build

CMakeFiles/myA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myA.dir/clean

CMakeFiles/myA.dir/depend:
	cd /media/anonyman637/CoreProgramming/CProjects/Official/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/anonyman637/CoreProgramming/CProjects/Official /media/anonyman637/CoreProgramming/CProjects/Official /media/anonyman637/CoreProgramming/CProjects/Official/cmake-build-debug /media/anonyman637/CoreProgramming/CProjects/Official/cmake-build-debug /media/anonyman637/CoreProgramming/CProjects/Official/cmake-build-debug/CMakeFiles/myA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myA.dir/depend

