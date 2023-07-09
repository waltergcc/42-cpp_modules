/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:50:26 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/09 09:13:40 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdio>
# include <iomanip>
# include <cstdlib>

# define CLEAR "\033c"
# define NO 0
# define YES 1

class	Contact
{
	public:
	
		Contact(void);
		~Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string secret);
		void				displayContact(void);
		std::string			getFirstName(void);
		std::string			getLastName(void);
		std::string			getNickname(void);
		static std::string	formatWidth(std::string field);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
};

#endif