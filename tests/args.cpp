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
	bool arg_opt = args.add_option({"--opt", "--option"}, "One option");
	// Option with one argument (last boolean means the option must be present, false by default)
	int arg_int = args.add_option({"--i", "--int"}, "n", "One integer", 0, true);
	// Option with a float (the return type depends on the 4th argument)
	float arg_float = args.add_option({"--float"}, "n", "One float", float(0));
	args.add_separator();
	// Option with several same type arguments
	auto arg_ints = args.add_option
	(
		{"--ints"}, {"n", "n", "n"}, "3 ints",
		{0, 0, 0}
	);
	// Option with several (different type) arguments
	auto arg_tuple = args.add_option
	(
		{"--types"}, {"s", "s", "s", "n", "s"}, "3 strings, 1 int, 1 string",
		std::make_tuple(std::string(""), std::string(""), std::string(""), 0, std::string(""))
	);
	args.add_separator();
	bool arg_version = args.add_option({"-v", "--version"}, "Display the version");
	bool arg_help    = args.add_option({"-h", "--help", "-?"}, "Display this help");

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
	std::cout << "    " << "--opt   " << arg_opt << std::endl;
	std::cout << "    " << "--int   " << arg_int << std::endl;
	std::cout << "    " << "--float " << arg_float << std::endl;
	std::cout << "    " << "--ints  " << arg_ints << std::endl;
	std::cout << "    " << "--tuple " << arg_tuple << std::endl;
	std::cout << "    " << "-v      " << arg_version << std::endl;
	std::cout << "    " << "-h      " << arg_help << std::endl;
	std::cout << std::endl;

	// Display the errors
	std::cout << "Errors:" << std::endl;
	for (auto const & error : args.errors())
	{
		std::cout << "    " << hnc::terminal::error << error.what() << hnc::terminal::color_reset << std::endl;
	}
	std::cout << std::endl;

	nb_test += 7;
	nb_test -= hnc::test::warning(arg_opt == true, "--opt is given\n");
	nb_test -= hnc::test::warning(arg_int == 42, "--int 42 is given\n");
	nb_test -= hnc::test::warning(arg_ints == std::vector<int>({21, 42, 73}), "--ints 21 42 73 is given\n");
	nb_test -= hnc::test::warning(arg_tuple == std::make_tuple(std::string("this is a"), std::string("tuple"), std::string("with"), 5, std::string("elements")), "--types \"this is a\" \"tuple\" \"with\" \"5\" \"elements\" is given\n");
	nb_test -= hnc::test::warning(arg_version == false, "--version is not given\n");
	nb_test -= hnc::test::warning(arg_help == false, "--help is not given\n");
	nb_test -= hnc::test::warning(args.errors().size() == 0, "No error\n");
	
	hnc::test::warning(nb_test == 0, "hnc::arg " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
