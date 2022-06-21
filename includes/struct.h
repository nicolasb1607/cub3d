/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:31:12 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/21 15:17:53 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_file
{
	char	*name;
	int		fd;
	int		map_index;
}	t_file;

typedef struct s_data
{
	struct s_texture	*texture;
	struct s_map		*map;
}	t_data;

typedef struct	s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
}	t_texture;

typedef struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct	s_map
{
	char			**content;
	int				width;
	int				height;
}	t_map;

#endif
