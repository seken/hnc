// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

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


#if defined(NDEBUG)
	#undef NDEBUG
#endif

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

#include <hnc/math/geometric_mean.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	++nb_test;
	#if defined(NDEBUG)
		std::cout << "With NDEBUG" << std::endl;
	#else
		std::cout << "Without NDEBUG" << std::endl;
		--nb_test;
	#endif

	{
		std::vector<int> c(0);
		std::cout << "Geometric mean of empty std::vector of int:" << std::endl;
		++nb_test;
		{
			try
			{
				int geo_mean = hnc::math::geometric_mean(c);
				std::cout << "- " << geo_mean << std::endl;
			}
			catch (std::exception const & e)
			{
				hnc::test::warning(false, std::string(e.what()) + "\n");
				--nb_test;
			}
		}
		++nb_test;
		{
			try
			{
				int geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
				std::cout << "- " << geo_mean << std::endl;
			}
			catch (std::exception const & e)
			{
				hnc::test::warning(false, std::string(e.what()) + "\n");
				--nb_test;
			}
		}
	}
	std::cout << std::endl;

	{
		std::list<int> c({42});
		int ref = 42;
		std::cout << "Geometric mean of std::list of one int (42):" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			int geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			int geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::vector<int> c({21, 21, 21});
		int ref = 21;
		std::cout << "Geometric mean of std::vector of {21, 21, 21}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			int geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			int geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::list<int> c({2, 8});
		int ref = 4;
		std::cout << "Geometric mean of std::list of {2, 8}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			int geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			int geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::vector<float> c({4, 1, 1.f/32});
		float ref = 0.5;
		std::cout << "Geometric mean of std::vector of {4, 1, 1.f/32}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			float geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			float geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::list<float> c({1, 1000});
		float ref = 31.62278;
		std::cout << "Geometric mean of std::list of {1, 1000}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			float geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.00001f, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			float geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.00001f, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::vector<float> c({10, 0.1f});
		float ref = 1;
		std::cout << "Geometric mean of std::vector of {10, 0.1f}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			float geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			float geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(geo_mean == ref, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::list<double> c({20, 0.02});
		double ref = 0.632456; // 0.6324555320336759;
		std::cout << "Geometric mean of std::list of {20, 0.02}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.000001, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.000001, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::vector<double> c({2, 0.2});
		double ref = 0.632456; // 0.6324555320336759;
		std::cout << "Geometric mean of std::vector of {2, 0.2}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.000001, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.000001, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::list<double> c({20, 0.02, 1, 10.5, 56.1});
		double ref = 2.98155; // 2.981552289953565;
		std::cout << "Geometric mean of std::list of {20, 0.02, 1, 10.5, 56.1}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.00001, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.00001, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	{
		std::vector<double> c({89, 0.005, 21, 42, 73, 2, 0.2});
		double ref = 3.80091; // 3.800907929174658;
		std::cout << "Geometric mean of std::vector of {2, 0.2}:" << std::endl;
		std::cout << "- Reference                           = " << ref << std::endl;
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c);
			std::cout << "- hnc::math::geometric_mean container = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.00001, "hnc::math::geometric_mean container == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
		++nb_test;
		{
			double geo_mean = hnc::math::geometric_mean(c.begin(), c.end());
			std::cout << "- hnc::math::geometric_mean iterator  = " << geo_mean << std::endl;
			nb_test -= hnc::test::warning(std::abs(geo_mean - ref) < 0.00001, "hnc::math::geometric_mean iterator == " + hnc::to_string(geo_mean) + " instead of " + hnc::to_string(ref) + "\n");
		}
	}
	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::geometric_mean: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
