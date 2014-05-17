// Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

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

#include <hnc/string.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	// ""_s
	
	++nb_test;
	{
		auto const tmp = ""_s;
		std::cout << "Types: " << typeid(std::string).name() << " vs " << typeid(decltype(tmp)).name() << std::endl;
		nb_test -= hnc::test::warning(typeid(std::string) == typeid(decltype(tmp)), "hnc operator \"\"_s fails\n");
	}
	
	std::cout << std::endl;
	
	// hnc::string::remove_multiple_whitespaces
	
	++nb_test;
	{
		std::string txt = "Text   with   multiple   spaces\t\tand \t  tabulations";
		hnc::string::remove_multiple_whitespaces(txt);
		std::cout << txt << std::endl;
		nb_test -= hnc::test::warning(txt == "Text with multiple spaces and tabulations", "hnc::string::remove_multiple_whitespaces fails\n");
	}
	
	++nb_test;
	{
		std::string const txt = "Text   with   multiple   spaces\t\tand \t  tabulations";
		std::string const copy = hnc::string::remove_multiple_whitespaces_copy(txt);
		std::cout << copy << std::endl;
		nb_test -= hnc::test::warning(copy == "Text with multiple spaces and tabulations", "hnc::string::remove_multiple_whitespaces_copy fails\n");
	}
	
	std::cout << std::endl;
	
	hnc::test::warning(nb_test == 0, "hnc::string: " + hnc::to_string(nb_test) + " test fail!\n");
	
	return 0;
}
