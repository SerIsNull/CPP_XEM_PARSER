# this CMakeLists.txt for testing xem_parser.

# set name, version, description and language for programming
	project( tester
	 	 VERSION 0.0.3
		 DESCRIPTION "This is test for testing xem_parser"
	 	 LANGUAGES CXX
	)

# set source files
	set( SOURCES
		xem_parser.cpp
		test_xem_parser.cpp
	)

# set header files
	set( HEADERS 
		xem_pareser.hpp	
		test_xem_parser.hpp
	)

# get the names of input files. It's about /test/valid_pic_filtered.XEM with data for parsing and /test/valid_composites.txt.txt.
# Actually, it's about the result file.txt
	file( GLOB VALID_PIC  valid*.XEM            )
	file( GLOB VALID_COMP valid*.txt.txt        )
	set ( F_RESULT ${CMAKE_BINARY_DIR}/f_result.txt)

# For testing we need one more input files. It untill doesn't exist. For generate it we need to get their names.
	STRING( REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/valid" "${CMAKE_BINARY_DIR}/empty" EMPTY_PIC  ${VALID_PIC}  )
	STRING( REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/valid" "${CMAKE_BINARY_DIR}/empty" EMPTY_COMP ${VALID_COMP} )


# We try ti create all the necessary files
	add_custom_target( creating_some_files_for_test 
			   COMMAND touch "${EMPTY_PIC}" "${EMPTY_COMP}" "${F_RESULT}"
			   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
			   COMMENT "===> CREATING SOME INPUT FILES FOR RUNNING THE TEST!"
			   VERBATIM
	)

file( GLOB EMPTY_PIC  ${CMAKE_BINARY_DIR}/empty*.XEM       )
file( GLOB EMPTY_COMP ${CMAKE_BINARY_DIR}/empty*.txt.txt   )
#file( GLOB F_RESULT   f_res*.txt       )

message( "EMPTIES == " ${EMPTY_PIC} " and " ${EMPTY_COMP} " and " ${F_RESULT} )

message( "VALID == " ${VALID_PIC} " and " ${VALID_COMP} )
# build the test  
add_executable ( test_xem_parser ${CMAKE_SOURCE_DIR}/src/${SOURCES} )

# we need to create all the necessary files for testing before building and running the test.
	add_dependencies( test_xem_parser creating_some_files_for_test )

# add paths for # include
	target_include_directories( test_xem_parser PRIVATE "${CMAKE_SOURCE_DIR}/src" "${CMAKE_CURRENT_SOURCE_DIR}")

# set output path for test
	set_target_properties( test_xem_parser PROPERTIES
			       RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	)


# add option -pthread for linker
	target_link_options ( test_xem_parser PRIVATE
	              	      -pthread 
	)

# link it with gtest library
	target_link_libraries( test_xem_parser
		               gtest
	)

# add the tests_xem_parser into the ctest programm
	add_test  ( NAME tests_xem_parser
	    	    COMMAND ${CMAKE_BINARY_DIR}/bin/test_xem_parser "${VALID_PIC}" "${VALID_COMP}" "${EMPTY_PIC}" "${EMPTY_COMP}" "./NOT_EXISTS_PIC.XEM" "./NOT_EXISTS_COMP.txt.txt" "${F_RESULT}" 
        )

# Run the test before building the xem_parser. If this test will be fails - the building won't be started!
	add_custom_command( TARGET test_xem_parser
	            	    POST_BUILD
	    	    	    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure 
		    	    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		    	    COMMENT "===> RUN THE TEST BEFORE BUILDING XEM_PARSER!"
		    	    VERBATIM
)

