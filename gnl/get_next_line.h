/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:39:08 by vearleen          #+#    #+#             */
/*   Updated: 2021/11/29 19:29:02 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<limits.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>

char			*get_next_line(int fd);
char			*ft_gnl_strjoin(char *s1, char *s2, long long int end);
long long int	ft_gnl_strlen(char *str);

#endif