# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/administrator/get_tags

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/administrator/get_tags/build

# Utility rule file for create_empty_files.

# Include the progress variables for this target.
include test/CMakeFiles/create_empty_files.dir/progress.make

test/CMakeFiles/create_empty_files:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/administrator/get_tags/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "===> CREATE SOME SOME INPUT FILES AND RESULT FILE FOR TEST!"
	cd /home/administrator/get_tags/build/test && touch /home/administrator/get_tags/build/empty_pic_filtered.XEM /home/administrator/get_tags/build/empty_composites.txt.txt /home/administrator/get_tags/build/f_result.txt

create_empty_files: test/CMakeFiles/create_empty_files
create_empty_files: test/CMakeFiles/create_empty_files.dir/build.make

.PHONY : create_empty_files

# Rule to build all files generated by this target.
test/CMakeFiles/create_empty_files.dir/build: create_empty_files

.PHONY : test/CMakeFiles/create_empty_files.dir/build

test/CMakeFiles/create_empty_files.dir/clean:
	cd /home/administrator/get_tags/build/test && $(CMAKE_COMMAND) -P CMakeFiles/create_empty_files.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/create_empty_files.dir/clean

test/CMakeFiles/create_empty_files.dir/depend:
	cd /home/administrator/get_tags/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/administrator/get_tags /home/administrator/get_tags/test /home/administrator/get_tags/build /home/administrator/get_tags/build/test /home/administrator/get_tags/build/test/CMakeFiles/create_empty_files.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/create_empty_files.dir/depend

