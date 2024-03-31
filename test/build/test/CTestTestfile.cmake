# CMake generated Testfile for 
# Source directory: /home/administrator/get_tags/test
# Build directory: /home/administrator/get_tags/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_xem_parser "/home/administrator/get_tags/build/bin/test_xem_parser" "/home/administrator/get_tags/test/valid_pic_filtered.XEM" "/home/administrator/get_tags/test/valid_composites.txt.txt" "" "" "NOT_EXIST.XEM" "NOT_EXIST.txt.txt" "/home/administrator/get_tags/build/f_result.txt")
set_tests_properties(test_xem_parser PROPERTIES  _BACKTRACE_TRIPLES "/home/administrator/get_tags/test/CMakeLists.txt;65;add_test;/home/administrator/get_tags/test/CMakeLists.txt;0;")
