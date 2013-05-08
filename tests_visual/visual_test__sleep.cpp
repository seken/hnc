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
	std::cout << "Sleep for 100 * 1000 * 1000 nanoseconds (100 milliseconds)" << std::endl;
	hnc::sleep::ns(100 * 1000 * 1000);

	std::cout << "Sleep for 100 * 1000 microseconds (100 milliseconds)" << std::endl;
	hnc::sleep::us(100 * 1000);

	std::cout << "Sleep for 100 milliseconds" << std::endl;
	hnc::sleep::ms(100);

	std::cout << "Sleep for 1 second" << std::endl;
	hnc::sleep::s(1);

	std::cout << "Sleep for 0 minute" << std::endl;
	hnc::sleep::min(0);

	std::cout << "Sleep for 0 hour" << std::endl;
	hnc::sleep::h(0);

	return 0;
}
