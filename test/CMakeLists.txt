# this CMakeLists.txt for setting common parameters in this project

# set vesrion of cmake
cmake_minimum_required( VERSION 3.16.3 )

# set policy
	cmake_policy( VERSION 3.16.3 )


# set name, version, description and language for programming
	project( xem_parser
	 	VERSION 0.0.3
		DESCRIPTION "This is parser for getting all the necessary composites and tags from the picture of SCADA"
	 	LANGUAGES CXX
	 )

# for build you'll need to have c++20
	set( CMAKE_CXX_STANDARD 20 )

	set( CMAKE_CXX_STANDARD_REQUIRED ON )


# set flags of compiler
	set( CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} -Wall -Wextra)

# set dir for resulting files like /build/bin/
	set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )

# so, in the src/CmakeLists.txt I used some system programm sucha as "grep" and "awk".
# if this OS doesn't have theese programms that building will be failed!
find_program( is_exist_grep    grep    )
find_program( is_exist_awk     awk     )
find_program( is_exist_touch   touch   )

if( NOT (is_exist_grep AND is_exist_awk AND is_exist_touch) )

	message( FATAL_ERROR " ===> NOT FOUND THE PROGRAMMS : " ${is_exist_grep} " , " ${is_exist_awk} ", " ${is_exist_touch} " in the OS! ")

else()
	message( "===> FOUND THE PROGRAMMS : " ${is_exist_grep} " , " ${is_exist_awk} ", " ${is_exist_touch} " in the OS! ")
	
	add_subdirectory( doc )

# add testing in this project. Before building
	enable_testing()

	add_subdirectory( test )

# add srs in this project. If the test PASSED - try to build out xem_paresr
	add_subdirectory( src )

endif()

