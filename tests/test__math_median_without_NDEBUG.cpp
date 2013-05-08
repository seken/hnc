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
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

#include <hnc/math/median.hpp>
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
		std::cout << "Median of empty std::vector of int:" << std::endl;
		++nb_test;
		{
			try
			{
				int median = hnc::math::median(c);
				hnc::test::warning(false, "hnc::math::median container does not throw exception with empty container, median = " + hnc::to_string(median) + "\n");
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
				int median = hnc::math::median(c.begin(), c.end());
				hnc::test::warning(false, "hnc::math::median iterator does not throw exception with empty container, median = " + hnc::to_string(median) + "\n");
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
		c.push_back(48);
		int medianRef = 48;
		std::cout << "Mean of std::list of one int:" << std::endl;
		std::cout << "- Reference                   = " << medianRef << std::endl;
		++nb_test;
		{
			int median = hnc::math::median(c);
			std::cout << "- hnc::math::median container = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median container == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
		++nb_test;
		{
			int median = hnc::math::median(c.begin(), c.end());
			std::cout << "- hnc::math::median iterator  = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median iterator == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
	}

	{
		std::vector<double> c;
		c.push_back(100.);
		c.push_back(50.);
		double medianRef = 75.;
		std::cout << "Mean of std::list of two double:" << std::endl;
		std::cout << "- Reference                   = " << medianRef << std::endl;
		++nb_test;
		{
			double median = hnc::math::median(c);
			std::cout << "- hnc::math::median container = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median container == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
		++nb_test;
		{
			double median = hnc::math::median(c.begin(), c.end());
			std::cout << "- hnc::math::median iterator  = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median iterator == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
	}

	{
		std::vector<int> c({-45, -98, -45, 45, 6, 10, 96});
		int medianRef = 6;
		std::cout << "Mean of std::list of one int:" << std::endl;
		std::cout << "- Reference                   = " << medianRef << std::endl;
		++nb_test;
		{
			int median = hnc::math::median(c);
			std::cout << "- hnc::math::median container = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median container == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
		++nb_test;
		{
			int median = hnc::math::median(c.begin(), c.end());
			std::cout << "- hnc::math::median iterator  = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median iterator == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
	}

	{
		std::vector<int> c({-45, -98, -45, 45, 6, 10});
		int medianRef = -19;
		std::cout << "Mean of std::list of one int:" << std::endl;
		std::cout << "- Reference                   = " << medianRef << std::endl;
		++nb_test;
		{
			int median = hnc::math::median(c);
			std::cout << "- hnc::math::median container = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median container == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
		++nb_test;
		{
			int median = hnc::math::median(c.begin(), c.end());
			std::cout << "- hnc::math::median iterator  = " << median << std::endl;
			nb_test -= hnc::test::warning(median == medianRef, "hnc::math::median iterator == " + hnc::to_string(median) + " instead of " + hnc::to_string(medianRef) + "\n");
		}
	}

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::median: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
