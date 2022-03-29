/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_side_l_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:06:57 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/03 23:59:09 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"enemies.h"

static int	ft_move_rigth(int *coor, t_vars *list, int index)
{
	if (list->map[index + 1] == '0')
	{
		ft_change_img(coor, 1, list, index);
		return (1);
	}
	else if (list->map[index + 1] == 'P')
	{
		ft_putstr_fd("YOU DIED\n", 1);
		exit(0);
	}
	else
		return (0);
}

static int	ft_move_left(int *coor, t_vars *list, int index)
{
	if (list->map[index - 1] == '0')
	{
		ft_change_img(coor, -1, list, index);
		return (1);
	}
	else if (list->map[index - 1] == 'P')
	{
		ft_putstr_fd("YOU DIED\n", 1);
		exit(0);
	}
	else
		return (0);
}

int	ft_get_side_l_r(int *coor, t_vars *list, int index)
{
	int	p_x;
	int	v_x;

	p_x = list->p_x;
	v_x = index % list->map_width;
	if (p_x > v_x)
		return (ft_move_rigth(coor, list, index));
	else if (p_x < v_x)
		return (ft_move_left(coor, list, index));
	return (0);
}
