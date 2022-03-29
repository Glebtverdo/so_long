/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:12:20 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/04 00:02:06 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pars.h"

char	*ft_make_result_map(char *result_map, char *str)
{
	char	*buf;

	buf = ft_strjoin(result_map, str);
	if (result_map)
		free(result_map);
	free(str);
	return (buf);
}

int	ft_check_walls(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] == '1')
		i++;
	if (i == len)
		return (1);
	else
		return (0);
}

int	ft_map_first_check(char *str, int line_len, int index)
{
	int	len;

	if (ft_strchr(str, '2'))
		return (0);
	len = ft_strlen(str);
	if (len != line_len && len != line_len - 1)
		return (0);
	if (index == 0 || len == line_len - 1)
		return (ft_check_walls(str, line_len - 1));
	if (str[0] != '1' && str[len - 1] != '1')
		return (0);
	return (1);
}
