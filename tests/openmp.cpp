// Copyright © 2012,2013 Lénaïc Bagnères, hnc@singularity.fr

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

#include <hnc/openmp.hpp>
#include <hnc/print.hpp>


int main()
{
	std::cout << "hnc::openmp::nb_thread_max() = " << hnc::openmp::nb_thread_max() << std::endl;
	std::cout << std::endl;
	
	#pragma omp parallel for
	for (std::size_t i = 0; i < 16; ++i)
	{
		hnc::print_mutex("Thread ", hnc::openmp::thread_id(), " / ", hnc::openmp::nb_thread_actual(), '\n');
	}
	
	return 0;
}
