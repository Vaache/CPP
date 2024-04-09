/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:15:29 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/09 17:19:37 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime> 

class Base
{
public:
	Base();
	virtual ~Base();
};

class A : public Base
{
public:
	A();
	~A();
};

class B : public Base
{
public:
	B();
	~B();
};

class C : public Base
{
public:
	C();
	~C();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif