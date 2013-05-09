// Copyright © 2012 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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

#include <hnc/args.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>
#include <hnc/ostream_std.hpp>


int main(int argc, char * * argv)
{
	int nb_test = 0;
	
	hnc::args args(argc, argv, "Description of your program", "Version & Author");

	// One option without argument
	bool arg_opt0 = args.add_option({"--opt0", "--option0"}, "Option 0");
	bool arg_opt1 = args.add_option({"--opt1", "--option1"}, "Option 1");
	bool arg_opt2 = args.add_option({"--opt2", "--option2"}, "Option 2");
	bool arg_opt3 = args.add_option({"--opt3", "--option3"}, "Option 3");
	bool arg_opt4 = args.add_option({"--opt4", "--option4"}, "Option 4");

	// Display the args (same as help)
	std::cout << args << std::endl;
	// You can display: args.usage(), args.help(), args.version() too

	// Display the arguments
	std::cout << "Arguments:" << std::endl;
	for (auto const & arg : args.raw_args())
	{
		std::cout << "    " << arg << std::endl;
	}
	std::cout << std::endl;

	// Display the option given
	std::cout << std::boolalpha;
	std::cout << "Options:" << std::endl;
	std::cout << "    " << "--opt0 " << arg_opt0 << std::endl;
	std::cout << "    " << "--opt1 " << arg_opt1 << std::endl;
	std::cout << "    " << "--opt2 " << arg_opt2 << std::endl;
	std::cout << "    " << "--opt3 " << arg_opt3 << std::endl;
	std::cout << "    " << "--opt4 " << arg_opt4 << std::endl;
	std::cout << std::endl;

	nb_test += 5;
	nb_test -= hnc::test::warning(arg_opt0 == true, "--opt0 is given\n");
	nb_test -= hnc::test::warning(arg_opt1 == true, "--option1 is given\n");
	nb_test -= hnc::test::warning(arg_opt2 == false, "--opt2 is not given\n");
	nb_test -= hnc::test::warning(arg_opt3 == true, "--opt3 is given\n");
	nb_test -= hnc::test::warning(arg_opt4 == false, "--opt4 is not given\n");
	
	hnc::test::warning(nb_test == 0, "hnc::arg " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
