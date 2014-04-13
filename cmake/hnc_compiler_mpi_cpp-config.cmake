# Copyright © 2014 Lénaïc Bagnères, hnc@singularity.fr

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


# Find MPI C++ Compiler

# HNC_COMPILER_MPI_CPP - MPI C++ Compiler executable (false if not found)
# HNC_MPIRUN_EXE       - MPI run executable (false if not found)


find_program(HNC_COMPILER_MPI_CPP NAMES mpic++ mpicxx mpiCC mpicc)

if (HNC_COMPILER_MPI_CPP)
	
	message(STATUS "MPI C++ Compiler found =) ${HNC_COMPILER_MPI_CPP}")
	
else()
	
	message(STATUS "MPI C++ Compiler not found :(")
	
endif()


find_program(HNC_MPIRUN_EXE NAMES mpirun)

if (HNC_MPIRUN_EXE)
	
	message(STATUS "MPI run executable found =) ${HNC_MPIRUN_EXE}")
	
else()
	
	message(STATUS "MPI run executable not found :(")
	
endif()
