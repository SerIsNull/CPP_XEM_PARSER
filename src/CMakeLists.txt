# This CMakeLists.txt exists the main target's building.
# Also, this file is preparing input arguments for running.
# After the building this CMakeLists.txt will run the target with necessary arguments.
# This is just for test running.

# set src files for compile
	set( SOURCES 
		xem_parser.cpp
		client.cpp
   	)

# set src files for compile
	set( HEADERS 
		xem_parser.hpp
   	)

# try to find name's input file 1 ( arg #1 for target )
	file( GLOB PIC
		${CMAKE_SOURCE_DIR}/*.XEM
    	)


# try to find name's input file 2 ( arg #2 for target )
	file( GLOB COMP
		${CMAKE_SOURCE_DIR}/*txt.txt
	)

# this is a main target.
add_executable( xem_parser ${SOURCES} ${HEADERS} )

# add derectory for includes
	target_include_directories( xem_parser PRIVATE
			    ${CMAKE_CURRENT_SOURCE_DIR}
	)


# Build the xem_pareser and test running
if ( (EXISTS ${COMP} ) AND ( EXISTS ${PIC} ) )

	message( "===> ALL THE NECASSARY INPUT FILES FOR RUNNING XEM_PARSER WAS FOUND!")

	# in this section I'm trying to filter arg # 1. I'm doing it because the original arg #1 contains about 8000 lines. It's too large.
	set( REGEXP 
		"\\n\\s*<Property Name=\"CompositeName\" Value=\"(.*)\" />\\n.*<Property Name=\"InstanceName\" Value=\"(.*)\" />"
	)

	# for filtering I'm using two programms such as gpep and awk.
	# the result will be generate into PIC_FILTERED.XEM. This is a new arg #1 for target.
	add_custom_command( 
			    OUTPUT PIC_FILTERED.XEM
			    COMMAND grep -Pzo  ${REGEXP} ${PIC} | awk "NF" > PIC_FILTERED.XEM
		    	    WORKING_DIRECTORY  ${CMAKE_BINARY_DIR}
			    COMMENT "==> CREATING NEW PIC_FILTERED.XEM ( NEW ARG #1)"
		    	    VERBATIM
	)

	# I adding new target. It depends on generated arg #1.
	add_custom_target( 
			    create_pic_filtered
		   	    DEPENDS PIC_FILTERED.XEM 
	)

	# I need to create necessaty input files before running 
	add_dependencies( xem_parser create_pic_filtered )

	# this section for test running like ./target arg#1 arg#2
	add_custom_command( 
			    TARGET xem_parser POST_BUILD
			    COMMAND xem_parser "${CMAKE_BINARY_DIR}/PIC_FILTERED.XEM" "${COMP}"
			    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
			    COMMENT "===> TEST RUNNING ./xem_parser ${CMAKE_BINARY_DIR}/PIC_FILTERED.XEM ${COMP}"
			    VERBATIM
	)

# Build xem_pareser without test running.
else()
	message( WARNING "===> INPUT FILES FOR RUNNING WASN'T FOUND. IT'LL JUST BUILD! YOU'LL NEED TO RUN IT MANUALY!")

endif()



