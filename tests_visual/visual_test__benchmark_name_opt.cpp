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

	hnc::benchmark_name_opt b;

	b["Test 0"]["1"].start();
	b["Test 0"]["1"].stop();
	b["Test 0"]["2"].start();
	b["Test 0"]["2"].stop();
	b["Test 0"]["3"].start();
	b["Test 0"]["3"].stop();
	b["Test 0"]["4"].start();
	b["Test 0"]["4"].stop();

	b["Test 1"]["1"].push_back(1);
	b["Test 1"]["2"].push_back(1);
	b["Test 1"]["3"].push_back(1);
	b["Test 1"]["4"].push_back(1);

	b["Test 2"]["1"].push_back(4);
	b["Test 2"]["2"].push_back(3);
	b["Test 2"]["3"].push_back(2);
	b["Test 2"]["4"].push_back(1);
	// Copy paste
	b["Test 2"]["1"].push_back(4);
	b["Test 2"]["2"].push_back(3);
	b["Test 2"]["3"].push_back(2);
	b["Test 2"]["4"].push_back(1);

	// Display the benchmark
	std::cout << "Display the benchmark" << std::endl;
	std::cout << b << std::endl;

	hnc::test::warning(nb_test == 0, "hnc::benchmark_name_opt: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
