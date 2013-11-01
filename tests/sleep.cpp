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

#include <hnc/sleep.hpp>


int main()
{
	std::cout << "Sleep for 0 nanosecond" << std::endl;
	hnc::sleep::ns(0);

	std::cout << "Sleep for 0 microsecond" << std::endl;
	hnc::sleep::us(0);

	std::cout << "Sleep for 0 millisecond" << std::endl;
	hnc::sleep::ms(0);

	std::cout << "Sleep for 0 second" << std::endl;
	hnc::sleep::s(0);

	std::cout << "Sleep for 0 minute" << std::endl;
	hnc::sleep::min(0);

	std::cout << "Sleep for 0 hour" << std::endl;
	hnc::sleep::h(0);


	std::cout << "Sleep for 1000 x 1000 x 1000 nanoseconds" << std::endl;
	hnc::sleep::ns(1000 * 1000 * 1000);

	std::cout << "Sleep for 1000 x 1000 microseconds" << std::endl;
	hnc::sleep::us(1000 * 1000);

	std::cout << "Sleep for 1000 milliseconds" << std::endl;
	hnc::sleep::ms(1000);

	std::cout << "Sleep for 1 second" << std::endl;
	hnc::sleep::s(1);

// 	std::cout << "Sleep for 1 minute" << std::endl;
// 	hnc::sleep::min(1);

// 	std::cout << "Sleep for 1 hour" << std::endl;
// 	hnc::sleep::h(1);

	return 0;
}
