/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:17:48 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/03 23:38:59 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H
# include"../libft/libft.h"
# include"../gnl/gnl_main.h"
# include"../struct.h"
# include<fcntl.h>

int		ft_check_file(char *file_name);
char	*ft_make_result_map(char *result_map, char *str);
int		ft_check_walls(char *str, int len);
int		ft_map_first_check(char *str, int line_len, int index);

#endif