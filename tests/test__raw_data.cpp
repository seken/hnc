// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <iostream>
#include <typeinfo>

#include <hnc/raw_data.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	// raw_data is used (and test) in hnc::ssl::hash::xxx functions

	{
		hnc::raw_data<8> r;
		std::array<unsigned char, 8> s;
		
		std::cout << typeid(decltype(r)::value_type).name() << std::endl;
		std::cout << typeid(decltype(r)::reference).name() << std::endl;
		std::cout << typeid(decltype(r)::const_reference).name() << std::endl;
		std::cout << typeid(decltype(r)::pointer).name() << std::endl;
		std::cout << typeid(decltype(r)::const_pointer).name() << std::endl;
		std::cout << typeid(decltype(r)::iterator).name() << std::endl;
		std::cout << typeid(decltype(r)::const_iterator).name() << std::endl;
		std::cout << typeid(decltype(r)::reverse_iterator).name() << std::endl;
		std::cout << typeid(decltype(r)::const_reverse_iterator).name() << std::endl;
		std::cout << typeid(decltype(r)::size_type).name() << std::endl;
		std::cout << typeid(decltype(r)::difference_type).name() << std::endl;

		for (auto const e : r) { std::cout << int(e); } std::cout << std::endl;

		for (auto it = r.rbegin(); it != r.rend(); ++it) { std::cout << int(*it); } std::cout << std::endl;

		std::cout << r.size() << std::endl;
		std::cout << r.max_size() << std::endl;
		std::cout << r.empty() << std::endl;

		for (std::size_t i = 0; i < r.size(); ++i) { std::cout << int(r[i]); } std::cout << std::endl;
		for (std::size_t i = 0; i < r.size(); ++i) { std::cout << int(r.at(i)); } std::cout << std::endl;
		std::cout << r.front() << std::endl;
		std::cout << r.back() << std::endl;
		for (std::size_t i = 0; i < r.size(); ++i) { std::cout << int(r.data()[i]); } std::cout << std::endl;

		r.fill('0');
		r.swap(s);
		r.swap(r);
		
		std::cout << (r == r) << std::endl;
		std::cout << (r != r) << std::endl;
		std::cout << (r < r) << std::endl;
		std::cout << (r <= r) << std::endl;
		std::cout << (r > r) << std::endl;
		std::cout << (r >= r) << std::endl;
		
		std::cout << r << std::endl;
	}

	hnc::test::warning(nb_test == 0, "hnc::raw_data: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
