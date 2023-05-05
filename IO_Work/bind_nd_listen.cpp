/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_nd_listen.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:43:12 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/05/05 15:48:28 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Headers/Webserver.hpp"

void	bind_and_listen(WebS *WS, SAdd_in *SAddr_in)
{
	//SAdd		SAddr;
	int			n, conn_fd;
	std::string	recvline, buffer;

	//SAddr.sa_family = AF_INET;

	if (bind(WS->get_sockfd(), (SAdd *)&SAddr_in, sizeof(SAddr_in)) < 0)
		WS->error_handler(5,0);
	if (listen(WS->get_sockfd(), 10) < 0)
		WS->error_handler(5,1);
	while(1)
	{
		//SAdd		new_addr;
		//socklen_t	addr_len;
		std::cout << "waiting for a connection on port" << SERVERPORT << "\n";
		fflush(stdout);
		conn_fd = accept(WS->get_sockfd(), (SAdd *) NULL, NULL);
		memset((void *)recvline.c_str(), 0, BUFFERSIZE);
		while((n = read(conn_fd, (void *)recvline.c_str(), BUFFERSIZE-1)) > 0)
		{
			fprintf(stdout, "\n%s\n\n%s", binary_to_hex(SAddr_in), (char *)recvline.c_str());
			if (recvline[n - 1] == '\n')
				break;
		}
		memset((void *)recvline.c_str(), 0, BUFFERSIZE);
		if (n < 0)
			WS->error_handler(4, 1); // read
		//
		snprintf((char *)buffer.c_str(), sizeof(buffer), \
		"HTTP/1.0 200 OK\r\n\r\n Hello");
		write (conn_fd, (char *)buffer.c_str(), buffer.size());
		close(conn_fd);
	}
}