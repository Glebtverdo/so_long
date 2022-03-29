/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:59:10 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/14 16:41:10 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

void	ft_show_counter(t_vars *list)
{
	char	*counter;

	counter = ft_itoa(list->counter);
	if (counter == NULL)
	{
		ft_putstr_fd("Error\nMALLOC EROOR\n", 1);
		exit(1);
	}
	list->counter_img = mlx_xpm_file_to_image(list->mlx, "./textures/1.xpm", \
	&(list->img_size), &(list->img_size));
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->counter_img, \
	list->img_size, 0);
	mlx_string_put(list->mlx, list->mlx_win, list->img_size + \
	list->img_size / 2, list->img_size / 3, 0x000000FF, counter);
	free(counter);
}

static void	ft_move_for_ft_move(t_vars *list, int move_x, int move_y)
{
	list->img = mlx_xpm_file_to_image(list->mlx, "./textures/0.xpm", \
	&(list->img_size), &(list->img_size));
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, \
	list->p_x * list->img_size, list->p_y * list->img_size);
	list->p_x += move_x;
	list->p_y += move_y;
	list->pers_img = mlx_xpm_file_to_image(list->mlx, "./textures/P.xpm", \
	&(list->img_size), &(list->img_size));
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->pers_img, \
	list->p_x * list->img_size, list->p_y * list->img_size);
	list->counter++;
	ft_show_counter(list);
}

static void	ft_more_more_for_ft_move(t_vars *list, int index, \
int move_x, int move_y)
{
	if ((list->map)[index] == 'V')
	{
		write(1, "YOU DIED\n", 9);
		exit(0);
	}
	if ((list->map)[index] == 'E')
	{
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
	(list->map)[list->p_index] = '0';
	ft_move_for_ft_move(list, move_x, move_y);
	(list->map)[index] = 'P';
	list->p_index = index;
	ft_putnbr_fd(list->counter, 1);
	write(1, "\n", 1);
}

static void	ft_move(t_vars *list, int move_x, int move_y)
{
	int		index;

	index = ((list->p_y + move_y)) * list->map_width + \
	((list->p_x + move_x));
	if ((list->map)[index] != '1')
	{
		if ((list->map)[index] == 'C')
			list->collectable_count--;
		if ((list->map)[index] != 'E' || list->collectable_count == 0)
			ft_more_more_for_ft_move(list, index, move_x, move_y);
	}
}

int	move_p(int keycode, t_vars *list)
{
	if (keycode == 13)
		ft_move(list, 0, -1);
	else if (keycode == 0)
		ft_move(list, -1, 0);
	else if (keycode == 1)
		ft_move(list, 0, 1);
	else if (keycode == 2)
		ft_move(list, 1, 0);
	else if (keycode == 53)
		exit(0);
	return (0);
}
