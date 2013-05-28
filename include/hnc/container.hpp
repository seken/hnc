// Copyright © 2013 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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


/**
 * @file
 * @brief Just for operator<<(std::ostream & o, hnc::container const & c)
 */

#ifndef HNC_CONTAINER_HPP
#define HNC_CONTAINER_HPP

#include <vector>

#include "ostream_std.hpp"


// Pre-declare hnc::container for operator<<
namespace hnc
{
	template <class T>
	class container;
}
// Declarate this function for hnc::container can be friend with
template <class T>
std::ostream & operator<<(std::ostream & o, hnc::container<T> const & c);


namespace hnc
{
	
	/**
	 * @brief Basic container (encapsulate std::vector)
	 * 
	 * @code
	 * #include <hnc/container.hpp>
	 * @endcode
	 *
	 * hnc::container is like std::vector (with less features) @n
	 * (You can create derivated class of hnc::container)
	 * 
	 * @note It is a (almost) useless class! Use std::vector instead.
	 */
	template <class T>
	class container
	{
	protected:

		/// Data
		std::vector<T> m_data;
		
	public:

		/// Iterator
		using iterator = typename std::vector<T>::iterator;
		/// Const iterator
		using const_iterator = typename std::vector<T>::const_iterator;

		/// Reverse iterator
		using reverse_iterator = typename std::vector<T>::reverse_iterator;
		/// Const reverse iterator
		using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

		/**
		 * @brief Constructor with size and default value
		 * @param[in] size          Number of element in the container
		 * @param[in] default_value default_value for the element of the container
		 */
		explicit container(std::size_t const size = 0, T const & default_value = T()) :
			m_data(size, default_value)
		{ }

		/**
		 * @brief Copy constructor
		 * @param[in] c A hnc::container<T>
		 */
		container(container<T> const & c) :
			m_data(c.m_data)
		{ }

		/**
		 * @brief Constructor with std::vector
		 * @param[in] v A std::vector<T>
		 */
		container(std::vector<T> const & v) :
			m_data(v)
		{ }

		/**
		 * @brief Constructor with std::initializer_list
		 * @param[in] il A std::initializer_list<T>
		 */
		container(std::initializer_list<T> const & il) :
			m_data(il)
		{ }

		/// Destructor
		virtual ~container() { }

		/**
		 * @brief Safe accces
		 * @param[in] i Index of the element
		 * @exception std::out_of_range if i is out of range
		 * @return the ith element
		 */
		T & at(std::size_t const i) { return m_data.at(i); }

		/**
		 * @brief Safe const accces
		 * @param[in] i Index of the element
		 * @exception std::out_of_range if i is out of range
		 * @return the ith const element
		 */
		T const & at(std::size_t const i) const { return m_data.at(i); }

		/**
		 * @brief Accces
		 * @param[in] i Index of the element
		 * @return the ith element
		 */
		T & operator[](std::size_t const i) { return m_data[i]; }

		/**
		 * @brief Const accces
		 * @param[in] i Index of the element
		 * @return the ith const element
		 */
		T const & operator[](std::size_t const i) const { return m_data[i]; }

		/**
		 * @brief Accces
		 * @param[in] i Index of the element
		 * @return the ith element
		 */
		T & operator()(std::size_t const i) { return m_data[i]; }

		/**
		 * @brief Const accces
		 * @param[in] i Index of the element
		 * @return the ith const element
		 */
		T const & operator()(std::size_t const i) const { return m_data[i]; }

		/**
		 * @brief Add an element to the container
		 * @param[in] e Element to be added in the container
		 */
		void push_back(T const & e) { m_data.push_back(e); }

		/**
		 * @brief Return the size of the container
		 * @return the size of the container
		 */
		std::size_t size() const { return m_data.size(); }

		/**
		 * @brief Return the first element
		 * @pre Container is not empty
		 * @return the first element
		 */
		T & front() { return m_data.front(); }

		/**
		 * @brief Return the first const element
		 * @pre Container is not empty
		 * @return the first const element
		 */
		T const & front() const { return m_data.front(); }

		/**
		 * @brief Return the last element
		 * @pre Container is not empty
		 * @return the last element
		 */
		T & back() { return m_data.back(); }

		/**
		 * @brief Return the last const element
		 * @pre Container is not empty
		 * @return the last const element
		 */
		T const & back() const { return m_data.back(); }

		/**
		 * @brief Compare the elements of two containers
		 * @return true if each element of the container are equals, else false
		 */
		bool operator==(container<T> const & c) const { return m_data == c.m_data; }

		/**
		 * @brief Return a iterator pointing to the first element
		 * @return a iterator pointing to the first element
		 */
		iterator begin() { return m_data.begin(); }

		/**
		 * @brief Return a const iterator pointing to the first element
		 * @return a const iterator pointing to the first element
		 */
		const_iterator begin() const { return m_data.begin(); }

		/**
		 * @brief Return a iterator referring to the past-the-end element
		 * @return a iterator referring to the past-the-end element
		 */
		iterator end() { return m_data.end(); }

		/**
		 * @brief Return a const iterator referring to the past-the-end element
		 * @return a const iterator referring to the past-the-end element
		 */
		const_iterator end() const { return m_data.end(); }

		/**
		 * @brief Return a reverse iterator pointing to the last element
		 * @return a reverse iterator pointing to the last element
		 */
		reverse_iterator rbegin() { return m_data.rbegin(); }

		/**
		 * @brief Return a const reverse iterator pointing to the last element
		 * @return a const reverse iterator pointing to the last element
		 */
		const_reverse_iterator rbegin() const { return m_data.rbegin(); }

		/**
		 * @brief Return a reverse iterator pointing to the element right before the first element
		 * @return a reverse iterator pointing to the element right before the first element
		 */
		reverse_iterator rend() { return m_data.rend(); }

		/**
		 * @brief Return a const reverse iterator pointing to the element right before the first element
		 * @return a const reverse iterator pointing to the element right before the first element
		 */
		const_reverse_iterator rend() const { return m_data.rend(); }

		/// Declare operator << with std::ostream as a friend
		friend std::ostream & operator<< <>(std::ostream & o, hnc::container<T> const & c);
	};
}

/**
 * @brief Display a hnc::container
 * 
 * @param[in,out] o Out stream
 * @param[in]     c A hnc::container
 * 
 * @return the out stream
 */
template <class T>
std::ostream & operator<<(std::ostream & o, hnc::container<T> const & c)
{
	o << c.m_data;
	return o;
}

#endif
