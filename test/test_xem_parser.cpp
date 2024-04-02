/*!
\file
\brief This file desribes all the tests in this project.
*/

# include <test_xem_parser.hpp>
# include <xem_parser.hpp>

/// This is data's definitions for testing.

/// They will be redefine into the /test/CMakeLists.txt.
parser::path      test_xem_parser::pth_to_pic_filtered;
parser::path      test_xem_parser::pth_to_find_composites;

parser::path      test_xem_parser::pth_to_empty_pic_filtered;
parser::path      test_xem_parser::pth_to_empty_find_composites;

parser::path      test_xem_parser::pth_to_not_exist_pic_filtered;
parser::path      test_xem_parser::pth_to_not_exist_find_composites;

parser::path      test_xem_parser::pth_to_result_file;

/// Expected result! 
parser::data_type test_xem_parser::valid_result{ " Composite name = CPC_COMPOSITE_1_FOUND",
						 "1) cmp1_tag_1",
						 "2) cmp1_tag_2",
						 "3) cmp1_tag_3",
						 "4) cmp1_tag_4",
						 " Composite name = CPC_COMPOSITE_2_FOUND",
						 "1) cmp2_tag_1",
						 "2) cmp2_tag_2",
						 "3) cmp2_tag_3",
						 "4) cmp2_tag_4",
						 "5) cmp2_tag_5",
						 "6) cmp2_tag_6",
						 "7) cmp2_tag_7",
						 "8) cmp2_tag_8"
};

/*!
 * \brief Possitive test parser::prepare_data()
The function parser::prepare_data() should return 14 strings ( from ../test/valid_pic_filtered.XEM) and 5 strings ( from ../test/valid_composites.txt.txt )
*/

TEST( F_PREPARE_DATA, PASS_PIC_FILTERED_AND_LIST_COMPOSITES_RETURN_PAIR_14STR_5STR ) {

	std::pair< parser::data_type, parser::data_type> pic_composites;

	parser::prepare_data( test_xem_parser::pth_to_pic_filtered,
			      test_xem_parser::pth_to_find_composites,
			      pic_composites
			    );
	
	for( auto const & data : pic_composites.first) {
	
		std::cout << ":" << data << '\n';
	}

	ASSERT_TRUE( pic_composites.first.size() == 14 and pic_composites.second.size() == 5 );
}

/*!
 * \brief Negative test parser::prepare_data().
If we passed paths to the empty input files we'll get exception std::filesystem::filesystem_error().
*/
TEST( F_PREPARE_DATA, PASS_EMPTY_PIC_FILTERED_AND_EMPTY_LIST_COMPOSITES_RETURN_EXCEPT ) {

	std::pair< parser::data_type, parser::data_type> pic_composites;

	ASSERT_THROW( parser::prepare_data( test_xem_parser::pth_to_empty_pic_filtered,
			      		    test_xem_parser::pth_to_empty_find_composites,
			                    pic_composites),
		      parser::filesystem_error
		     
		    );

	// after the test we need to remove these files.
	test_xem_parser::remove( test_xem_parser::pth_to_empty_pic_filtered );
	test_xem_parser::remove( test_xem_parser::pth_to_empty_pic_filtered );
}

/*!
 * \brief Negative test parser::prepare_data().
If we passed paths to the not exist input files we'll get exception std::filesystem::filesystem_error().
*/
TEST( F_PREPARE_DATA, PASS_NOT_EXIST_PIC_FILTERED_AND_NOT_EXIST_LIST_COMPOSITES_RETURN_EXCEPT ) {

	std::pair< parser::data_type, parser::data_type> pic_composites;

	ASSERT_THROW( parser::prepare_data( test_xem_parser::pth_to_not_exist_pic_filtered,
			      		    test_xem_parser::pth_to_not_exist_find_composites,
			                    pic_composites),
		      parser::filesystem_error
		     
		    );
}

/*!
 * \brief Possitive test parser::parser()
The function parser::parser() should be equal by the size and values to the test_xem_valid_result.
*/
TEST( F_PARSE, PASS_PAIR_PIC_COMPOSITES_RETURN_FILE_WITH_16_VALID_STR ) {

	std::pair< parser::data_type, parser::data_type> pic_composites;

	parser::prepare_data( test_xem_parser::pth_to_pic_filtered,
			      test_xem_parser::pth_to_find_composites,
			      pic_composites
			    );
	
	std::basic_fstream< parser::char_type > f_result( test_xem_parser::pth_to_result_file,
			                                  std::ios_base::out
							);

	parser::parser( pic_composites,
			f_result 
		      );

	std::basic_string< parser::char_type > str_buff;
	parser::data_type result;

	// reopen file to unset getting possition after writing
	f_result.close();
	f_result.open( test_xem_parser::pth_to_result_file );

	while( !f_result.eof() ) { 
		std::getline( f_result, str_buff );

		if( !str_buff.empty() )
			result.emplace_back(str_buff);
	}

	// Remove the result file from /build/.. I already have a copy of it.
	test_xem_parser::remove( test_xem_parser::pth_to_result_file );

	// First of all I check that sizes are equal
	ASSERT_EQ( result.size(), test_xem_parser::valid_result.size() );

	// Secondary, I check that values are equal
	for( std::size_t i{0}; i < result.size(); i++ )
		ASSERT_TRUE( result[i] == test_xem_parser::valid_result[i] );
}

/*!
 * \brief Negative test parser::parser().
If we passed empty pic_composites.first or pic_composites.second - throw an exception std::invalid_argument().
*/
TEST( F_PARSE, PASS_EMPTY_PAIR_PIC_COMPOSITES_RETURN_EXCEPT ) {

	std::pair< parser::data_type, parser::data_type> pic_composites;

	std::basic_fstream< parser::char_type > f_result( test_xem_parser::pth_to_result_file,
			                                  std::ios_base::out
							);

	ASSERT_THROW( parser::parser( pic_composites,
		                      f_result
				    ),
		      std::invalid_argument
		     );

	f_result.close();

	// Remove the result file from /build/.. I already have a copy of it.
	test_xem_parser::remove( test_xem_parser::pth_to_result_file );
}

int main( int argc, char **argv) {

	::testing::InitGoogleTest(&argc, argv);

/// for more details you can see ../test/CMaekLists.txt.
/// I get these values from there.

	test_xem_parser::pth_to_pic_filtered              = argv[1];
	test_xem_parser::pth_to_find_composites           = argv[2];

	test_xem_parser::pth_to_empty_pic_filtered        = argv[3];
	test_xem_parser::pth_to_empty_find_composites     = argv[4];

	test_xem_parser::pth_to_not_exist_pic_filtered    = argv[5];
	test_xem_parser::pth_to_not_exist_find_composites = argv[6];

	test_xem_parser::pth_to_result_file               = argv[7];


return RUN_ALL_TESTS(); 
}
