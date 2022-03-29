/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_side_u_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:12:23 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/03 23:59:28 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"enemies.h"

static int	ft_move_up(int *coor, t_vars *list, int index)
{
	if (list->map[index + list->map_width] == '0')
	{
		ft_change_img(coor, list->map_width, list, index);
		return (1);
	}
	else if (list->map[index + list->map_width] == 'P')
	{
		ft_putstr_fd("YOU DIED\n", 1);
		exit(0);
	}
	else
		return (ft_get_side_l_r(coor, list, index));
}

static int	ft_move_down(int *coor, t_vars *list, int index)
{
	if (list->map[index - list->map_width] == '0')
	{
		ft_change_img(coor, -1 * list->map_width, list, index);
		return (1);
	}
	else if (list->map[index + list->map_width] == 'P')
	{
		ft_putstr_fd("YOU DIED\n", 1);
		exit(0);
	}
	else
		return (ft_get_side_l_r(coor, list, index));
}

int	ft_get_side_u_d(int *coor, t_vars *list, int index)
{
	if (list->p_y > index / list->map_width)
		return (ft_move_up(coor, list, index));
	else if (list->p_y < index / list->map_width)
		return (ft_move_down(coor, list, index));
	else
		return (ft_get_side_l_r(coor, list, index));
}
