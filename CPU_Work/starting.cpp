/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:00:48 by dmendonc          #+#    #+#             */
/*   Updated: 2023/04/30 23:12:57 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Webserver.hpp"

void starting(int argc, char *argv[], WebS *WS, struct sockaddr_in *WS_addr)
{
    if (argc != 2)
		WS->error_handler(0,0);
    WS->set_sockfd();
	if (WS->get_sockfd() < 0)
		WS->error_handler(1,0);
	if (inet_pton(AF_INET, argv[1], &WS_addr->sin_addr) <= 0)
		WS->error_handler(2, inet_pton(AF_INET, argv[1], &WS_addr->sin_addr));
}