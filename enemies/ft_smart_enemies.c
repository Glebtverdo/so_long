/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_enemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:12:06 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/04 00:11:18 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"enemies.h"

void	ft_change_img(int *coor, int move, t_vars *list, int index)
{
	list->map[index] = '0';
	list->re_render_img = mlx_xpm_file_to_image(list->mlx, \
	"./textures/0.xpm", &(list->img_size), &(list->img_size));
	mlx_put_image_to_window(list->mlx, list->mlx_win, \
	list->re_render_img, coor[0] * list->img_size, coor[1] * list->img_size);
	list->map[index + move] = 'v';
	if (move == list->map_width)
		coor[1] += 1;
	else if (move == -list->map_width)
		coor[1] -= 1;
	else if (move == 1)
		coor[0] += 1;
	else if (move == -1)
		coor[0] -= 1;
	list->re_render_img = mlx_xpm_file_to_image(list->mlx, \
	"./textures/V2.xpm", &(list->img_size), &(list->img_size));
	mlx_put_image_to_window(list->mlx, list->mlx_win, \
	list->re_render_img, coor[0] * list->img_size, coor[1] * list->img_size);
}

int	ft_move_enemy(t_vars *list, int index)
{
	int	coor[2];

	coor[1] = (index / (list->map_width));
	coor[0] = (index % (list->map_width));
	return (ft_get_side_u_d(coor, list, index));
}
