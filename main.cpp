/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:23:45 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/05/05 16:55:09 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/Webserver.hpp"


//Convert from presentation format of an Internet number in buffer
//starting at CP to the binary network format and store result for
//interface type AF in buffer starting at BUF.

int main(int argc, char *argv[])
{
	WebS		WS;
	SAdd		SAddr;
	SAdd_in		SAddr_in;
	//int		sendbytes;
	std::string	sendline;

	if (argv[0] == NULL)
		exit(1);
	if (argc != 2)
		WS.error_handler(0,0);
	starting(&WS, &SAddr, &SAddr_in);
	std::cout << "bind and listen starts" << std::endl;
	bind_and_listen(&WS, &SAddr_in);
}
