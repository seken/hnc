// Copyright © 2014 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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
#include <string>

#include <hnc/view_ptr.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	++nb_test;
	{
		hnc::view_ptr<int> p;
		
		std::cout << "p = " << p << std::endl;
		
		nb_test -= hnc::test::warning(bool(p) == false && p == false, "hnc::view_ptr fails\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		int e = 0;
		hnc::view_ptr<int> p(e);
		
		std::cout << "e = " << e << std::endl;
		std::cout << "p = " << p << std::endl;
		
		nb_test -= hnc::test::warning(bool(p) && p && e == *p, "hnc::view_ptr fails\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		std::string e("test");
		hnc::view_ptr<std::string> p(e);
		
		std::cout << "e = " << e << std::endl;
		std::cout << "p = " << p << std::endl;
		
		nb_test -= hnc::test::warning(bool(p) && p && e == *p, "hnc::view_ptr fails\n");
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::view_ptr: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
