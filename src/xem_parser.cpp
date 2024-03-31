// This file describes all the definitions of functions in this project.
# include <xem_parser.hpp>


//This is definition of function parser::prepare_data().

void parser::prepare_data( path const& pth_to_pic, 
		           path const& pth_to_composites,
			   std::pair<data_type, data_type>& pic_composites ) {

	// Are the source files exist in the filesystem and that non-empty?
	std::error_code err_code;

	if( !file_size(pth_to_composites, err_code) or !file_size(pth_to_pic,err_code) or err_code )

		throw parser::filesystem_error("Error. prepare_data(). Invalid input paths", err_code );

	// Are the source files were opened ?
	std::fstream f_pic        ( pth_to_pic ),
		     f_composites ( pth_to_composites );

	using std::operator""s;

	if( !f_pic.is_open() or !f_composites.is_open() ) 

		throw std::ios_base::failure("Error.prepare_data(). Can't open input files: "s + std::string(pth_to_pic.filename()) + std::string(pth_to_composites.filename()));

	str_type str_1_buff,
		 str_2_buff;

	// The preparing data for file.XEM that contains all the composites and tags.
	while( !f_pic.eof() ) {
			
		std::getline(f_pic, str_1_buff);
		std::getline(f_pic, str_2_buff);
		if ( !str_1_buff.empty() and !str_2_buff.empty() )
			pic_composites.first.emplace_back(str_1_buff + str_2_buff);

	}

	// The preparing data for file that contains the necessary composites
	while( !f_composites.eof() ) {

		std::getline(f_composites, str_1_buff );
		pic_composites.second.emplace_back(str_1_buff );
		}

	f_composites.close();

	f_pic.close();

	if( pic_composites.first.empty() or pic_composites.second.empty() )

		throw std::runtime_error("Error.prepare_data(). The preparing was fail!");
} 

// This is definition of function parser::paser().

void parser::parser( std::pair<data_type, data_type> const& pic_composites, file_type& f_results ) {

	// is the composites_pic empty?
	if( pic_composites.first.empty() or pic_composites.second.empty() ) 

		throw std::invalid_argument("Error.parser(). The data for parsing was empty!");

	for( auto const& search_composite : pic_composites.second ) {
	
		std::basic_regex< char_traits::char_type> regex { ".*\"CompositeName\" Value=\"("+ search_composite + ")\" />.*\"InstanceName\" Value=\"(.*)\" />.*"};

		std::match_results <str_type::const_iterator> match_results;

		std::size_t cnt_match{0};

		for( auto const& str_pic : pic_composites.first ) {

			if( std::regex_match( str_pic, match_results, regex ) ) {

				// count of matches
				cnt_match++;

				// write name of composite
				if( cnt_match == 1 ) 
					f_results << " Composite name = " << search_composite << '\n';

				// write name of tag
				f_results << cnt_match <<") " << match_results[2] << '\n';
			}
		}
	}


}

