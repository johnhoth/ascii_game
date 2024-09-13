# CMake generated Testfile for 
# Source directory: C:/Users/ivanz/prog/cpp/ascii_game/tests
# Build directory: C:/Users/ivanz/prog/cpp/ascii_game/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(TestRenderer "C:/Users/ivanz/prog/cpp/ascii_game/build/tests/Debug/test_renderer.exe")
  set_tests_properties(TestRenderer PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;18;add_test;C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(TestRenderer "C:/Users/ivanz/prog/cpp/ascii_game/build/tests/Release/test_renderer.exe")
  set_tests_properties(TestRenderer PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;18;add_test;C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(TestRenderer "C:/Users/ivanz/prog/cpp/ascii_game/build/tests/MinSizeRel/test_renderer.exe")
  set_tests_properties(TestRenderer PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;18;add_test;C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(TestRenderer "C:/Users/ivanz/prog/cpp/ascii_game/build/tests/RelWithDebInfo/test_renderer.exe")
  set_tests_properties(TestRenderer PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;18;add_test;C:/Users/ivanz/prog/cpp/ascii_game/tests/CMakeLists.txt;0;")
else()
  add_test(TestRenderer NOT_AVAILABLE)
endif()
