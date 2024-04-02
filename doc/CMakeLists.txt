# This CMakelists.txt will generate documentation in /build/doc

# Try to find the doxygen
find_package( Doxygen )

# Try to find cfg file
file( GLOB CFG_FILE *.conf )

if( DOXYGEN_FOUND AND ( EXISTS ${CFG_FILE} ) )
	message("===> THE DOXYGEN AND CONFIGURATION WERE FOUND THEREFORE THE DECUMENTATION WILL BE GENERATED! USE: \"make generate_doc\" for it!")
	add_custom_target( generate_doc
		           COMMAND ${DOXYGEN_EXECUTABLE} "${CFG_FILE}"
			   WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/doc"
			   COMMENT "===> GENERATE THE DOCUMENTATION!"
			   VERBATIM
		)
else()
	message("===> THE DOXYGEN OR CONFIGURATION WEREN'T FOUND. THE DOCUMENTATION WON'T GENERATE!")
endif()
