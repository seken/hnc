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


#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

#include <hnc/math/nth_root.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	std::cout.precision(std::numeric_limits<double>::digits10+1);

	// a == 0

	++nb_test;
	{
		unsigned int const n = 2;
		int a = 0;
		int r = int(hnc::math::nth_root(a, n));
		int ref = 0;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 3;
		float a = 0;
		float r = hnc::math::nth_root(a, n);
		float ref = 0;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 4;
		double a = 0;
		double r = hnc::math::nth_root(a, n);
		double ref = 0;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 0

	++nb_test;
	{
		unsigned int const n = 0;
		int a = 5498654;
		int r = int(hnc::math::nth_root(a, n));
		int ref = 1;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 0;
		float a = 564968.849f;
		float r = hnc::math::nth_root(a, n);
		float ref = 1;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 0;
		double a = 849.85435616;
		double r = hnc::math::nth_root(a, n);
		double ref = 1;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 1

	++nb_test;
	{
		unsigned int const n = 1;
		int a = 785785;
		int r = int(hnc::math::nth_root(a, n));
		int ref = a;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 1;
		float a = 785.875785f;
		float r = hnc::math::nth_root(a, n);
		float ref = a;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 1;
		double a = 8686.86785785;
		double r = hnc::math::nth_root(a, n);
		double ref = a;
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 2

	++nb_test;
	{
		unsigned int const n = 2;
		int a = 5875;
		int r = int(hnc::math::nth_root(a, n));
		int ref = int(std::sqrt(a));
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 2;
		float a = 785785.58f;
		float r = hnc::math::nth_root(a, n);
		float ref = std::sqrt(a);
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 2;
		double a = 785.85785785;
		double r = hnc::math::nth_root(a, n);
		double ref = std::sqrt(a);
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 3

	++nb_test;
	{
		unsigned int const n = 3;
		int a = 85785;
		int r = int(hnc::math::nth_root(a, n));
		int ref = int(std::cbrt(a));
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 3;
		float a = 5237877.58f;
		float r = hnc::math::nth_root(a, n);
		float ref = std::cbrt(a);
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 3;
		double a = 785785.78578532788;
		double r = hnc::math::nth_root(a, n);
		double ref = std::cbrt(a);
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 3

	++nb_test;
	{
		unsigned int const n = 3;
		int a = 85785;
		int r = int(hnc::math::nth_root(a, n));
		int ref = int(std::cbrt(a));
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 3;
		float a = 5237877.58f;
		float r = hnc::math::nth_root(a, n);
		float ref = std::cbrt(a);
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 3;
		double a = 785785.78578532788;
		double r = hnc::math::nth_root(a, n);
		double ref = std::cbrt(a);
		nb_test -= hnc::test::warning(r == ref, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " = " + hnc::to_string(r) + " instead of " + hnc::to_string(ref) + "\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 4

	++nb_test;
	{
		unsigned int const n = 4;
		int a = 6561;
		int r = int(hnc::math::nth_root(a, n));
		nb_test -= hnc::test::warning(std::pow(r, n) == a, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 4;
		float a = 785785.58f;
		float r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.2, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 4;
		double a = 785.85785785;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 5

	++nb_test;
	{
		unsigned int const n = 5;
		int a = 1048576;
		int r = int(hnc::math::nth_root(a, n));
		nb_test -= hnc::test::warning(std::pow(r, n) == a, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 5;
		float a = 785.875785f;
		float r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 5;
		double a = 8686.86785785;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// n == 6

	++nb_test;
	{
		unsigned int const n = 6;
		int a = 1771561;
		int r = int(hnc::math::nth_root(a, n));
		nb_test -= hnc::test::warning(std::pow(r, n) == a, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 6;
		float a = 5785.78585f;
		float r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 6;
		double a = 849.85435616;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// Little double

	++nb_test;
	{
		unsigned int const n = 6;
		double a = 0.00000085435616;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 7;
		double a = 0.00000085435616;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 8;
		double a = 0.00000085435616;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 9;
		double a = 0.00000085435616;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 10;
		double a = 0.00000085435616;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	++nb_test;
	{
		unsigned int const n = 11;
		double a = 0.00506 * 0.001059 * 0.001058 * 0.001057 * 0.001056 * 0.001057 * 0.001056 * 0.001057 * 0.001057 * 0.001056 * 0.001056;
		double r = hnc::math::nth_root(a, n);
		nb_test -= hnc::test::warning(std::abs(std::pow(r, n) - a) <= 0.1, hnc::to_string(n) + "th root of " + hnc::to_string(a) + " is not " + hnc::to_string(r) + " (" + hnc::to_string(r) + "^" + hnc::to_string(n) + " = " + hnc::to_string(std::pow(r, n)) + " != " + hnc::to_string(a) + ")\n");
		std::cout << n << "th root of " << a << " = " << r << std::endl;
	}

	std::cout << std::endl;

	// Exception

	++nb_test;
	{
		try
		{
			unsigned int n = 4;
			double a = -256;
			double r = hnc::math::nth_root(a, n);
			std::cout << n << "th root of " << a << " = " << r << std::endl;
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
			unsigned int n = 5;
			double a = -1024;
			double r = hnc::math::nth_root(a, n);
			std::cout << n << "th root of " << a << " = " << r << std::endl;
			--nb_test;
		}
		catch (std::exception const & e)
		{
			hnc::test::warning(false, std::string(e.what()) + "\n");
		}
	}

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::math::nth_root: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
