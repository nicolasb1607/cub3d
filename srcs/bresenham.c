/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:32:44 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/25 20:30:44 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham.h"

void	bresenham(t_2d a, t_2d b, t_data *data)
{
	t_line	line;
	int	color;

	create_line_data(a, b, &line);
	printf("%d %d %d\n", data->ceiling_color->red, data->ceiling_color->green, data->ceiling_color->blue);
	color = set_rgb_color(data->ceiling_color->red, data->ceiling_color->green, data->ceiling_color->blue);
	put_line(a, b, data->gui->img_data, &line, color);
}

void	create_line_data(t_2d a, t_2d b, t_line *line)
{
	line->ex = abs(b.x - a.x);
	line->ey = abs(b.y - a.y);
	line->dx = 2 * line->ex;
	line->dy = 2 * line->ey;
	line->const_x = line->ex;
	line->const_y = line->ey;
	line->x_incr = 1;
	line->y_incr = 1;
	if (a.x > b.x)
		line->x_incr = -1;
	if (a.y > b.y)
		line->y_incr = -1;
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	set_rgb_color(int r_grad, int g_grad, int b_grad)
{
	return (encode_rgb(r_grad, g_grad, b_grad));
}
