/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:44:06 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/24 12:01:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"


void	put_line(t_2d a, t_2d b, t_img_data *img, t_line *line, int color)
{
	if (line->const_x > line->const_y)
		dx_put_line(a, img, line, color);
	else if (line->const_x <= line->const_y)
		dy_put_line(a, img, line, color);
	else if (line->const_x == 0)
		horizontal_line(a, b, img, color);
	else if (line->const_y == 0)
		vertical_line(a, b, img, color);
}

void	dx_put_line(t_2d a, t_img_data *img, t_line *line, int color)
{
	int	i;

	i = 0;
	while (i <= line->const_x)
	{
		my_mlx_pixel_put(a.x, a.y, img,
			color);
		i++;
		a.x += line->x_incr;
		line->ex -= line->dy;
		if (line->ex < 0)
		{
			a.y += line->y_incr;
			line->ex += line->dx;
		}
	}
}

void	dy_put_line(t_2d a, t_img_data *img, t_line *line, int color)
{
	int	i;

	i = 0;
	while (i <= line->const_y)
	{
		my_mlx_pixel_put(a.x, a.y, img,
			color);
		i++;
		a.y += line->y_incr;
		line->ey -= line->dx;
		if (line->ey < 0)
		{
			a.x += line->x_incr;
			line->ey += line->dy;
		}
	}
}

void	horizontal_line(t_2d a, t_2d b, t_img_data *img, int color)
{
	int	tmp;

	if (a.x > b.x)
	{
		tmp = a.x;
		a.x = b.x;
		b.x = tmp;
	}
	while (a.x <= b.x)
	{
		my_mlx_pixel_put(a.x, a.y, img,
			color);
		a.x++;
	}
}

void	vertical_line(t_2d a, t_2d b, t_img_data *img, int color)
{
	int	tmp;

	if (a.y > b.y)
	{
		tmp = a.y ;
		a.y = b.y;
		b.y = tmp;
	}
	while (a.y <= b.y)
	{
		my_mlx_pixel_put(a.x, a.y, img,
			color);
		a.y++;
	}
}
