/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:18:14 by marvin            #+#    #+#             */
/*   Updated: 2023/05/03 16:18:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Headers/Webserver.hpp"

// need to do here a function that converts binary to hexa.
// min 5:50 of 2nd video.

char	*binary_to_hex(SA *SAdd)
{
	int		i = 0;
    int     addr = (int)SAdd->sin_port;
    char    hex_chars[16] = "0123456789ABCDEF";
	char	*str;
    while (addr > 0)
    {
		str = realloc(str, i);
        str[i] = hex_chars[addr % 16];
		addr /= 16;
		i++;
    }
}

char	*realloc(char *str, int len)
{
	char *new_str;

	if (str)
		free(str);
	new_str = malloc((len + 1) * sizeof(char));
	return(new_str);
}
