/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_nd_listen.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:43:12 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/05/09 14:03:52 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Headers/Webserver.hpp"

void	bind_and_listen(WebS *WS, SAdd_in *SAddr_in, int listen_fd)
{
	int			n, conn_fd;
	char		recvline[4096];
	std::string	buffer;
	int			addrlen = sizeof(&SAddr_in);

	while(1)
	{
		std::cout << "waiting for a connection on port" << SERVERPORT << "\n";
		//fflush(stdout);
		if ((conn_fd = accept(listen_fd, (SAdd *)&SAddr_in, (socklen_t*)&addrlen)) < 0)
			std::cout << "error here" << std::endl;
		memset(recvline, 0, BUFFERSIZE);
		while((n = read(conn_fd, recvline, BUFFERSIZE-1)) > 0)
		{
			fprintf(stdout, "\n%s\n\n%s", binary_to_hex(SAddr_in), recvline);
			if (recvline[n - 1] == '\n')
				break;
		}
		memset(recvline, 0, BUFFERSIZE);
		if (n < 0)
			WS->error_handler(4, 1); // read
		//
		snprintf((char *)buffer.c_str(), sizeof(buffer), \
		"HTTP/1.0 200 OK\r\n\r\n Hello");
		write (conn_fd, (char *)buffer.c_str(), buffer.size());
		close(conn_fd);
	}
}