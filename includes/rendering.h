/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:33:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/05 14:31:48 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "cub3d.h"


void	draw_player(t_data *data);
void	draw_all_raycasting(t_data *data, t_list *all_rays);
void	draw_minimap(t_data *data);
void	set_tile_color(t_data *data, int i, int j);
void	draw_strip_wall(int i, int wall_strip_height, t_data *data);
void	draw_walls(t_data *data, t_list *all_rays);

#endif