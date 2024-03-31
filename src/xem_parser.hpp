/*!
\file
\brief This header-file describes all the functions in this project.
*/
# pragma once

# include <iostream>

# include <regex>

# include <string>

# include <fstream>

# include <filesystem>

namespace parser {

	/*!
	\brief This are types and functions that I used
	*/

	using std::filesystem::path;

	using std::filesystem::file_size;

	using std::filesystem::filesystem_error;

	using char_type   = char;

	using char_traits = std::char_traits<char_type>;

	using file_type  =  std::basic_fstream<char_type>;

	using str_type    = std::basic_string<char_type>;

	using data_type   = std::vector<str_type>;

	/*!
	\brief This function for preparing input data for parsing.
	\param pth_to_pic[in]  - this is a path to the file.XEM that constains the composites and tags.
	\param pth_to_composites[int] - this is a path to the file.txt.txt that contains necessary composites.
	\param pic_composites[out] - this is a result type for writing the data from "pth_to_pic" and "pth_to_composites".
	Therefore pic_composites.first - it's the data form "pth_to_pic" and the pic_composites.second - this is the data from "pth_to_composites".

	<b>pred-conditions:</b>\n
	You need to pass the file paths that exists in the file system and that point to non-empty files.

	<b> post-conditions:</b>\n
	All data from two file paths will be write into the pic_composites.

	\throw std::filesystem::filesystem_error() if you passed the paths to the empty files.
	\throw std::ios_base::failure() if an attempt to open files failed for some reason.
	\throw std::runtime_error() if the result "pic_composites" after parsing will be empty.
*/
void prepare_data( path const& pth_to_pic, 
		   path const& pth_to_composites,
		   std::pair<data_type, data_type>& pic_composites );
	/*!
	\brief This function for parsing input data into file result.
	\param composites_pic[in] - this is a data that contains all necessary data from pic.XEM and composites.txt.txt.
	\param f_result[out] - this is a result file for writing results of parsing.
	
	<b>pred-conditions:</b>\n
	- You need to call the function prepare_data() before calling the parser().
	- You need to pass not empty composites_pic.

	<b>post-conditions:</b>\n
	The useful data will be write into the result file.
	std::invalid_argument() if you passed the empty "pic_compostes"
*/
void parser( std::pair<data_type, data_type> const& pic_composites, file_type& f_results );

}
