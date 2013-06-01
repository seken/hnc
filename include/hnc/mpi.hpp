// Copyright © 2013 Lénaïc Bagnères, hnc@singularity.fr

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
	 * #include <hnc/mpi.hpp>
	 * @endcode
	 *
	 * @b From @b Wikipedia http://en.wikipedia.org/wiki/Message_Passing_Interface @n
	 * Message Passing Interface (MPI) is a standardized and portable message-passing system designed by a group of researchers from academia and industry to function on a wide variety of parallel computers. The standard defines the syntax and semantics of a core of library routines useful to a wide range of users writing portable message-passing programs in Fortran 77 or the C programming language. Several well-tested and efficient implementations of MPI include some that are free and in the public domain. These fostered the development of a parallel software industry, and there encouraged development of portable and scalable large-scale parallel applications.
	 *
	 * With MPI you can write distributed program to:
	 * - increase performances
	 * - solve a bigger problem who can do with only one computer
	 */
	namespace mpi
	{
		// For Doxygen only
	}
}

#endif
