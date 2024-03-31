<b>This is XEM-parser for getting all the necessary types and their tags from pic.XEM of the SCADA-system Oasys. This xem_parser is based on the regular expressions.</b>

**How to use it?**

***Build***
- First of all you need to have some programms in your OS such as touch, grep and awk programms. These programms are necessary for building.
- The doxygen isn't required but if you want to generate documentation you need to have it too.
- Actually, you'll nedd to have 2 input files. The first file is a pic.XEM (SCADA) and the second file is a list.txt.txt (composites for getting ).
- So,iIf you're a lazy man=) you can trust Cmake this checking. If this checking will be successful, you'll get this output:

![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/39f40764-7809-4afe-8249-f8834ccbfe3e)

- First of all you need to create the build directory. You can do it using cmd :

```
mkdir ./build && cd ./build.
```
- You need to run cmake in the /build directory for generating some files for building. You can do it using cmd:
```
cmake ..
```
- After that you'll get all the necessary files for building. So, fo the building xem_parser you need to use this cmd:
```
cmake --build .
```
- In the end you'll get two files in the /build/bin directory:
1) text_xem_parser - this is a test for xem_parser;
2) xem_parser - this is a main programm.

You can create it with cmd: mkdir
- First of all you need to put two input files into the project derectory. The first file.XEM describes all compoistes and tags in the picture of SCADA-OASYS, the second file.txt.txt describes the composites that you need to be obtained from the picture of the SCADA-OASYS.
- After that, you need to create the directory for building. In the project root-directory you need to use cmd: mkdir build.
-  "cmake .." in the /build directory.
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
