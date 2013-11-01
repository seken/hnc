// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

// This file is part of hnc.

// hnc is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// hnc is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with hnc. If not, see <http://www.gnu.org/licenses/>


#include <iostream>
#include <sstream>
#include <string>

#include <hnc/log_level.hpp>
#include <hnc/test.hpp>
#include <hnc/terminal.hpp>


int main()
{
	int nb_test = 0;

	// Visual test
	std::cout << "Visual test" << std::endl;
	{
		hnc::out(2, 0) << "hnc::out(2, 0): log ok" << std::endl;
		hnc::out(2, 1) << "hnc::out(2, 1): log ok" << std::endl;
		hnc::out(2, 2) << "hnc::out(2, 2): log ok" << std::endl;
		hnc::out(2, 3) << hnc::terminal::error << "hnc::out(2, 3): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
		hnc::out(2, 4) << hnc::terminal::error << "hnc::out(2, 4): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
	}
	std::cout << std::endl;

	// Test with int
	std::cout << "Test with int" << std::endl;
	++nb_test;
	{
		std::ostringstream o;
		hnc::out(2, 0, o) << "hnc::out(2, 0): log ok" << std::endl;
		std::cout << o.str(); std::cout.flush();
		nb_test -= hnc::test::warning(o.str() != "", o.str());
	}
	++nb_test;
	{
		std::ostringstream o;
		hnc::out(2, 1, o) << "hnc::out(2, 1): log ok" << std::endl;
		std::cout << o.str(); std::cout.flush();
		nb_test -= hnc::test::warning(o.str() != "", o.str());
	}
	++nb_test;
	{
		std::ostringstream o;
		hnc::out(2, 2, o) << "hnc::out(2, 2): log ok" << std::endl;
		std::cout << o.str(); std::cout.flush();
		nb_test -= hnc::test::warning(o.str() != "", o.str());
	}
	++nb_test;
	{
		std::ostringstream o;
		hnc::out(2, 3, o) << hnc::terminal::error << "hnc::out(2, 3): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
		std::cout << o.str(); std::cout.flush();
		nb_test -= hnc::test::warning(o.str() == "", o.str());
	}
	++nb_test;
	{
		std::ostringstream o;
		hnc::out(2, 4, o) << hnc::terminal::error << "hnc::out(2, 4): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
		std::cout << o.str(); std::cout.flush();
		nb_test -= hnc::test::warning(o.str() == "", o.str());
	}
	std::cout << std::endl;

	// Visual test with enum
	std::cout << "Visual test with enum" << std::endl;
	{
		enum log_level {minimal_log, normal_log, verbose_log};
		// minimal_log
		{
			std::cout << "minimal_log" << std::endl;
			hnc::out(minimal_log, minimal_log) << "- hnc::out(minimal_log, minimal_log): log ok" << std::endl;
			hnc::out(minimal_log, normal_log)  << hnc::terminal::error << "- hnc::out(minimal_log, normal_log): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
			hnc::out(minimal_log, verbose_log) << hnc::terminal::error << "- hnc::out(minimal_log, verbose_log): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
		}
		// normal_log
		{
			std::cout << "normal_log" << std::endl;
			hnc::out(normal_log, minimal_log) << "- hnc::out(normal_log, minimal_log): log ok" << std::endl;
			hnc::out(normal_log, normal_log)  << "- hnc::out(normal_log, normal_log):  log ok" << std::endl;
			hnc::out(normal_log, verbose_log) << hnc::terminal::error << "- hnc::out(normal_log, verbose_log): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
		}
		// verbose_log
		{
			std::cout << "verbose_log" << std::endl;
			hnc::out(verbose_log, minimal_log) << "- hnc::out(verbose_log, minimal_log): log ok" << std::endl;
			hnc::out(verbose_log, normal_log)  << "- hnc::out(verbose_log, normal_log):  log ok" << std::endl;
			hnc::out(verbose_log, verbose_log) << "- hnc::out(verbose_log, verbose_log): log ok" << std::endl;
		}
	}
	std::cout << std::endl;

	// Test with enum
	std::cout << "Test with enum" << std::endl;
	{
		enum log_level {minimal_log, normal_log, verbose_log};
		// minimal_log
		std::cout << "minimal_log" << std::endl;
		{
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(minimal_log, minimal_log, o) << "- hnc::out(minimal_log, minimal_log): log ok" << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() != "", o.str());
			}
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(minimal_log, normal_log, o)  << hnc::terminal::error << "- hnc::out(minimal_log, normal_log): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() == "", o.str());
			}
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(minimal_log, verbose_log, o) << hnc::terminal::error << "- hnc::out(minimal_log, verbose_log): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() == "", o.str());
			}
		}
		// normal_log
		std::cout << "normal_log" << std::endl;
		{
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(normal_log, minimal_log, o) << "- hnc::out(normal_log, minimal_log): log ok" << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() != "", o.str());
			}
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(normal_log, normal_log, o)  << "- hnc::out(normal_log, normal_log):  log ok" << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() != "", o.str());
			}
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(normal_log, verbose_log, o) << hnc::terminal::error << "- hnc::out(normal_log, verbose_log): if you see this, it is a bug" << hnc::terminal::color_reset << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() == "", o.str());
			}
		}
		// verbose_log
		std::cout << "verbose_log" << std::endl;
		{
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(verbose_log, minimal_log, o) << "- hnc::out(verbose_log, minimal_log): log ok" << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() != "", o.str());
			}
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(verbose_log, normal_log, o)  << "- hnc::out(verbose_log, normal_log):  log ok" << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() != "", o.str());
			}
			++nb_test;
			{
				std::ostringstream o;
				hnc::out(verbose_log, verbose_log, o) << "- hnc::out(verbose_log, verbose_log): log ok" << std::endl;
				std::cout << o.str(); std::cout.flush();
				nb_test -= hnc::test::warning(o.str() != "", o.str());
			}
		}
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::log_level: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
