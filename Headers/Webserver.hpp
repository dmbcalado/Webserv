/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:44:41 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/05/05 15:12:54 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP
# define MAX_INT 1000

# include "Librarys.hpp"

class WebS
{
	public:
		void	error_handler(int type, int subtype);
		void	set_sockfd();
		int		get_sockfd();
	private:
		int	sock_fd;
};

// functions to set socket's address
void	set_SAddr(SAdd *SAddr);
void	set_SAddr_in(SAdd_in *SA);

char	*binary_to_hex(SAdd_in *SAddr_in);
void	starting(WebS *WS, SAdd *SAddr, SAdd_in *SAddr_in);

void	bind_and_listen(WebS *WS, SAdd_in *SAddr_in);
void	connecting(char *argv[], WebS *WS, SAdd_in *SAddr_in);
void	send_message(std::string sendline, int sendbytes, WebS *WS);

#endif