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

void starting(int argc, char *argv[], WebS *WS, SAdd *WS_addr)
{
    if (argc != 2)
		WS->error_handler(0,0);
    WS->set_sockfd();
	if (WS->get_sockfd() < 0)	// checks if internet socket was well created
		WS->error_handler(1,0);
	bzero(&WS_addr, sizeof(WS_addr));
	set_WS_Addr(WS_addr);
}

void	connecting(char *argv[], WebS *WS, SAdd *WS_Addr)
{
	if (inet_pton(AF_INET, argv[1], &WS_addr->sin_addr) <= 0)	// converts str arg to binary equivalent
		WS->error_handler(2, inet_pton(AF_INET, argv[1], &WS_addr->sin_addr));
	if (connect(WS->get_sockfd(), (SAdd *)WS_addr, sizeof(WS_addr)) < 0)
		WS->error_handler(3, 0);
}

void	bind_and_listen(WebS *WS, SAdd *WS_Addr)
{
	int			n, conn_fd;
	std::string	recvline;

	if (bind(WS->get_sockfd(), (SAdd *) &WS_Addr, sizeof(set_WS_Addr)) < 0)
		WS->error_handler(5,0);
	if (listen(WS->get_sockfd(), 10) < 0)
		WS->error_handler(5,1);
	while(1)
	{
		SAdd		new_addr;
		socklen_t	addr_len;
		std::cout << "waiting for a connection on port" << SERVERPORT << "\n";
		fflush(stdout);
		conn_fd = accept(WS->get_sockfd(), (SAdd *) NULL, NULL);
		memset(recvline, 0, BUFFERSIZE);
		while((n = read(conn_fd, recvline, BUFFERSIZE-1)) > 0)
		{
			fprintf(stdout, "\n%s\n\n%s", )
		}

	}
}

void	send_message(std::string sendline, int sendbytes, WebS *WS, Sadd *WS_Addr)
{
	int n;
	std::string	recvline;

	sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
	sendbytes = strlen(sendline);
	if (write(WS->get_sockfd(), sendline, sendbytes) != sendbytes)
		WS->error_handler(4, 0); // write error
	memset(recvline, 0, BUFFERSIZE);
	while ( (n = read(WS->get_sockfd(), recvline, BUFFERSIZE - 1)) > 0)
		printf("%s", recvline);
	if (n < 0)
		WS->error_handler(4,1); // read error
	exit(0);
}