# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hdb/proj/DEEP-GSTREAMER/glib_sample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hdb/proj/DEEP-GSTREAMER/glib_sample/build_debug

# Include any dependencies generated for this target.
include CMakeFiles/glib_key_value.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glib_key_value.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glib_key_value.dir/flags.make

CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o: CMakeFiles/glib_key_value.dir/flags.make
CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o: ../src/glib_key_value/glib_key_value.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hdb/proj/DEEP-GSTREAMER/glib_sample/build_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o   -c /home/hdb/proj/DEEP-GSTREAMER/glib_sample/src/glib_key_value/glib_key_value.c

CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hdb/proj/DEEP-GSTREAMER/glib_sample/src/glib_key_value/glib_key_value.c > CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.i

CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hdb/proj/DEEP-GSTREAMER/glib_sample/src/glib_key_value/glib_key_value.c -o CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.s

CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.requires:

.PHONY : CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.requires

CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.provides: CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.requires
	$(MAKE) -f CMakeFiles/glib_key_value.dir/build.make CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.provides.build
.PHONY : CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.provides

CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.provides.build: CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o


# Object files for target glib_key_value
glib_key_value_OBJECTS = \
"CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o"

# External object files for target glib_key_value
glib_key_value_EXTERNAL_OBJECTS =

bin/glib_key_value: CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o
bin/glib_key_value: CMakeFiles/glib_key_value.dir/build.make
bin/glib_key_value: CMakeFiles/glib_key_value.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hdb/proj/DEEP-GSTREAMER/glib_sample/build_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/glib_key_value"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glib_key_value.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glib_key_value.dir/build: bin/glib_key_value

.PHONY : CMakeFiles/glib_key_value.dir/build

CMakeFiles/glib_key_value.dir/requires: CMakeFiles/glib_key_value.dir/src/glib_key_value/glib_key_value.c.o.requires

.PHONY : CMakeFiles/glib_key_value.dir/requires

CMakeFiles/glib_key_value.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glib_key_value.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glib_key_value.dir/clean

CMakeFiles/glib_key_value.dir/depend:
	cd /home/hdb/proj/DEEP-GSTREAMER/glib_sample/build_debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hdb/proj/DEEP-GSTREAMER/glib_sample /home/hdb/proj/DEEP-GSTREAMER/glib_sample /home/hdb/proj/DEEP-GSTREAMER/glib_sample/build_debug /home/hdb/proj/DEEP-GSTREAMER/glib_sample/build_debug /home/hdb/proj/DEEP-GSTREAMER/glib_sample/build_debug/CMakeFiles/glib_key_value.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glib_key_value.dir/depend

