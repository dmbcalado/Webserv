/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:00:48 by dmendonc          #+#    #+#             */
/*   Updated: 2023/05/05 15:37:52 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Webserver.hpp"

void starting(WebS *WS, SAdd *SAddr, SAdd_in *SAddr_in)
{
	WS->set_sockfd();
	if (WS->get_sockfd() < 0)	// checks if internet socket was well created
		WS->error_handler(1,0);
	bzero(&SAddr, sizeof(SAddr));
	//set_SAddr(SAddr);
	set_SAddr_in(SAddr_in);
}
