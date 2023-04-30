/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:20:30 by dmendonc          #+#    #+#             */
/*   Updated: 2023/04/30 22:50:25 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Webserver.hpp"



// Create a new socket of type SOCK_STREAM in domain iPv4, using
// protocol PROTOCOL. If PROTOCOL is zero, one is chosen automatically.
// Returns a file descriptor for the new socket, or -1 for errors.

void	WebS::set_sockfd() {
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
}

int     WebS::get_sockfd() {return (sock_fd);}