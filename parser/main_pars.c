/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:59:03 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/01 22:33:33 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pars.h"

char	*ft_parse_and_first_check(int fd, t_vars *list)
{
	char	*result_map;
	char	*str;

	str = get_next_line(fd);
	list->map_width = ft_strlen(str);
	list->map_height = 0;
	result_map = NULL;
	while (*str)
	{
		if (ft_map_first_check(str, list->map_width, list->map_height))
			result_map = ft_make_result_map(result_map, str);
		else
		{
			free(str);
			free(result_map);
			return (NULL);
		}
		str = get_next_line(fd);
		list->map_height++;
	}
	free(str);
	close(fd);
	return (result_map);
}

char	*ft_second_check(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] == 'E' || str[i] == '1' || str[i] == '2' || \
	str[i] == '0' || str[i] == 'C' || str[i] == 'P')
		i++;
	if ((len != i) || \
	(!ft_strchr(str, 'E') || !ft_strchr(str, 'P') || !ft_strchr(str, 'C')) \
	|| (ft_strchr(str, 'E') != ft_strrchr(str, 'E')) || \
	(ft_strchr(str, 'P') != ft_strrchr(str, 'P')))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_main_pars(char *file_name, t_vars *list)
{
	char	*result_map;
	int		fd;

	fd = ft_check_file(file_name);
	if (fd < 0)
		return (NULL);
	result_map = ft_parse_and_first_check(fd, list);
	if (!result_map)
		return (NULL);
	return (ft_second_check(result_map));
}
