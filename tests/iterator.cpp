// Copyright © 2013 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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
#include <iterator>

#include <hnc/iterator.hpp>
#include <hnc/container.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


template <class const_random_iterator>
unsigned int test_const_it(const_random_iterator a)
{
	unsigned int nb_test_fail = 0;
	
	// All categories

	// Can be copied and copy-constructed
	// X b(a);
	// b = a;

	const_random_iterator b(a);
	b = a;
	
	// -> Copy constructor and affectation operator are by default

	// Can be incremented
	// ++a
	// a++
	// *a++

	++b;
	b++;

	// Input

	// Accepts equality/inequality comparisons
	// a == b
	// a != b

	if (a == b) { ++nb_test_fail; }
	if (a != a) { ++nb_test_fail; }
	if (a != const_random_iterator(a)) { ++nb_test_fail; }

	// Can be dereferenced as an rvalue
	// *a
	// a->m

	typename const_random_iterator::value_type val = *a;
	std::cout << "Display *a = " << val << ", and b with -> " << *(b.operator ->()) << std::endl;

	// Output

	// Can be dereferenced to be the left side of an assignment operation
	// *a = t
	// *a++ = t

	// -> No with const iterator

	// Forward

	// Can be default-constructed
	// X a;
	// X()

	const_random_iterator c;
	c = const_random_iterator();

	// Bidirectional

	// Can be decremented
	// --a
	// a--
	// *a--

	--b;
	b--;
	if (a != b) { ++nb_test_fail; }

	// Random Access

	// Supports arithmetic operators + and -
	// a + n
	// n + a
	// a - n
	// a - b

	if ((a + 2) != (a + 4 - 2)) { ++nb_test_fail; }

	if (b != (b + std::size_t(a - a))) { ++nb_test_fail; }
	
	// Supports inequality comparisons (<, >, <= and >=) between iterators
	// a < b
	// a > b
	// a <= b
	// a >= b
	
	if (a < b) { ++nb_test_fail; }
	if (a > b) { ++nb_test_fail; }

	if ((a <= b) == false) { ++nb_test_fail; }
	if ((a >= b) == false) { ++nb_test_fail; }

	++b;

	if (a > b) { ++nb_test_fail; }
	if (b < a) { ++nb_test_fail; }

	// Supports compound assignment operations += and -=
	// a += n
	// a -= n

	a += 1;

	if (a != b) { ++nb_test_fail; }

	b += 3;
	b -= 2;
	b -= 1;

	if (a != b) { ++nb_test_fail; }

	// Supports offset dereference operator ([])
	// a[n]

	a += 2;

	if (a[0] != b[2]) { ++nb_test_fail; }
	
	return nb_test_fail;
}

template <class random_iterator>
unsigned int test_it(random_iterator a)
{
	unsigned int nb_test_fail = 0;

	nb_test_fail += test_const_it(a);

	// Can be dereferenced to be the left side of an assignment operation
	// *a = t
	// *a++ = t

	random_iterator b = a + 1;

	*a = *b; if (*a != *b) { ++nb_test_fail; }

	return nb_test_fail;
}

int main()
{
	int nb_test = 0;

	{
		hnc::container<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21});
		nb_test += int(test_it(hnc::iterator<int, hnc::container<int>>(c, 9)));
		hnc::test::warning(nb_test == 0, "After hnc::iterator, " + hnc::to_string(nb_test) + " test fail!\n");
		std::cout << std::endl;
	}

	{
		hnc::container<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21});
		nb_test += int(test_const_it(hnc::const_iterator<int, hnc::container<int>>(c, 9)));
		hnc::test::warning(nb_test == 0, "After hnc::const_iterator, " + hnc::to_string(nb_test) + " test fail!\n");
		std::cout << std::endl;
	}

	{
		hnc::container<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21});
		nb_test += int(test_it(hnc::reverse_iterator<int, hnc::container<int>>(c, 9)));
		hnc::test::warning(nb_test == 0, "After hnc::reverse_iterator, " + hnc::to_string(nb_test) + " test fail!\n");
		std::cout << std::endl;
	}

	{
		hnc::container<int> c({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21});
		nb_test += int(test_const_it(hnc::const_reverse_iterator<int, hnc::container<int>>(c, 9)));
		hnc::test::warning(nb_test == 0, "After hnc::const_reverse_iterator, " + hnc::to_string(nb_test) + " test fail!\n");
		std::cout << std::endl;
	}
	
	hnc::test::warning(nb_test == 0, "hnc::iterator " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
