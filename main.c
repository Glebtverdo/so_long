/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:05:10 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/04 00:00:09 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

int	main(int argc, char **argv)
{
	t_vars	list;

	if (argc != 2)
	{
		ft_putstr_fd("ERROR\nNO MAP\n", 1);
		exit(-1);
	}
	list.map = ft_main_pars(argv[1], &list);
	if (!list.map)
	{
		ft_putstr_fd("ERROR\nUNVALID MAP\n", 1);
		exit(-1);
	}
	ft_init_list(&list);
	mlx_hook(list.mlx_win, 2, 1L << 0, move_p, &list);
	mlx_hook(list.mlx_win, 17, 1L << 17, ft_close, &list);
	main_render(&list);
	mlx_loop_hook(list.mlx, ft_animation, &list);
	mlx_loop(list.mlx);
	return (0);
}
