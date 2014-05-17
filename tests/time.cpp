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

#include <hnc/time.hpp>


int main()
{
	std::cout << "Time point in hours        = " << hnc::time::h() << std::endl;
	std::cout << "Time point in minutes      = " << hnc::time::min() << std::endl;
	std::cout << "Time point in second       = " << hnc::time::s() << std::endl;
	std::cout << "Time point in milliseconds = " << hnc::time::ms() << std::endl;
	std::cout << "Time point in microseconds = " << hnc::time::us() << std::endl;
	std::cout << "Time point in nanoseconds  = " << hnc::time::ns() << std::endl;

	return 0;
}
