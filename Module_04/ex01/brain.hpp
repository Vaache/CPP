/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:57:54 by vhovhann          #+#    #+#             */
/*   Updated: 2024/02/18 18:13:29 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string idea[100];

public:
	Brain();
	Brain(const Brain &other);
	~Brain();
	Brain& operator =(const Brain &other);
	
	void	setIdea(std::string &idea, const int Index);
	std::string getIdea(const int Index);
};

#endif