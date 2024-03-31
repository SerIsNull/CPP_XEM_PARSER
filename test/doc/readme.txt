/*! \mainpage This is XEM-parser for getting all the necessary types and their tags from pic.XEM of the SCADA-system Oasys. This xem_parser is based on the regular expressions.
- \ref groupExample "How to use it?"
- \ref groupMoreDetails "More ditails"
*/
/**
\defgroup groupExample This sections shows how to use it.
- First of all you need to put two input files into the project derectory. The first file.XEM describes all compoistes and tags in the picture of SCADA-OASYS, the second file.txt.txt describes the composites that you need to be obtained from the picture of the SCADA-OASYS.
- After that, you need to create the directory for building. In the project root-directory you need to use cmd: mkdir build.
- For generating some files for building you need to run the cmd like "cmake .." in the /build directory.
- After that Cmake will check the availability of the necessary programms such as g++, grep, awk an touch and something else.
- After that you'll take all the necessary files for building project.
- For build project, you need run cmd like "cmake --build ." in the /build directory.
- After that and before building the xem_parser CMake will try to create some input files for testing.
- After that CMake will build test_xem_parser for testing and run it. If the test will be fail - stop building
- If the test will be passed that CMake will start building the xem_parser.
- It'll generate new filtered pic.XEM for faster parsing. It locates into the /build directory.
- After building the xem_parser CMake tries to 
- After building the CMake makes the running of the parser xem_parser  with new filtered picture.XEM and file.txt.txt with composites.
- The result of the building and the running you can see in the standart output.
- The result file of parsing will be save in /build directory like "result.txt".
- If you want to run it againg you just need to run the progtamm /build/bin/get_tags ../pic_filtered.XEM ../composites.txt.txt
- But I don't reccomend you run it manually because pic_filtered.XEM generates in /src/CMakeLists.txt with the grep help.
- Also you can run the test again. For it you need to run ctest in the /build dirrectory and you need to have 2 input files: /test/valid_pic_filtered.XEM and /test/valid_composites.txt.txt.
*/
/**
\defgroup groupMoreDetails This section shows more details.
- \ref xem_parser.hpp
*/

