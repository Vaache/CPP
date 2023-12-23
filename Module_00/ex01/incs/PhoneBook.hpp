/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:16:09 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/23 21:38:59 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contac.hpp"

class PhoneBook
{
private:
		Contact a[8];
		bool 	pars_number(std::string _phone_number_);
		bool 	only_space(std::string _space_);
		void	pars_set_dot(std::string &s1, std::string s2);

public:
		void add(int i);
		void add_first_name(int i);
		void add_last_name(int i);
		void add_phone_number(int i);
		void search(int count);
};

#endif