/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:24:40 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/11 21:21:25 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
	class Array
	{
	private:
		size_t len;
		T *elem;
	public:
		Array():len(0),elem(NULL)
		{}
		Array(unsigned int n)
		{
			this->elem = new T[n];
			this->len = n;
			for (size_t i = 0; i < this->len; ++ i)
				this->elem[i] = 0;
		}
		Array(const Array<T> &other)
		{
			this->elem = new T[other.len];
			this->len = other.len;
			for (size_t i = 0; i < other.len; ++ i)
				this->elem[i] = other.elem[i];
		}
		Array<T>& operator =(const Array<T> &other)
		{
			if (this == &other)
				return *this;
			if (this->elem)
				delete this->elem;
			this->elem = new T[other.len];
			this->len = other.len;
			for (size_t i = 0; i < this->len; ++ i)
				this->elem[i] = other.elem[i];
			return *this;
		}
		T& operator[](const size_t index) 
		{
			if (index >= this->len)
				throw ExpHandler();
			return this->elem[index];
		}
		const T& operator[](const size_t index) const
		{
			if (index >= this->len)
				throw ExpHandler();
			return this->elem[index];
		}
		~Array()
		{
			if (this->elem)
				delete this->elem;
		}
		class ExpHandler : public std::exception
		{
		public:
			const char *what() const throw()
			{
				return "Out of range in Array";
			}
		};
		size_t size() const
			{ return this->len; }
	};

#endif