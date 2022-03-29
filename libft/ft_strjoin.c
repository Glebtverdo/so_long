/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:38:20 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/04 00:03:24 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s2_len;
	size_t	s1_len;
	size_t	i;
	char	*new;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = malloc(sizeof(char) * (s2_len + s1_len + 1));
	i = -1;
	if (new == NULL)
		return (NULL);
	while (++i < s1_len)
		new[i] = s1[i];
	while (i < s2_len + s1_len)
	{
		if (s2[i - s1_len] == '\n')
			new[i] = '2';
		else
			new[i] = s2[i - s1_len];
		i++;
	}
	new[i] = '\0';
	return (new);
}
