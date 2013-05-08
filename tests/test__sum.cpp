// Copyright © 2012 Lénaïc Bagnères, hnc@singularity.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <iostream>
#include <vector>
#include <list>
#include <string>

#include <hnc/sum.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


int main()
{
	int nb_test = 0;

	{
		std::vector<int> c(0);
		int sumRef = 0;
		std::cout << "Sum of empty std::vector of int:" << std::endl;
		std::cout << "- Reference                = " << sumRef << std::endl;
		++nb_test;
		{
			int sum = hnc::sum(c);
			std::cout << "- hnc::sum container = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum container == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
		}
		++nb_test;
		{
			int sum = hnc::sum(c.begin(), c.end());
			std::cout << "- hnc::sum iterator  = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum iterator == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
		}
	}

	{
		std::list<int> c;
		int sumRef = 0;
		for (int v = -42; v < 543; v += 21) { c.push_back(v); sumRef += v; }
		std::cout << "Sum of std::list of int:" << std::endl;
		std::cout << "- Reference                = " << sumRef << std::endl;
		++nb_test;
		{
			int sum = hnc::sum(c);
			std::cout << "- hnc::sum container = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum container == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
		}
		++nb_test;
		{
			int sum = hnc::sum(c.begin(), c.end());
			std::cout << "- hnc::sum iterator  = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum iterator == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
		}
	}

	{
		std::vector<double> c;
		double sumRef = 0;
		for (int v = -42; v < 543; v += 21) { c.push_back(v / 11.); sumRef += v / 11.; }
		std::cout << "Sum of std::vector of double:" << std::endl;
		std::cout << "- Reference                = " << sumRef << std::endl;
		++nb_test;
		{
			double sum = hnc::sum(c);
			std::cout << "- hnc::sum container = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum container == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
		}
		++nb_test;
		{
			double sum = hnc::sum(c.begin(), c.end());
			std::cout << "- hnc::sum iterator  = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum iterator == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef) + "\n");
		}
	}

	{
		std::vector<int> c;
		int sumRef0 = 0;
		int sumRef1 = 0;
		for (int v = -42; v < 543; v += 21) { c.push_back(v); sumRef0 += v; }
		int separator = c.size();
		for (int v = -485; v < 427; v += 13) { c.push_back(v); sumRef1 += v; }
		std::cout << "Sum of partial std::vector of int:" << std::endl;
		++nb_test;
		{
			int sum = hnc::sum(c.begin(), c.begin() + separator);
			std::cout << "- [0 -> " << separator << "[. Reference                = " << sumRef0 << std::endl;
			std::cout << "- [0 -> " << separator << "[. hnc::sum iterator  = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef0, "hnc::sum iterator == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef0) + "\n");
		}
		++nb_test;
		{
			int sum = hnc::sum(c.begin() + separator, c.end());
			std::cout << "- [" << separator << ", end[. Reference                = " << sumRef1 << std::endl;
			std::cout << "- [" << separator << ", end[. hnc::sum iterator  = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef1, "hnc::sum iterator == " + hnc::to_string(sum) + " instead of " + hnc::to_string(sumRef1) + "\n");
		}
	}

	{
		std::list<std::string> c;
		c.push_back("It");
		c.push_back(" ");
		c.push_back("works");
		c.push_back("!");
		std::string sumRef = "It works!";
		std::cout << "Sum of std::list of std::string:" << std::endl;
		std::cout << "- Reference                = " << sumRef << std::endl;
		++nb_test;
		{
			std::string sum = hnc::sum(c);
			std::cout << "- hnc::sum container = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum container == " + sum + " instead of " + sumRef + "\n");
		}
		++nb_test;
		{
			std::string sum = hnc::sum(c.begin(), c.end());
			std::cout << "- hnc::sum iterator  = " << sum << std::endl;
			nb_test -= hnc::test::warning(sum == sumRef, "hnc::sum iterator == " + sum + " instead of " + sumRef + "\n");
		}
	}

	hnc::test::warning(nb_test == 0, "hnc::sum: " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
