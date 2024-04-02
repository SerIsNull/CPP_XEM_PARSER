<b>This is XEM-parser for getting all the necessary types and their tags from pic.XEM of the SCADA-system Oasys. This xem_parser is based on the regular expressions.</b>

**How to use it?**

***Download***
- For clone this project on your PC you need to use this command for getting submodule too:
```
git clone --recurse-submodules name-of-repo.git
```

***Build***
- First of all you need to have some programms in your OS such as touch, grep and awk. These programms are necessary for building.
- The doxygen isn't required but if you want to generate documentation you need to have it too.
- Actually, you'll nedd to have 2 input files. The first file is a pic.XEM (SCADA) and the second file is a list.txt.txt (composites for getting ).
- After that you need to create the build directory and change it:
```
$ mkdir ./build && cd ./build
```
- You need to run cmake in the creating /build directory for generating some files for building. You can do it using cmd:
```
$ cmake ..
```
- CMake will start checking that all the necessary files are exists. If you'll see this message you're on the right way:
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/f37771b1-57a6-4d61-8948-8c05f343476c)

- After the generating necessary files you can try to build this project:
```
$ cmake --build .
```

- Afret that you'll need to change directory

- First of all you need to create the build directory. You can do it using cmd :

```
$ mkdir ./build && cd ./build.
```
- You need to run cmake in the /build directory for generating some files for building. You can do it using cmd:
```
/build/$ cmake ..
```
- After that you'll get all the necessary files for building. So, fo the building xem_parser you need to use this cmd:
```
/build/$ cmake --build .
```
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/81225d3b-51e3-4d67-8448-c74d6b7bff5b)

***Run***
- So, as you understood, after the building xem_parser it runs with the input parameters automaticaly.
- After the running the result file of parsing saved into /build/results.txt.
- You can run it manually but I don't recommend you because the first input file.XEM ( picture of the SCADA-system ) generates into /src/CMakeLists.txt with grep help using regular expression.
- The most easy way to run it again it's just clean the /buid directory and put two new input files into the root-directory of the project:
```
/build/$ rm -r *
/build/$ cmake ..
/build/$ cmake --build .
```
***Test***
- The directory /test contains two input files for test.
- Other input files for test will be generated with CMake help. It desribes into the /test/CMakelists.txt.
- This test uses the gtest library. This library builds automaticaly because gtest includes into this project as a submodule.
- Therefore, for test you just need to run those build commands which I write above. For example, this is part of output:
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/dd8a0065-f322-4885-8e71-a8c56fa90cb5)

- Attention! This test builds and runs before building xem_parser, therefore if it'll be fail - the xem_parser won't build. For exampale:
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/33008cf5-6e71-4546-b56b-70898e176d22)

***Documentations***
- If you need some documentations you can generate it. But for it you need to have doxygen in your OS.
- After the generate some files, I mean after these comands:
```
$ mkdir ./build && cd ./build
$ cmake ..
```
You can see the result of checking doxygen:
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/87719446-6672-4416-8fc7-79701abb51ec)
- After that you need to follow those recommendations:
```
/build/$ make generate_doc
```
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/f65959b9-b321-44ac-89ea-7ef016303f1a)

- After that you can open the doc file into the directory /build/doc/html/index.html. Yoy can see it on these pictures:
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/b4e1e6e4-caee-44e4-bd54-10f91159d062)
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/26948bec-d5d7-4746-8da3-c04230cdef83)
![image](https://github.com/SerIsNull/CPP_XEM_PARSER/assets/124979388/55f1ef11-3c11-4a9a-8e68-58674778885d)





