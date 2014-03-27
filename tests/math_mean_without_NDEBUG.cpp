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


#if defined(NDEBUG)
	#undef NDEBUG
#endif

#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

#include <hnc/math/mean.hpp>
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
		std::cout << "Mean of empty std::vector of int:" << std::endl;
		++nb_test;
		{
			try
			{
				double mean = hnc::math::mean(c);
				hnc::test::warning(false, "hnc::math::mean container does not throw exception with empty container, mean = " + hnc::to_string(mean) + "\n");
			}
			catch (std::exception const & e)
			{
				std::cout << "- " << e.what() << std::endl;
				--nb_test;
			}
		}
		++nb_test;
		{
			try
			{
				double mean = hnc::math::mean(c.begin(), c.end());
				hnc::test::warning(false, "hnc::math::mean iterator does not throw exception with empty container, mean = " + hnc::to_string(mean) + "\n");
			}
			catch (std::exception const & e)
			{
				std::cout << "- " << e.what() << std::endl;
				--nb_test;
			}
		}
	}

	{
		std::list<int> c;
		c.push_back(42);
		int meanRef = 42;
		std::cout << "Mean of std::list of one int:" << std::endl;
		std::cout << "- Reference                 = " << meanRef << std::endl;
		++nb_test;
		{
			int mean = hnc::math::mean(c);
			std::cout << "- hnc::math::mean container = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef, "hnc::math::mean container == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef) + "\n");
		}
		++nb_test;
		{
			int mean = hnc::math::mean(c.begin(), c.end());
			std::cout << "- hnc::math::mean iterator  = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef, "hnc::math::mean iterator == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef) + "\n");
		}
	}

	{
		std::list<int> c;
		c.push_back(42);
		c.push_back(13);
		int meanRef = 27; // 27.5;
		std::cout << "Mean of std::list of two int:" << std::endl;
		std::cout << "- Reference                 = " << meanRef << std::endl;
		++nb_test;
		{
			int mean = hnc::math::mean(c);
			std::cout << "- hnc::math::mean container = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef, "hnc::math::mean container == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef) + "\n");
		}
		++nb_test;
		{
			int mean = hnc::math::mean(c.begin(), c.end());
			std::cout << "- hnc::math::mean iterator  = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef, "hnc::math::mean iterator == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef) + "\n");
		}
	}

	{
		std::vector<double> c;
		double sum = 0;
		for (double i = -412; i < 649; i += 13) { c.push_back(i); sum += i; }
		double meanRef = double(sum) / double(c.size());
		std::cout << "Mean of std::vector of double:" << std::endl;
		std::cout << "- Reference                 = " << meanRef << std::endl;
		++nb_test;
		{
			double mean = hnc::math::mean(c);
			std::cout << "- hnc::math::mean container = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef, "hnc::math::mean container == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef) + "\n");
		}
		++nb_test;
		{
			double mean = hnc::math::mean(c.begin(), c.end());
			std::cout << "- hnc::math::mean iterator  = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef, "hnc::math::mean iterator == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef) + "\n");
		}
	}

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::mean: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
