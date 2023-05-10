/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nd_send.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:38:08 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/05/09 13:27:04 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Webserver.hpp"


// void	connecting(char *argv[], WebS *WS, SAdd_in *SAddr_in)
// {
// 	if (inet_pton(AF_INET, argv[1], &SAddr_in->sin_addr) <= 0)	// converts str arg to binary equivalent
// 		WS->error_handler(2, inet_pton(AF_INET, argv[1], &SAddr_in->sin_addr));
// 	if (connect(WS->get_sockfd(), (SAdd_in *)SAddr_in, sizeof(SAddr_in)) < 0)
// 		WS->error_handler(3, 0);
// }

// void	send_message(std::string sendline, int sendbytes, WebS *WS)
// {
// 	int n;
// 	std::string	recvline;

// 	sprintf((char *)sendline.c_str(), "GET / HTTP/1.1\r\n\r\n");
// 	sendbytes = strlen(sendline.c_str());
// 	if (write(WS->get_sockfd(), (char *)sendline.c_str(), sendbytes) != sendbytes)
// 		WS->error_handler(4, 0); // write error
// 	memset((void *)recvline.c_str(), 0, BUFFERSIZE);
// 	while ( (n = read(WS->get_sockfd(), (void *)recvline.c_str(), BUFFERSIZE - 1)) > 0)
// 		printf("%s", recvline.c_str());
// 	if (n < 0)
// 		WS->error_handler(4,1); // read error
// 	exit(0);
// }
