/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserver.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:44:41 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/04/30 23:13:22 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP
# define MAX_INT 1000

# include "Librarys.hpp"
# include "SockAddr.hpp"

class WebS
{
	public:
		void	error_handler(int type, int subtype);
		void	set_sockfd();
		int		get_sockfd();
	private:
		int	sock_fd;

};

void	set_WS_Addr(struct sockaddr_in *WS_Addr);
void	starting(int argc, char *argv[], WebS *WS, struct sockaddr_in *WS_Addr);
#endif