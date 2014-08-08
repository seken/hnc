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
#include <iterator>

#include <hnc/any.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/string.hpp>


int main()
{
	int nb_test = 0;
	
	++nb_test;
	{
		hnc::any a;
		std::cout << "Type = \"" << a.type().name() << "\"" << std::endl;
		nb_test -= hnc::test::warning(a.empty(), "hnc::any fails with type \""_s + a.type().name() + "\"\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		hnc::any a = 5;
		std::cout << hnc::any_cast<int>(a) << std::endl;
		nb_test -= hnc::test::warning(hnc::any_cast_ref<int>(a) == 5, "hnc::any fails with type \""_s + a.type().name() + "\"\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		hnc::any a = 42.21;
		auto & ref = hnc::any_cast_ref<double>(a);
		std::cout << hnc::any_cast<double>(a) << std::endl;
		ref = 21.73;
		std::cout << hnc::any_cast_ref<double>(a) << std::endl;
		nb_test -= hnc::test::warning(hnc::any_cast<double>(a) == 21.73, "hnc::any fails with type \""_s + a.type().name() + "\"\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		hnc::any a = 21;
		a = std::string("A std::string");
		std::cout << hnc::any_cast_ref<std::string>(a) << std::endl;
		nb_test -= hnc::test::warning(hnc::any_cast_ref<std::string>(a) == "A std::string", "hnc::any fails with type \""_s + a.type().name() + "\"\n");
	}
	std::cout << std::endl;
	
	++nb_test;
	{
		hnc::any a = 21;
		a = std::string("A std::string");
		try
		{
			std::cout << hnc::any_cast_ref<int>(a) << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			--nb_test;
		}
	}
	std::cout << std::endl;
	
	hnc::test::warning(nb_test == 0, "hnc::any " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
