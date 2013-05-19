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

#include <hnc/math/pi.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;
	
	std::string const ref_pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
		std::cout << "Reference pi         = " << ref_pi << std::endl;

	++nb_test;
	{
		std::string const pi = hnc::to_string(hnc::math::pi());
		std::cout << "hnc::math::pi        = " << pi << std::endl;
		nb_test -= hnc::test::warning(pi.substr(0, pi.size() - 1) == ref_pi.substr(0, pi.size() - 1), "hnc::math::pi == " + pi + " instead of " + ref_pi.substr(0, pi.size() - 1) + "\n");
	}

	++nb_test;
	{
		std::string const pi = hnc::to_string(hnc::math::pi<float>());
		std::cout << "hnc::math::pi<float> = " << pi << std::endl;
		nb_test -= hnc::test::warning(pi.substr(0, pi.size() - 1) == ref_pi.substr(0, pi.size() - 1), "hnc::math::pi == " + pi + " instead of " + ref_pi.substr(0, pi.size() - 1) + "\n");
	}

	hnc::test::warning(nb_test == 0, "hnc::math::pi: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
