/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:52:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/16 17:46:19 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_texture	*init_texture()
{
	t_texture *texture;

	texture = malloc(sizeof(t_texture));
	texture->north = NULL;
	texture->south= NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor = NULL;
	texture->ceiling = NULL;
	return (texture);
}