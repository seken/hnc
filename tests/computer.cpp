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

#include <hnc/computer.hpp>


int main()
{
	std::cout << "Computer system name    = " << hnc::computer::system_name() << std::endl;
	std::cout << "Computer system version = " << hnc::computer::system_version() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Processor name = " << hnc::computer::processor_name() << std::endl;
	std::cout << std::endl;

	return 0;
}
