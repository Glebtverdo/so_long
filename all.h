/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:06:16 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/03 23:59:56 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include<stdio.h>
# include<stdlib.h>
# include <mlx.h>
# include"./gnl/gnl_main.h"
# include"./parser/main_pars.h"
# include"./libft/libft.h"
# include"./enemies/ft_animation.h"
# include"struct.h"

int		ft_close(void);
int		move_p(int keycode, t_vars *list);
void	ft_init_list(t_vars *list);
void	ft_show_counter(t_vars *list);
void	main_render(t_vars *list);

#endif