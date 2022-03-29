/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:21:20 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/04 00:00:34 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

void	ft_init_list(t_vars *list)
{
	list->fps = 0;
	list->img_size = 60;
	list->counter = 0;
	list->window_width = list->img_size * (list->map_width - 1);
	list->window_height = list->img_size * list->map_height;
	list->mlx = mlx_init();
	list->mlx_win = mlx_new_window(list->mlx, list->window_width, \
	list->window_height, "so_long");
	list->render = 1;
}
