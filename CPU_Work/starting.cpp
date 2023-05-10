/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:00:48 by dmendonc          #+#    #+#             */
/*   Updated: 2023/05/09 13:25:51 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Webserver.hpp"

void starting(WebS *WS, SAdd *SAddr, SAdd_in *SAddr_in)
{
	WS->set_sockfd();
	bzero(&SAddr, sizeof(SAddr));
	//set_SAddr(SAddr);
	set_SAddr_in(SAddr_in);
}
