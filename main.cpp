#include "split.h"
#include "ip_adress.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <functional>

int main(int argc, char const *argv[])
{
	try
	{
		std::multiset<IpAdress, std::greater<IpAdress>> ip_pool;

		for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = std::move(split(line, '\t'));
			ip_pool.emplace(split(v.at(0), '.'));
		}

		for (const auto& ip : ip_pool)
			std::cout << ip << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}