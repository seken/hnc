 -------------------------------
| hnc https://gitorious.org/hnc |
 -------------------------------

Basic (but useful) C++11 header-only library

Files can be under different licenses, see the header of a file to know its license and copyright.
List of the licenses actually used:
– Apache License, Version 2.0
– GNU Affero General Public License 3+


 ----------------------------
| System requirement for hnc |
 ----------------------------

hnc uses CMake build system.

The required packages are:
build-essential cmake git doxygen

The optional packages (but recommended) are:
libssl-dev gnuplot libboost-all-dev libboost-mpi-dev


 ---------------------
| Installation of hnc |
 ---------------------
 
With CMake
----------

Your C++ compiler must support common features of C++11
GCC 4.7 works (GCC 4.7.2 is in Debian Wheezy)

Use CMake to build hnc:
mkdir build
cd build
cmake .. #-DCMAKE_INSTALL_PREFIX=/path/to/install/hnc
make
# make doc
# make test
make install # su -c "make install" # sudo make install
 
Without CMake
-------------
 
hnc is an header-only library, you can copy the include directory in /usr/local or in your project.
