
//This client file that use parser.
# include <xem_parser.hpp>

int main( int ccmd, const char **argv ) {

	using std::operator""s;
try {

// check input parameters!
	if( !argv[1] or !argv[2] )

		throw std::invalid_argument("Error. Bad input arguments for running the programm : "s + std::string(argv[0]));

	parser::path pth_to_pic(argv[1]),
		     pth_to_composites(argv[2]);

	std::pair< parser::data_type, parser::data_type> pic_composites;

// try to prepare the input data for the parsing
	parser::prepare_data  ( pth_to_pic, pth_to_composites, pic_composites );

	parser::path pth_to_results("../results.txt");

	parser::file_type f_results (pth_to_results, std::ios_base::out );

	if(!f_results.is_open()) 

		throw std::invalid_argument("Error. Can't open file for store results!");

// try to parse input data into the file
	parser::parser( pic_composites, f_results );

	std::cout << "The result's file was saved like : " << pth_to_results.filename() << '\n';

	f_results.close();
	
}

// error handlers
catch( parser::filesystem_error const& e ) {

	std::cerr << e.what() << " " << e.code().message() << '\n';
}

catch( std::invalid_argument const& e ) {

	std::cerr << e.what() << '\n';
}

catch( std::runtime_error const& e ) {

	std::cerr << e.what() << '\n';
}

}
