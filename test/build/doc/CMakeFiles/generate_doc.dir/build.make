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

# Utility rule file for generate_doc.

# Include the progress variables for this target.
include doc/CMakeFiles/generate_doc.dir/progress.make

doc/CMakeFiles/generate_doc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/administrator/get_tags/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "===> GENERATE THE DOCUMENTATION!"
	cd /home/administrator/get_tags/build/doc && /usr/bin/doxygen /home/administrator/get_tags/doc/doxygen.conf

generate_doc: doc/CMakeFiles/generate_doc
generate_doc: doc/CMakeFiles/generate_doc.dir/build.make

.PHONY : generate_doc

# Rule to build all files generated by this target.
doc/CMakeFiles/generate_doc.dir/build: generate_doc

.PHONY : doc/CMakeFiles/generate_doc.dir/build

doc/CMakeFiles/generate_doc.dir/clean:
	cd /home/administrator/get_tags/build/doc && $(CMAKE_COMMAND) -P CMakeFiles/generate_doc.dir/cmake_clean.cmake
.PHONY : doc/CMakeFiles/generate_doc.dir/clean

doc/CMakeFiles/generate_doc.dir/depend:
	cd /home/administrator/get_tags/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/administrator/get_tags /home/administrator/get_tags/doc /home/administrator/get_tags/build /home/administrator/get_tags/build/doc /home/administrator/get_tags/build/doc/CMakeFiles/generate_doc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/CMakeFiles/generate_doc.dir/depend
