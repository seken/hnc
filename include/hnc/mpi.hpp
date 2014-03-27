// Copyright © 2013, 2014 Lénaïc Bagnères, hnc@singularity.fr

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


#ifndef HNC_MPI_HPP
#define HNC_MPI_HPP


#include "mpi/future.hpp"


namespace hnc
{
	/**
	 * @brief MPI (Message Passing Interface) functions
	 *
	 * @code
	   #include <hnc/mpi.hpp>
	   @endcode
	 *
	 * With MPI you can write distributed program to:
	 * - increase performances
	 * - solve a bigger problem who can do with only one computer
	 *
	 * @b From @b Wikipedia http://en.wikipedia.org/wiki/Message_Passing_Interface @n
	 * Message Passing Interface (MPI) is a standardized and portable message-passing system designed by a group of researchers from academia and industry to function on a wide variety of parallel computers. The standard defines the syntax and semantics of a core of library routines useful to a wide range of users writing portable message-passing programs in Fortran 77 or the C programming language. Several well-tested and efficient implementations of MPI include some that are free and in the public domain. These fostered the development of a parallel software industry, and there encouraged development of portable and scalable large-scale parallel applications.
	 *
	 * To use MPI code, you need Boost.MPI and Boost.Serialization @n
	 * You can add this in your CMakeLists.txt
	 * @code
	   find_package(Boost COMPONENTS mpi serialization)
	   if (Boost_FOUND)
	   	# Boost.MPI and Boost.Serialization
	   	set(boost_mpi_serialization "${Boost_LIBRARIES}")
	   	message(STATUS "Boost.MPI and Boost.Serialization found :) ${boost_mpi_serialization}")
	   	# MPI compiler
	   	find_program(MPICXX_COMPILER NAMES mpic++ mpicxx mpiCC mpicc)
	   	if (MPICXX_COMPILER)
	   		# Change the compiler
	   		message(STATUS "MPI C++ compiler found = ${MPICXX_COMPILER}")
	   		set(CMAKE_CXX_COMPILER ${MPICXX_COMPILER})
	   	else()
	   		message(STATUS "MPI C++ compiler not found :(")
	   	endif()
	   	# MPI run
	   	find_program(MPIRUN_EXE NAMES mpirun)
	   	if (MPIRUN_EXE)
	   		message(STATUS "mpirun executable found = ${MPIRUN_EXE}")
	   	else()
	   		message(STATUS "mpirun executable not found :(")
	   	endif()
	   else()
	   	message(STATUS "Boost.MPI and Boost.Serialization not found :(")
	   endif()
	   
	   # ...
	  
	   # Create the executable
	   add_executable(your_exe your_exe.cpp)
	   target_link_libraries(your_exe ${boost_mpi_serialization})
	   @endcode
	 * 
	 * For quick test, if you use GCC from the command line and Boost is installed, you can link directly with:
	 * @code
	   -lboost_mpi -lboost_serialization
	   @endcode
	 *
	 * On Debian GNU/Linux distribution you can install the packages:
	 * @code
	   openmpi-bin openmpi-dev libboost-serialization-dev libboost-mpi-dev
	   @endcode
	 *
	 * To run a program with MPI, run your program with:
	 * @code
	   mpirun -np number_of_processors your_exe
	   @endcode
	 * 
	 * If you want compile without Boost.MPI, you can define the macro
	 * @code
	   #define NO_HNC_Boost_MPI
	   @endcode
	 */
	namespace mpi
	{
		// For Doxygen only
	}
}

#endif
