/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:18:14 by marvin            #+#    #+#             */
/*   Updated: 2023/05/05 15:18:46 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Headers/Webserver.hpp"

// need to do here a function that converts binary to hexa.
// min 5:50 of 2nd video.

char	*re_alloc(char *str, int len)
{
	char *new_str;

	if (str)
		free(str);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	return(new_str);
}

char	*binary_to_hex(SAdd_in *SAddr_in)
{
	int		i = 0;
	int		addr = (int)SAddr_in->sin_port;
	char	hex_chars[17] = "0123456789ABCDEF";
	char	*str;
	while (addr > 0)
	{
		str = re_alloc(str, i);
		str[i] = hex_chars[addr % 16];
		addr /= 16;
		i++;
	}
	return (str);
}
