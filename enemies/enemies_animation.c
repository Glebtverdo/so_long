/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:09:13 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/03 23:43:22 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"enemies.h"

static void	ft_more_for_re_render(t_vars *list, int width, int height, int i)
{
	if (list->map[i] == 'V')
	{
		if (list->render == 2)
		{
			if (!ft_move_enemy(list, i))
			{
				list->re_render_img = mlx_xpm_file_to_image(list->mlx, \
				"./textures/V2.xpm", &(list->img_size), &(list->img_size));
				mlx_put_image_to_window(list->mlx, list->mlx_win, \
				list->re_render_img, \
				list->img_size * width, list->img_size * height);
			}
		}
		else
		{
			list->re_render_img = mlx_xpm_file_to_image(list->mlx, \
			"./textures/V1.xpm", &(list->img_size), &(list->img_size));
			mlx_put_image_to_window(list->mlx, list->mlx_win, \
			list->re_render_img, \
			list->img_size * width, list->img_size * height);
		}
	}
}

static void	ft_remake_v(t_vars *list)
{
	int		i;

	i = 0;
	while (list->map[i])
	{
		if (list->map[i] == 'v')
			list->map[i] = 'V';
		i++;
	}
}

static void	re_render(t_vars *list)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	width = 0;
	height = 0;
	while (list->map[i])
	{
		if (list->map[i] == '2')
		{
			width = -1;
			height++;
		}
		else
			ft_more_for_re_render(list, width, height, i);
		width++;
		i++;
	}
	ft_remake_v(list);
	if (list->render == 2)
		list->render = 1;
	else
		list->render = 2;
}

int	ft_animation(t_vars *list)
{
	if (list->fps == 6000)
	{
		list->fps = -1;
		re_render(list);
	}
	else if (list->fps == 3000)
		re_render(list);
	list->fps++;
	return (0);
}
