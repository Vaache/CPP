/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contac.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:16:06 by vhovhann          #+#    #+#             */
/*   Updated: 2023/12/23 21:27:01 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
		std::string _first_name_;
		std::string _last_name_;
		std::string _phone_number_;
		std::string _nickname_;
		std::string _darkest_secret_;

public:
		void	set_first_name(std::string _first_name_);
		void	set_last_name(std::string _last_name_);
		void	set_nickname(std::string _nickname_);
		void	set_phone_number(std::string _phone_number_);
		void	set_darkest_secret(std::string _darkest_secret_);

		std::string get_firs_name(void);
		std::string get_last_name(void);
		std::string get_nickname(void);
		std::string get_phone_number(void);
		std::string get_darkest_secret(void);
};

#endif