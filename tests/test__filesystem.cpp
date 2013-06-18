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
#include <fstream>

#include <hnc/filesystem.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

// 	{
// 		std::vector<int> c(0);
// 		int sumRef = 0;
// 		std::cout << "Sum of empty std::vector of int:" << std::endl;
// 		std::cout << "- Reference                = " << sumRef << std::endl;
// 		++nb_test;
// 		{
// 			int sum = hnc::algo::sum(c);
// 			std::cout << "- hnc::algo::sum container = " << sum << std::endl;
// 			nb_test -= hnc::test::warning(sum == sumRef, "hnc::algo::sum container == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
// 		}
// 		++nb_test;
// 		{
// 			int sum = hnc::algo::sum(c.begin(), c.end());
// 			std::cout << "- hnc::algo::sum iterator  = " << sum << std::endl;
// 			nb_test -= hnc::test::warning(sum == sumRef, "hnc::algo::sum iterator == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
// 		}
// 	}

	nb_test += 5;
	{
		nb_test -= hnc::test::warning(hnc::filesystem::directory_separator::common == '/', "hnc::filesystem::directory_separator::common is != of '/'\n");
		nb_test -= hnc::test::warning(hnc::filesystem::directory_separator::windows == '\\', "hnc::filesystem::directory_separator::windows is != of '\\'\n");
		nb_test -= hnc::test::warning(hnc::filesystem::directory_separator::classic_mac_os == ':', "hnc::filesystem::directory_separator::classic_mac_os is != of ':'\n");
		nb_test -= hnc::test::warning(hnc::filesystem::directory_separator::dot == '.', "hnc::filesystem::directory_separator::dot is != of '.'\n");
		nb_test -= hnc::test::warning(hnc::filesystem::directory_separator::greater_than == '>', "hnc::filesystem::directory_separator::greater_than is != of '>'\n");
	}

	// Filename

	++nb_test;
	{
		std::string const s = "/path/to/file.ext";
		std::string const r = hnc::filesystem::filename(s);
		std::cout << "Filename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "file.ext", "hnc::filesystem::filename fails\n");
	}

	++nb_test;
	{
		std::string const s = "file.ext";
		std::string const r = hnc::filesystem::filename(s);
		std::cout << "Filename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "file.ext", "hnc::filesystem::filename fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/";
		std::string const r = hnc::filesystem::filename(s);
		std::cout << "Filename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::filename fails\n");
	}

	++nb_test;
	{
		std::string const s = "";
		std::string const r = hnc::filesystem::filename(s);
		std::cout << "Filename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::filename fails\n");
	}

	++nb_test;
	{
		std::string const s = "f";
		std::string const r = hnc::filesystem::filename(s);
		std::cout << "Filename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "f", "hnc::filesystem::filename fails\n");
	}

	std::cout << std::endl;

	// Dirname

	++nb_test;
	{
		std::string const s = "/path/to/file.ext";
		std::string const r = hnc::filesystem::dirname(s);
		std::cout << "Dirname of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to", "hnc::filesystem::dirname fails\n");
	}

	++nb_test;
	{
		std::string const s = "file.ext";
		std::string const r = hnc::filesystem::dirname(s);
		std::cout << "Dirname of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::dirname fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/";
		std::string const r = hnc::filesystem::dirname(s);
		std::cout << "Dirname of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to", "hnc::filesystem::dirname fails\n");
	}

	++nb_test;
	{
		std::string const s = "";
		std::string const r = hnc::filesystem::dirname(s);
		std::cout << "Dirname of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::dirname fails\n");
	}

	++nb_test;
	{
		std::string const s = "/";
		std::string const r = hnc::filesystem::dirname(s);
		std::cout << "Dirname of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::dirname fails\n");
	}

	std::cout << std::endl;

	// Basename

	++nb_test;
	{
		std::string const s = "/path/to/file.ext";
		std::string const r = hnc::filesystem::basename(s);
		std::cout << "Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "file", "hnc::filesystem::basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "/p.a.t.h/t.o/f.i.l.e.ext";
		std::string const r = hnc::filesystem::basename(s);
		std::cout << "Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "f.i.l.e", "hnc::filesystem::basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "file.ext";
		std::string const r = hnc::filesystem::basename(s);
		std::cout << "Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "file", "hnc::filesystem::basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/";
		std::string const r = hnc::filesystem::basename(s);
		std::cout << "Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "";
		std::string const r = hnc::filesystem::basename(s);
		std::cout << "Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "f";
		std::string const r = hnc::filesystem::basename(s);
		std::cout << "Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "f", "hnc::filesystem::basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "f.";
		std::string const r = hnc::filesystem::basename(s);
		std::cout << "Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "f", "hnc::filesystem::basename fails\n");
	}

	std::cout << std::endl;

	// Extension

	++nb_test;
	{
		std::string const s = "/path/to/file.ext";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "ext", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "/p.a.t.h/t.o/f.i.l.e.ext";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "ext", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "file.ext";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "ext", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "fi.le.ext";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "ext", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "f";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "f.";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = "f.e";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "e", "hnc::filesystem::extension fails\n");
	}

	++nb_test;
	{
		std::string const s = ".";
		std::string const r = hnc::filesystem::extension(s);
		std::cout << "Extension of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::extension fails\n");
	}

	std::cout << std::endl;

	// Tmp filename & remove

	for (unsigned int i = 0; i < 10; ++i)
	{
		nb_test += 2;
		std::string const r = hnc::filesystem::tmp_filename();
		std::cout << "Tmp filename = \"" << r << "\"" << std::endl;
		{
			std::fstream f(r);
			nb_test -= hnc::test::warning(f.is_open() == true, "hnc::filesystem::tmp_filename fails\n");
		}
		hnc::filesystem::remove(r);
		{
			std::fstream f(r);
			nb_test -= hnc::test::warning(f.is_open() == false, "hnc::filesystem::remove fails\n");
		}
	}

	std::cout << std::endl;

	// File exists & filename_without_overwrite

	++nb_test;
	{
		std::string const r = hnc::filesystem::tmp_filename();
		std::cout << "File \"" << r << "\" must exist" << std::endl;
		nb_test -= hnc::test::warning(hnc::filesystem::file_exists(r) == true, "hnc::filesystem::file_exists fails\n");
		hnc::filesystem::remove(r);
	}

	++nb_test;
	{
		std::string const r = hnc::filesystem::tmp_filename();
		hnc::filesystem::remove(r);
		std::cout << "File \"" << r << "\" must not exist" << std::endl;
		nb_test -= hnc::test::warning(hnc::filesystem::file_exists(r) == false, "hnc::filesystem::file_exists fails\n");
	}

	std::cout << std::endl;

	++nb_test;
	{
		std::string const r = hnc::filesystem::tmp_filename();
		std::string const n = hnc::filesystem::filename_without_overwrite(r);
		std::cout << "File \"" << r << "\" exists, generate \"" << n << "\"" << std::endl;
		nb_test -= hnc::test::warning(hnc::filesystem::file_exists(n) == false, "hnc::filesystem::filename_without_overwrite fails\n");
		hnc::filesystem::remove(r);
	}

	++nb_test;
	{
		std::string const f0 = hnc::filesystem::tmp_filename();
		std::string const n0 = hnc::filesystem::filename_without_overwrite(f0);
		{ std::ofstream f(n0); }
		std::string const n1 = hnc::filesystem::filename_without_overwrite(f0);
		std::cout << "File \"" << f0 << "\" exists, generate \"" << n0 << "\" and generate \"" << n1 << "\"" << std::endl;
		nb_test -= hnc::test::warning(hnc::filesystem::file_exists(n0) == true && hnc::filesystem::file_exists(n1) == false, "hnc::filesystem::filename_without_overwrite fails\n");
		hnc::filesystem::remove(f0);
		hnc::filesystem::remove(n0);
	}

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::filesystem: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}