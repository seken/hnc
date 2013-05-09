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


int main()
{
	int nb_test = 0;

	
	hnc::args args
	(
		{
			"prog_name",
			"-?",
			"-opt",
			"--n", "42",
			"--test1",
			"--test2", "-5", "5",
			"--test3", "21", "42", "73",
			"--test4", "21", "42",
			"--test5", "one string", "42",
			"--test6", "One tuple of", "3", "elements"
		},
		"Just a quick test for hnc::args", "Copyright © 2012 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr"
	);

	bool arg_opt = args.add_option({"--opt", "-opt"}, "One option");
	int arg_n = args.add_option({"--n", "-n"}, "n", "One integer", 0);
	args.add_separator();
	auto arg_t0 = args.add_option({"--test0"}, "n", "Must be present, but not given", 0, true);
	auto arg_t1 = args.add_option({"--test1"}, "n", "Present without argument", 0, true);
	auto arg_t2 = args.add_option({"--test2"}, {"x", "y"}, "Excepted 2 int arguments", {0, 0});
	auto arg_t3 = args.add_option({"--test3"}, {"x", "y", "z"}, "Excepted 3 int arguments", {0, 0, 0});
	auto arg_t4 = args.add_option({"--test4"}, {"x", "y", "z"}, "Excepted 2 int arguments, only 2 are given", {0, 0, 0});
	auto arg_t5 = args.add_option({"--test5"}, {"n", "s"}, "Excepted 1 int and 1 string", std::make_tuple(std::string("default"), 0));
	auto arg_t6 = args.add_option({"--test6"}, {"s", "n", "s"}, "Excepted 1 string, 1 int and 1 string", std::make_tuple(std::string("default"), 0, std::string("default")));
	args.add_separator();
	bool arg_version = args.add_option({"-v", "--version"}, "Display the version");
	bool arg_help = args.add_option({"-h", "--help", "-?"}, "Display this help");

	std::cout << std::boolalpha;
	
	std::cout << args << std::endl;

	std::cout << "Options:" << std::endl;
	std::cout << "    " << "--opt   " << arg_opt << std::endl;
	std::cout << "    " << "--n     " << arg_n << std::endl;
	std::cout << "    " << "--test0 " << arg_t0 << std::endl;
	std::cout << "    " << "--test1 " << arg_t1 << std::endl;
	std::cout << "    " << "--test2 " << arg_t2 << std::endl;
	std::cout << "    " << "--test3 " << arg_t3 << std::endl;
	std::cout << "    " << "--test4 " << arg_t4 << std::endl;
	std::cout << "    " << "--test5 " << arg_t5 << std::endl;
	std::cout << "    " << "--test6 " << arg_t6 << std::endl;
	std::cout << "    " << "-v      " << arg_version << std::endl;
	std::cout << "    " << "-h      " << arg_help << std::endl;
	std::cout << std::endl;

	std::cout << "Errors:" << std::endl;
	for (auto const & error : args.errors())
	{
		std::cout << "    " << hnc::terminal::error << error.what() << hnc::terminal::color_reset << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Arguments:" << std::endl;
	for (auto const & arg : args.raw_args())
	{
		std::cout << "    " << arg << std::endl;
	}
	std::cout << std::endl;

	std::cout << "bash completion:" << std::endl;
	std::cout << args.bash_completion() << std::endl;

	nb_test += 11;
	nb_test -= hnc::test::warning(arg_opt == true, "-opt is given\n");
	nb_test -= hnc::test::warning(arg_version == false, "-v is not given\n");
	nb_test -= hnc::test::warning(arg_help == true, "-? is given\n");
	nb_test -= hnc::test::warning(arg_t0 == 0, "-test0 is given with no argument\n");
	nb_test -= hnc::test::warning(arg_t1 == 0, "-n 42 is given\n");
	nb_test -= hnc::test::warning(arg_t2 == std::vector<int>({-5, 5}), "--test2 is given with -5 5\n");
	nb_test -= hnc::test::warning(arg_t3 == std::vector<int>({21, 42, 73}), "--test3 is given with 21 42 73\n");
	nb_test -= hnc::test::warning(arg_t4 == std::vector<int>({0, 0, 0}), "--test4 is given with 21 42, one argument miss\n");
	nb_test -= hnc::test::warning(arg_t5 == std::make_tuple(std::string("one string"), 42), "--test5 is given with 'one string' 42\n");
	nb_test -= hnc::test::warning(arg_t6 == std::make_tuple(std::string("One tuple of"), 3, std::string("elements")), "--test6 is given with 'One tuple of' 3 'elements'\n");
	nb_test -= hnc::test::warning(args.errors().size() == 3, "The number of errors must be 3\n");
	
	hnc::test::warning(nb_test == 0, "hnc::arg " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
