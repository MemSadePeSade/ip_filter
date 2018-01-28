#pragma once
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


struct IpAdress
{
	std::array<unsigned char,4> m_data;
	
	explicit IpAdress(const std::vector<std::string>& ip_adress)
	{
		std::transform(ip_adress.crbegin(), ip_adress.crend(), std::begin(m_data),
			[](decltype(*std::begin(ip_adress)) var) { return static_cast<unsigned char>(std::stoi(var)); });
	}
	
	/*
	friend bool operator<(const IpAdress& x, const IpAdress& y)
	{
		return std::lexicographical_compare(x.m_data.crbegin(), x.m_data.crend(),
			y.m_data.crbegin(), y.m_data.crend());
	}
	*/
	
	friend bool operator<(const IpAdress& x, const IpAdress& y)
	{
		return  (*reinterpret_cast<const uint32_t*>(x.m_data.data())) <
			    (*reinterpret_cast<const uint32_t*>(y.m_data.data()));
	}
	
	friend bool operator>(const IpAdress& x, const IpAdress& y)
	{
		return y < x;
	}

	friend std::ostream& operator<<(std::ostream& os, const IpAdress& ip)
	{
		std::ostream_iterator<unsigned> out_it(os, ".");
		std::copy(ip.m_data.crbegin(), ip.m_data.crend(), out_it);
		os << '\b';  os << " "; // delete last "."
		return os;
	}
};


