/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:37:21 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/03 23:58:45 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H
# include <mlx.h>
# include"../libft/libft.h"
# include"../struct.h"

int		ft_move_enemy(t_vars *list, int index);
int		ft_get_side_l_r(int *coor, t_vars *list, int index);
int		ft_get_side_u_d(int *coor, t_vars *list, int index);
void	ft_change_img(int *coor, int move, t_vars *list, int index);

#endif