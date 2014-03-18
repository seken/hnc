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
#include <vector>
#include <list>

#include <hnc/math/standard_deviation.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	{
		std::list<int> c({2, 4, 4, 4, 5, 5, 7, 9}); // mean = 5
		double standard_deviation_ref = 2;
		std::cout << "Standard deviation of std::list of int:" << std::endl;
		std::cout << "- Reference                               = " << standard_deviation_ref << std::endl;
		++nb_test;
		{
			double standard_deviation = hnc::math::standard_deviation(c);
			std::cout << "- hnc::math::standard_deviation container = " << standard_deviation << std::endl;
			nb_test -= hnc::test::warning(standard_deviation == standard_deviation_ref, "hnc::math::standard_deviation container == " + hnc::to_string(standard_deviation) + " instead of " + hnc::to_string(standard_deviation_ref) + "\n");
		}
		++nb_test;
		{
			double standard_deviation = hnc::math::standard_deviation(c.begin(), c.end());
			std::cout << "- hnc::math::standard_deviation iterator  = " << standard_deviation << std::endl;
			nb_test -= hnc::test::warning(standard_deviation == standard_deviation_ref, "hnc::math::standard_deviation iterator == " + hnc::to_string(standard_deviation) + " instead of " + hnc::to_string(standard_deviation_ref) + "\n");
		}
	}

	hnc::test::warning(nb_test == 0, "hnc::math::standard_deviation: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
