/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:04:37 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/14 16:40:46 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vars {
	char	*map;
	int		map_width;
	int		map_height;
	int		img_size;
	int		window_width;
	int		window_height;
	int		fps;
	int		collectable_count;
	int		p_x;
	int		p_y;
	int		p_index;
	int		render;
	int		counter;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*re_render_img;
	void	*counter_img;
	void	*pers_img;
}				t_vars;

#endif