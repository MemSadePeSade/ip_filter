find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(TestSplit  test_split.cpp)

set_target_properties(TestSplit PROPERTIES
     CXX_STANDARD 14
     CXX_STANDARD_REQUIRED ON

     COMPILE_DEFINITIONS BOOST_TEST_DYN_LYNK
     INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(TestSplit ${Boost_LIBRARIES})
add_test(TestSplit TestSplit)








