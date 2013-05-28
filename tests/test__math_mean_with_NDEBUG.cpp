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


#if !defined(NDEBUG)
	#define NDEBUG
#endif

#include <iostream>
#include <string>
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
		--nb_test;
	#else
		std::cout << "Without NDEBUG" << std::endl;
	#endif

	{
		std::vector<double> c(0);
		std::cout << "Mean of empty std::vector of int:" << std::endl;
		++nb_test;
		{
			try
			{
				double mean = hnc::math::mean(c);
				std::cout << "- " << mean << std::endl;
				--nb_test;
			}
			catch (std::exception const & e)
			{
				hnc::test::warning(false, std::string(e.what()) + "\n");
			}
		}
		++nb_test;
		{
			try
			{
				double mean = hnc::math::mean(c.begin(), c.end());
				std::cout << "- " << mean << std::endl;
				--nb_test;
			}
			catch (std::exception const & e)
			{
				hnc::test::warning(false, std::string(e.what()) + "\n");
			}
		}
	}

	{
		std::list<int> c;
		c.push_back(48);
		double meanRef = 48;
		std::cout << "Mean of std::list of one int:" << std::endl;
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

	{
		std::list<int> c;
		c.push_back(478);
		c.push_back(12);
		double meanRef = 245;
		std::cout << "Mean of std::list of two int:" << std::endl;
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

	{
		std::vector<double> c;
		double sum = 0;
		for (int i = -14; i < 741; i += 78) { c.push_back(i); sum += i; }
		double meanRef = sum / c.size();
		std::cout << "Mean of std::vector of int:" << std::endl;
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

	{
		std::vector<double> c;
		std::size_t size = 0;
		double sum0 = 0;
		for (int i = 57; i < 47825; i += 145) { c.push_back(i); sum0 += i; ++size; }
		double meanRef0 = sum0 / size;
		double sum1 = 0;
		for (int i = -475; i < 41; i += 7) { c.push_back(i); sum1 += i; }
		double meanRef1 = sum1 / (c.size() - size);
		std::cout << "Partial mean of std::vector of int:" << std::endl;
		++nb_test;
		{
			std::cout << "- Reference                 = " << meanRef0 << std::endl;
			double mean = hnc::math::mean(c.begin(), c.begin() + size);
			std::cout << "- hnc::math::mean iterator  = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef0, "hnc::math::mean iterator == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef0) + "\n");
		}
		++nb_test;
		{
			std::cout << "- Reference                 = " << meanRef1 << std::endl;
			double mean = hnc::math::mean(c.begin() + size, c.end());
			std::cout << "- hnc::math::mean iterator  = " << mean << std::endl;
			nb_test -= hnc::test::warning(mean == meanRef1, "hnc::math::mean iterator == " + hnc::to_string(mean) + " instead of " + hnc::to_string(meanRef1) + "\n");
		}
	}

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::mean: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
