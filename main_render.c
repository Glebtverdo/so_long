/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:02:21 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/02 23:23:40 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

int	ft_make_enemy(t_vars *list, int i)
{
	if (list->map[i + 1] == 'E' || list->map[i - 1] == 'E' || \
	list->map[i + list->map_width] == 'E' || \
	list->map[i - list->map_width] == 'E')
	{
		list->img = mlx_xpm_file_to_image(list->mlx, \
		"./textures/V1.xpm", &(list->img_size), &(list->img_size));
		list->map[i] = 'V';
		return (1);
	}
	return (0);
}

void	ft_output_from_1_to_v1(t_vars *list, int width, int height, int i)
{
	if (list->map[i] == '1')
		list->img = mlx_xpm_file_to_image(list->mlx, \
		"./textures/1.xpm", &(list->img_size), &(list->img_size));
	else if (list->map[i] == 'P')
	{
		list->img = mlx_xpm_file_to_image(list->mlx, \
		"./textures/P.xpm", &(list->img_size), &(list->img_size));
		list->p_x = width;
		list->p_y = height;
	}
}

void	ft_output_from_0_to_e(t_vars *list, int i)
{
	if (list->map[i] == '0')
	{
		if (!(ft_make_enemy(list, i)))
		{
			list->img = mlx_xpm_file_to_image(list->mlx, \
			"./textures/0.xpm", &(list->img_size), &(list->img_size));
		}
	}
	else if (list->map[i] == 'C')
	{
		list->img = mlx_xpm_file_to_image(list->mlx, \
		"./textures/C.xpm", &(list->img_size), &(list->img_size));
		list->collectable_count++;
	}
	else if (list->map[i] == 'E')
		list->img = mlx_xpm_file_to_image(list->mlx, \
		"./textures/E.xpm", &(list->img_size), &(list->img_size));
}

void	ft_output_for_main_render(t_vars *list, int *width, int *height, int i)
{
	if (list->map[i] == '2')
	{
		*width = -1;
		*height += 1;
	}
	else
	{
		if (list->map[i] == '1' || list->map[i] == 'P')
			ft_output_from_1_to_v1(list, *width, *height, i);
		else if (list->map[i] == '0' || list->map[i] == 'C' || \
		list->map[i] == 'E')
			ft_output_from_0_to_e(list, i);
		mlx_put_image_to_window(list->mlx, list->mlx_win, \
		list->img, list->img_size * (*width), list->img_size * (*height));
	}
}

void	main_render(t_vars *list)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = 0;
	height = 0;
	list->collectable_count = 0;
	while (list->map[i])
	{
		ft_output_for_main_render(list, &width, &height, i);
		width++;
		i++;
	}
	list->render = 2;
}
