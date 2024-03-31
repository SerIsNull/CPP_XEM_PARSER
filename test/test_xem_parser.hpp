/*!
\file
\brief This header-file describes the declaration some useful data for test.
*/
# pragma once
# include <gtest/gtest.h>
# include <xem_parser.hpp>

namespace test_xem_parser {

	using std::filesystem::remove;

	/// Some input data for possitive tests.
	extern parser::path pth_to_pic_filtered,
	                    pth_to_find_composites,

	/// Some inputs data for negative test.
			    pth_to_empty_pic_filtered,
	       		    pth_to_empty_find_composites,

	/// These empty files will be create with cmake help.
	                    pth_to_not_exist_pic_filtered,
			    pth_to_not_exist_find_composites,

	/// This path to result file of parsing
			    pth_to_result_file;
	
	// This is data of expecpted result
	extern parser::data_type valid_result;

} // end namespace
