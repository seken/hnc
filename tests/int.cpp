// Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

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

#include <hnc/int.hpp>
#include <hnc/test.hpp>
#include <hnc/to_string.hpp>


struct int8
{
	signed char i:8;
};

struct uint8
{
	unsigned char i:8;
};


template <int bits, class hnc_int_t, class struct_int_t, class struct_i_t>
int test_int()
{
	std::cout << "Test hnc::[u]int" << bits << std::endl;
	
	int nb_test = 0;
	
	for (int i = -256; i <= 256; ++i)
	{
		// Constructor
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		
		// +
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			h += 10;
			s.i = struct_i_t(s.i + 10);
			
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			if (++h != ++s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			if (h++ != s.i++)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		
		// -
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			h -= 10;
			s.i = struct_i_t(s.i - 10);
			
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			if (--h != --s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			if (h-- != s.i--)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		
		// *
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			h *= 10;
			s.i = struct_i_t(s.i * 10);
			
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
		
		// /
		{
			struct_int_t s; s.i = struct_i_t(i);
			hnc_int_t h(i);
			
			h /= 10;
			s.i = struct_i_t(s.i / 10);
			
			if (h != s.i)
			{
				++nb_test;
				std::cout << "i = " << i << " | h = " << h << " | s = " << s.i << std::endl;
			}
		}
	}
	
	return nb_test;
}

int main()
{
	int nb_test = 0;

	nb_test += test_int<8, hnc::int8, int8, signed char>();
	hnc::test::warning(nb_test == 0, "hnc::int8 fails!\n");

	nb_test += test_int<8, hnc::uint8, uint8, unsigned char>();
	hnc::test::warning(nb_test == 0, "hnc::uint8 fails!\n");
	
	hnc::test::warning(nb_test == 0, "hnc::int " + hnc::to_string(nb_test) + " test fail!\n");

	return nb_test;
}
