/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SockAddr.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:31:52 by dmendonc          #+#    #+#             */
/*   Updated: 2023/04/30 22:32:18 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Headers/Librarys.hpp"

//AF_INET: Specifies the iPv4 address family.

//The port number must be specified in direct binary form in the sin_port 
//member of the structure. Therefore, it is necessary to convert the value 
//to this data type.
//The htons() function is most commonly used for this purpose. It converts 
//the integer value contained in its input argument and returns its value 
//in direct binary format to its output.

// sin_family: this is a short that specifies the type of address family 
//             that the structure contains.

// sin_port:   specifies the port number that the socket will use. Like 
//			   addresses, the port number is not encoded, which means that
//             it must be specified in direct binary format, so a conversion 
//			   to this data type must be done to assign a value to it.

void	set_WS_Addr(struct sockaddr_in *WS_Addr)
{
	WS_Addr->sin_family = AF_INET;
	WS_Addr->sin_port = htons(SOCK_STREAM);
}