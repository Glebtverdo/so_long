/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:44:56 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/02 21:04:09 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *string, int symbol)
{
	unsigned char	s;

	s = (unsigned char)symbol;
	while (*string)
	{
		if (*string == s)
			return (string);
		string++;
	}
	if (*string == s)
		return (string);
	return (NULL);
}
