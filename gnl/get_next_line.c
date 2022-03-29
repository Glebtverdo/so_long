/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:38:51 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/29 19:29:46 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static long long int	ft_check(char *arr)
{
	long long int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_addstr(char *src, long long int end, char *res)
{
	char			*new;

	new = ft_gnl_strjoin(res, src, end);
	free(res);
	return (new);
}

static char	*ft_i_need_more_lines(char *buf, long long int *end, char *arr)
{
	*end = ft_check(arr);
	buf = ft_addstr(arr, *end, buf);
	return (buf);
}

static char	*ft_movestr(char *arr, long long int len)
{
	long long int	i;

	i = 0;
	if (len == -1)
		return (NULL);
	len++;
	while (i <= 256 - len)
	{
		arr[i] = arr[i + len];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*get_next_line(int fd)
{
	static char		st_arr[257];
	static int		last_fd;
	char			*buf;
	long long int	read_status;
	long long int	end;

	if (fd < 0)
		return (NULL);
	buf = NULL;
	if (!st_arr[0] && last_fd == fd)
		end = -1;
	else
		buf = ft_i_need_more_lines(buf, &end, st_arr);
	while (end < 0)
	{
		read_status = read(fd, &st_arr[0], 256);
		if (read_status < 0)
			return (NULL);
		st_arr[read_status] = '\0';
		if (read_status == 0)
			return (buf);
		buf = ft_i_need_more_lines(buf, &end, st_arr);
	}
	ft_movestr(st_arr, end);
	return (buf);
}
