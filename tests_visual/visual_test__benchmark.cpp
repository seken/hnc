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

#include <hnc/benchmark.hpp>
#include <hnc/sleep.hpp>
#include <hnc/test.hpp>


int main()
{
	int nb_test = 0;

	hnc::benchmark b;

	b["Test 0"].start();
	b["Test 0"].stop();
	std::cout << "Test 0 took " << b["Test 0"].all.back() << " seconds (must be close to 0 second)" << std::endl;

	std::cout << std::endl;

	b["Test 1"].start();
	hnc::sleep::s(1);
	b["Test 1"].stop();
	std::cout << "Test 1 took " << b["Test 1"].all.back() << " seconds (must be close to 1 second)" << std::endl;

	std::cout << std::endl;

	b["Test 2"].start();
	hnc::sleep::ms(5);
	b["Test 2"].stop();
	for (unsigned int i = 0; i < 10; ++i)
	{
		b["Test 2"].start();
		hnc::sleep::ms(1);
		b["Test 2"].stop();
	}
	std::cout << "Test 2 have " << b["Test 2"].all.size() << " times (must be 11)" << std::endl;
	std::cout << "Test 2: last:   " << b["Test 2"].all.back() << " seconds (must be close to 0.005 second)" << std::endl;
	std::cout << "Test 2: min:    " << b["Test 2"].min() << " seconds (must be close to 0.001 second)" << std::endl;
	std::cout << "Test 2: max:    " << b["Test 2"].max() << " seconds (must be close to 0.005 second)" << std::endl;
	std::cout << "Test 2: mean:   " << b["Test 2"].mean() << " seconds (must be close to 0.0013 second)" << std::endl;
	std::cout << "Test 2: median: " << b["Test 2"].median() << " seconds (must be close to 0.0013 second)" << std::endl;
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 2"].all.size() == 11, "hnc::benchmark Test 2: must be have 11 times\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 2"].min() <= b["Test 2"].min(), "hnc::benchmark Test 2: min is not <= to max\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 2"].mean() >= b["Test 2"].min() && b["Test 2"].mean() <= b["Test 2"].max(), "hnc::benchmark Test 2: mean is not between min and max\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 2"].median() >= b["Test 2"].min() && b["Test 2"].median() <= b["Test 2"].max(), "hnc::benchmark Test 2: median is not between min and max\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 2"].all.back() >= b["Test 2"].min() && b["Test 2"].all.back() <= b["Test 2"].max(), "hnc::benchmark Test 2: last is not between min and max\n");

	std::cout << std::endl;

	b["Test 3"].push_back(20.);
	b["Test 3"].push_back(0.);
	b["Test 3"].push_back(1.);
	b["Test 3"].push_back(10.);
	b["Test 3"].push_back(1.);
	b["Test 3"].push_back(1.);
	std::cout << "Test 3 have " << b["Test 3"].all.size() << " times (must be 6)" << std::endl;
	std::cout << "Test 3: last:   " << b["Test 3"].all.back() << " seconds (must be 1.)" << std::endl;
	std::cout << "Test 3: min:    " << b["Test 3"].min() << " seconds (must be 0.)" << std::endl;
	std::cout << "Test 3: max:    " << b["Test 3"].max() << " seconds (must be 20.)" << std::endl;
	std::cout << "Test 3: mean:   " << b["Test 3"].mean() << " seconds (must be 5.5)" << std::endl;
	std::cout << "Test 3: median: " << b["Test 3"].median() << " seconds (must be 1)" << std::endl;
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].all.size() == 6, "hnc::benchmark Test 3: must be have 11 times\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].min() <= b["Test 3"].min(), "hnc::benchmark Test 3: min is not <= to max\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].mean() >= b["Test 3"].min() && b["Test 3"].mean() <= b["Test 3"].max(), "hnc::benchmark Test 3: mean is not between min and max\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].median() >= b["Test 3"].min() && b["Test 3"].median() <= b["Test 3"].max(), "hnc::benchmark Test 3: median is not between min and max\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].all.back() >= b["Test 3"].min() && b["Test 3"].all.back() <= b["Test 3"].max(), "hnc::benchmark Test 3: last is not between min and max\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].all.back() == 1., "hnc::benchmark Test 3: last is not 1.\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].min() == 0., "hnc::benchmark Test 3: min is not 0.\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].max() == 20., "hnc::benchmark Test 3: min is not 20.\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].mean() == 5.5, "hnc::benchmark Test 3: min is not 5.5\n");
	++nb_test;
	nb_test -= hnc::test::warning(b["Test 3"].median() == 1., "hnc::benchmark Test 3: min is not 1.\n");

	std::cout << std::endl;

	// Display the benchmark
	std::cout << "Display the benchmark" << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::benchmark: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
