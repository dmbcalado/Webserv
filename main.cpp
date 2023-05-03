/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:23:45 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/04/30 23:13:10 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/Webserver.hpp"


//Convert from presentation format of an Internet number in buffer
//starting at CP to the binary network format and store result for
//interface type AF in buffer starting at BUF.

int main(int argc, char *argv[])
{
	WebS	WS;
	SAdd	WS_addr;
	int			sendbytes;
	std::string	sendline;

	starting(argc, argv, &WS, &WS_addr);
	connecting(argv, &WS, &WS_Addr);
	send_message(sendbytes, sendline, &WS, &WS_Addr);
}
