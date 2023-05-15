/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:23:45 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/05/15 16:02:43 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/Webserver.hpp"


//Convert from presentation format of an Internet number in buffer
//starting at CP to the binary network format and store result for
//interface type AF in buffer starting at BUF.

int main(int argc, char *argv[])
{
	WebS		WS;
	//SAdd		SAddr;
	SAdd_in		SAddr_in;
	int			n, listen_fd, conn_fd;
	std::string	sendline, buffer;
	char		recvline[4096];
	if (argv[0] == NULL)
		exit(1);
	if (argc != 2)
		WS.error_handler(0,0);

	bzero(&SAddr_in, sizeof(SAddr_in));
	SAddr_in.sin_family = AF_INET;
	SAddr_in.sin_port = SERVERPORT;
	SAddr_in.sin_addr.s_addr = INADDR_ANY;

	// create and check if well created socket
	if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		WS.error_handler(1,0);
	std::cout << "listen_fd : " << listen_fd << std::endl;
	// bind socket with the servers address and put it to listen
	if (bind(listen_fd, (SAdd *)&SAddr_in, sizeof(SAddr_in)) < 0)
		WS.error_handler(5,0);
	if (listen(listen_fd, 10) < 0)
		WS.error_handler(5,1);

	std::cout << "loop starts" << std::endl;
	while(1)
	{
		std::cout << "waiting for a connection on port " << SERVERPORT << std::endl;
		std::cout << "ti segura ti segura, tiii segura ";
		fflush(stdout);
		if ((conn_fd = accept(listen_fd, (SAdd *)NULL, NULL)) < 0)
			std::cout << "error here" << std::endl;
		std::cout << "ca vida ta dura" << std::endl;
		memset(recvline, 0, BUFFERSIZE - 1);
		while((n = read(conn_fd, recvline, BUFFERSIZE-1)) > 0)
		{
			fprintf(stdout, "\n%s\n\n%s", binary_to_hex(&SAddr_in), recvline);
			if (recvline[n - 1] == '\n')
				break;
		}
		memset(recvline, 0, BUFFERSIZE);
		// if (n < 0)
		// 	WS.error_handler(4, 1); // read
		//
		snprintf((char *)buffer.c_str(), sizeof(buffer), \
		"HTTP/1.0 200 OK\r\n\r\n Hello");
		write (conn_fd, (char *)buffer.c_str(), buffer.size());
		close(conn_fd);
	}
}
