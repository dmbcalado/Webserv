/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Librarys.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:30:07 by dmendonc          #+#    #+#             */
/*   Updated: 2023/05/05 14:29:43 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARYS_HPP
# define LIBRARYS_HPP

# include <map>
# include <string>
# include <cstring>
# include <fstream>
# include <unistd.h>
# include <limits.h>
# include <iostream>
# include <algorithm>
# include <strings.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <netinet/in.h>

// Standard for HTTP port
# define SERVERPORT 1700
// Buffer size for reading
# define BUFFERSIZE 4096

//struct sockaddr {
//	unsigned short	sa_family;			// 2 bytes address family, AF_xxx
//	char			sa_data[14];		// 14 bytes of protocol address
//};

//struct sockaddr_in {
//	short			sin_family;			// 2 bytes e.g. AF_INET, AF_INET6
//	unsigned short	sin_port;			// 2 bytes e.g. htons(3490)
//	struct in_addr	sin_addr;			// 4 bytes see struct in_addr, below
//	char				sin_zero[8];	// 8 bytes zero this if you want to
//};

#define SAdd struct		sockaddr
#define SAdd_in struct	sockaddr_in

#endif