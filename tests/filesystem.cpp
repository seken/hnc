// Copyright © 2013 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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
#include <string>

#include <hnc/filesystem.hpp>
#include <hnc/ostream_std.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	std::cout << std::endl;
	
	int nb_test = 0;

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

	// Dirname and Basename

	++nb_test;
	{
		std::string const s = "/path/to/file.ext";
		std::string const r = hnc::filesystem::dir_and_basename(s);
		std::cout << "Dirname and Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to/file", "hnc::filesystem::dir_and_basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "file.ext";
		std::string const r = hnc::filesystem::dir_and_basename(s);
		std::cout << "Dirname and Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "file", "hnc::filesystem::dir_and_basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/";
		std::string const r = hnc::filesystem::dir_and_basename(s);
		std::cout << "Dirname and Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to/", "hnc::filesystem::dir_and_basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "";
		std::string const r = hnc::filesystem::dir_and_basename(s);
		std::cout << "Dirname and Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "", "hnc::filesystem::dir_and_basename fails\n");
	}

	++nb_test;
	{
		std::string const s = "f";
		std::string const r = hnc::filesystem::dir_and_basename(s);
		std::cout << "Dirname and Basename of \"" << s << "\" is \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "f", "hnc::filesystem::dir_and_basename fails\n");
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

	// Add prefix and suffix

	++nb_test;
	{
		std::string const s = "/path/to/file.ext";
		std::string const r = hnc::filesystem::add_prefix(s, "prefix_");
		std::cout << "Add prefix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to/prefix_file.ext", "hnc::filesystem::add_prefix fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/file";
		std::string const r = hnc::filesystem::add_prefix(s, "prefix_");
		std::cout << "Add prefix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to/prefix_file", "hnc::filesystem::add_prefix fails\n");
	}

	++nb_test;
	{
		std::string const s = "file.ext";
		std::string const r = hnc::filesystem::add_prefix(s, "prefix_");
		std::cout << "Add prefix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "prefix_file.ext", "hnc::filesystem::add_prefix fails\n");
	}

	++nb_test;
	{
		std::string const s = "file";
		std::string const r = hnc::filesystem::add_prefix(s, "prefix_");
		std::cout << "Add prefix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "prefix_file", "hnc::filesystem::add_prefix fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/file.ext";
		std::string const r = hnc::filesystem::add_suffix(s, "_suffix");
		std::cout << "Add suffix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to/file_suffix.ext", "hnc::filesystem::add_suffix fails\n");
	}

	++nb_test;
	{
		std::string const s = "/path/to/file";
		std::string const r = hnc::filesystem::add_suffix(s, "_suffix");
		std::cout << "Add suffix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "/path/to/file_suffix", "hnc::filesystem::add_suffix fails\n");
	}

	++nb_test;
	{
		std::string const s = "file.ext";
		std::string const r = hnc::filesystem::add_suffix(s, "_suffix");
		std::cout << "Add suffix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "file_suffix.ext", "hnc::filesystem::add_suffix fails\n");
	}

	++nb_test;
	{
		std::string const s = "file";
		std::string const r = hnc::filesystem::add_suffix(s, "_suffix");
		std::cout << "Add suffix: \"" << s << "\" become \"" << r << "\"" << std::endl;
		nb_test -= hnc::test::warning(r == "file_suffix", "hnc::filesystem::add_suffix fails\n");
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

	// read_file

	++nb_test;
	{
		std::cout << "hnc::filesystem::read_file" << std::endl;
		// Write
		std::string const txt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. \nSed non risus. \nSuspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.\n";
		std::cout << "txt:" << std::endl << txt;
		std::string const filename = hnc::filesystem::tmp_filename();
		{
			std::ofstream f(filename);
			f << txt;
		}
		// Read
		std::string const read_txt = hnc::filesystem::read_file(filename);
		std::cout << "txt:" << std::endl << read_txt;
		nb_test -= hnc::test::warning(read_txt == txt, "hnc::filesystem::read_file fails\n");
		// Remove
		hnc::filesystem::remove(filename);
	}
	std::cout << std::endl;

	// copy_file

	++nb_test;
	{
		std::cout << "hnc::filesystem::copy_file" << std::endl;
		// txt
		std::string const txt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. \nSed non risus. \nSuspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.\n";
		std::cout << "txt:" << std::endl << txt;
		// Source
		std::string const src_filename = hnc::filesystem::tmp_filename();
		{
			std::ofstream f(src_filename);
			f << txt;
		}
		// Destination
		std::string const dest_filename = hnc::filesystem::filename_without_overwrite(src_filename);
		hnc::filesystem::copy_file(src_filename, dest_filename);
		std::string const copy_txt = hnc::filesystem::read_file(dest_filename);
		std::cout << "copy_txt:" << std::endl << copy_txt;
		nb_test -= hnc::test::warning(copy_txt == txt, "hnc::filesystem::copy_file fails\n");
		// Remove
		hnc::filesystem::remove(src_filename);
		hnc::filesystem::remove(dest_filename);
	}
	std::cout << std::endl;

	// File exists & filename_without_overwrite

	++nb_test;
	{
		std::string const r = hnc::filesystem::tmp_filename();
		std::cout << "File \"" << r << "\" must exist" << std::endl;
		nb_test -= hnc::test::warning(hnc::filesystem::file_exists(r) == true && hnc::filesystem::file_is_readable(r) == true && hnc::filesystem::file_is_writeable(r) == true, "hnc::filesystem::file_exists fails\n");
		hnc::filesystem::remove(r);
	}

	++nb_test;
	{
		std::string const r = hnc::filesystem::tmp_filename();
		hnc::filesystem::remove(r);
		std::cout << "File \"" << r << "\" must not exist" << std::endl;
		nb_test -= hnc::test::warning(hnc::filesystem::file_exists(r) == false && hnc::filesystem::file_is_readable(r) == false && hnc::filesystem::file_is_writeable(r) == false, "hnc::filesystem::file_exists fails\n");
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

	nb_test += 5;
	{
		std::string const path = hnc::filesystem::filename_without_overwrite(hnc::filesystem::tmp_filename());
		std::cout << "Create directory " << path << std::endl;
		bool const r = hnc::filesystem::create_directory(path);
		{ std::ofstream f(path + "/hnc_tmp"); }
		nb_test -= hnc::test::warning(r && hnc::filesystem::file_exists(path + "/hnc_tmp"), "hnc::filesystem::create_directory fails\n");
		nb_test -= hnc::test::warning(r && hnc::filesystem::is_a_directory(path), "hnc::filesystem::is_a_directory fails\n");
		nb_test -= hnc::test::warning(r && hnc::filesystem::is_a_file(path) == false, "hnc::filesystem::is_a_file fails\n");
		nb_test -= hnc::test::warning(r && hnc::filesystem::is_a_directory(path + "/hnc_tmp") == false, "hnc::filesystem::is_a_directory fails\n");
		nb_test -= hnc::test::warning(r && hnc::filesystem::is_a_file(path + "/hnc_tmp"), "hnc::filesystem::is_a_file fails\n");
	}
	std::cout << std::endl;

	++nb_test;
	{
		if (hnc::filesystem::file_exists("/proc/cpuinfo"))
		{
			nb_test -= hnc::test::warning(hnc::filesystem::file_is_writeable("/proc/cpuinfo") == false, "hnc::filesystem::file_is_writeable fails with \"/proc/cpuinfo\"\n\n");
		}
		else
		{
			std::cout << "/proc/cpuinfo does not exist, skip tst of hnc::filesystem::file_is_writeable" << std::endl;
			std::cout << std::endl;
			--nb_test;
		}
	}
	
	// home directory

	{
		std::cout << "home directory = " << hnc::filesystem::home() << std::endl;
		auto const filenames = hnc::filesystem::read_directory(hnc::filesystem::home());
		for (auto const & filename : filenames)
		{
			std::cout << filename << " (is exe = " << std::boolalpha << hnc::filesystem::is_executable(hnc::filesystem::home() + "/" + filename) << ")" << std::endl;
		}
	}
	std::cout << std::endl;
	
	// hnc::filesystem::read_directory

	{
		std::cout << ". = " << std::endl;
		auto const filenames = hnc::filesystem::read_directory(".");
		for (auto const & filename : filenames)
		{
			std::cout << filename << " (is exe = " << std::boolalpha << hnc::filesystem::is_executable("./" + filename) << ")" << std::endl;
		}
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::filesystem: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
