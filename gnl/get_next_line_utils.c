/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:36:02 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/29 19:29:54 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

long long int	ft_gnl_strlen(char *str)
{
	long long int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2, long long int end)
{
	long long int	s2_len;
	long long int	s1_len;
	long long int	i;
	char			*new;

	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	new = malloc(sizeof(char) * (s2_len + s1_len + 1));
	i = 0;
	if (new == NULL)
		return (NULL);
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	if (end == -1)
		end = s2_len + s1_len;
	while (i < s2_len + s1_len && i - s1_len <= end)
	{
		new[i] = s2[i - s1_len];
		i++;
	}
	new[i] = '\0';
	return (new);
}
