/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:33:06 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/09 17:34:34 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(){}
Base::~Base(){ /*std::cout << "Destructor Base" << std::endl;*/ }

A::A(){}
A::~A(){ /*std::cout << "Destructor A" << std::endl;*/ }

B::B(){}
B::~B(){ /*std::cout << "Destructor B" << std::endl;*/ }

C::C(){}
C::~C(){ /*std::cout << "Destructor C" << std::endl;*/ }

Base* generate()
{
	int randomClass = 'A' + std::rand() % ('C' - 'A' + 1);
	if (static_cast<char>(randomClass) == 'A')
	{
		A *ptr = new A;
		return dynamic_cast<Base*>(ptr);
	}
	if (static_cast<char>(randomClass) == 'B')
	{
		B *ptr = new B;
		return dynamic_cast<Base*>(ptr);
	}
	if (static_cast<char>(randomClass) == 'C')
	{
		C *ptr = new C;
		return dynamic_cast<Base*>(ptr);
	}
	return NULL;
}

void identify(Base* p)
{
	A *objA = dynamic_cast<A*>(p);
	B *objB = dynamic_cast<B*>(p);
	C *objC = dynamic_cast<C*>(p);
	if (objA)
		std::cout << "The actual type of the object pointed to by p: A" << std::endl;
	else if (objB)
		std::cout << "The actual type of the object pointed to by p: B" << std::endl;
	else if (objC)
		std::cout << "The actual type of the object pointed to by p: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &objA = dynamic_cast<A&>(p);
		(void)objA;
		std::cout << "The actual type of the object that p refers to: A" << std::endl;
	}
	catch(...)
	{
		try
		{
			B &objB = dynamic_cast<B&>(p);
			(void)objB;
			std::cout << "The actual type of the object that p refers to: B" << std::endl;
		}
		catch(...)
		{
			try
			{
				C &objC = dynamic_cast<C&>(p);
				(void)objC;
				std::cout << "The actual type of the object that p refers to: C" << std::endl;
			}
			catch(...)
			{}
		}
	}
}
