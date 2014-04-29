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

#include <hnc/hnc.hpp>


int main()
{
	std::cout << "Just test hnc/ hnc.hpp include" << std::endl;
	std::cout << "hnc version  = " << hnc::version() << std::endl;
	std::cout << "hnc codename = " << hnc::codename() << std::endl;

	return 0;
}
