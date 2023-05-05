/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:50:34 by dmendonc          #+#    #+#             */
/*   Updated: 2023/05/05 15:40:50 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Webserver.hpp"

void    WebS::error_handler(int type, int subtype)
{
	if (type == 0)
	{
		std::cout << "You need to specify a configuration file\n";
		std::cout << "Type : ./webserver [configuration filename]\n";
		std::cout << "or instead of [configuration filename] the path to it.\n";
	}
	else if (type == 1)
		std::cout << "Failed to create a new socket in set_sockfd()\n";
	else if (type == 2)
	{
		if (subtype == 0)
		{
			std::cout << "inet_pton : src does not contain a character string ";
			std::cout << "representing a valid network address in the ";
			std::cout << "specified address family.\n";
		}
		if (subtype == 1)
		{
			std::cout << "inet_pton : af does not contain a valid address ";
       		std::cout << "family";
		}
	}
	else if (type == 3)
	{
		// connecting errors
	}
	else if (type == 4)
	{
		// send message errors
	}
	else if (type == 5)
	{
		if (subtype == 0)
			std::cout << "error on binding" << std::endl;
		else if (subtype == 1)
			std::cout << "error on listening" << std::endl;
	}
	exit(1);
}