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

#include <hnc/math/variance.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	{
		std::list<int> c({2, 4, 6, 8}); // mean = 5
		double varianceRef = 5; // mean((2 - 5)², (4 - 5)², (6 - 5)², (8 - 5)²) = mean(9, 1, 1, 9) = 5
		std::cout << "Sum of std::list of int:" << std::endl;
		std::cout << "- Reference                     = " << varianceRef << std::endl;
		++nb_test;
		{
			double variance = hnc::math::variance(c);
			std::cout << "- hnc::math::variance container = " << variance << std::endl;
			nb_test -= hnc::test::warning(variance == varianceRef, "hnc::math::variance container == " + hnc::to_string(variance) + " instead of " + hnc::to_string(varianceRef) + "\n");
		}
		++nb_test;
		{
			double variance = hnc::math::variance(c.begin(), c.end());
			std::cout << "- hnc::math::variance iterator  = " << variance << std::endl;
			nb_test -= hnc::test::warning(variance == varianceRef, "hnc::math::variance iterator == " + hnc::to_string(variance) + " instead of " + hnc::to_string(varianceRef) + "\n");
		}
	}

	hnc::test::warning(nb_test == 0, "hnc::math::variance: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
