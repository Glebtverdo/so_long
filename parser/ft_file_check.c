/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:11:15 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/04 00:01:47 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pars.h"

static int	ft_check_file_name(char *file_name)
{
	char	*str;

	if (!file_name)
		return (1);
	str = ft_strrchr(file_name, '.');
	if (str && !ft_strncmp(str, ".ber\0", 5))
		return (0);
	return (1);
}

int	ft_check_file(char *file_name)
{
	int	fd;

	if (ft_check_file_name(file_name))
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
