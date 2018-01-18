#include "../split.h"

#define BOOST_TEST_MODULE TestSplit
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(TestSplit)
{
	typedef std::vector<std::string> Tokens;
	
	BOOST_CHECK(split("", '.')      == Tokens({""}));
	BOOST_CHECK(split("11", '.')    == Tokens({ "11" }));;
	BOOST_CHECK(split("..", '.')    == Tokens({ "", "", "" }));;
	BOOST_CHECK(split("11.", '.')   == Tokens({ "11", "" }));;
	BOOST_CHECK(split(".11", '.')   == Tokens({ "", "11" }));;
	BOOST_CHECK(split("11.22", '.') == Tokens({ "11", "22" }));
}