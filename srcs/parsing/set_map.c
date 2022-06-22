/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:24:31 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/22 16:29:59 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_map	*set_map(t_file *file)
{
	t_map	*map;
	char	*line;

	line = get_next_line(file->fd);
	while (line != NULL && line[0] == '\n')
	{
		file->map_index++;
		free(line);
		line = get_next_line(file->fd);
	}
	free(line);
	printf("index : %d\n", file->map_index);
	if (line == NULL)
	{
		ft_putstr_fd(ERROR_MISSING_MAP, 2);
		close(file->fd);
		return (NULL);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	 	return (NULL);
	get_map_size(file->fd, map);
	printf("%d %d\n", map->width, map->height);
	if (get_map_content(file, map) == -1)
		return (NULL);
	return (map);
}

void	get_map_size(int fd, t_map *map)
{
	char	*line;
	int		size;

	line = get_next_line(fd);
	map->height++;
	while (line != NULL)
	{
		size = (int)ft_strlen(line);
		if(size > map->width)
		{
			if (line[size - 1] == '\n')
				map->width = size - 1;
			else
				map->width = size;
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	get_map_content(t_file *file, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	file->fd = open(file->name, O_RDONLY);
	
	if(file->fd < 0)
		return (ft_putstr_fd(ERROR_OPEN_FILE, 2), -1);
	while(i < file->map_index)
	{
		line = get_next_line(file->fd);
		free(line);
		i++;
	}
	map = alloc_map_content(map);
	if (!map)
		return (-1);
	if (fill_map(file, map) == NULL)
		return (-1);
	return (0);
}

void	*fill_map(t_file *file, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(file->fd);
	while (line != NULL)
	{
		map->content[i] = collect_data_from_line(line, map->content[i]);
		if (map->content[i] == NULL)
		{
			free_map(map, map->height);
			free(line);
			return (NULL);
		}
		free(line);
		line = get_next_line(file->fd);
		i++;
	}
	return (map);
}


char	*collect_data_from_line(char *line, char *content)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_allowed_char(line[i]))
		{
			ft_putstr_fd(ERROR_MAP_FORMAT, 2);
			free(content);
			return (NULL);
		}
		else if (!ft_is_space(line[i]))
			content[j++] = line[i++];
		else
		{
			i++;
			j++;
		}
	}
	return (content);
}

t_map	*alloc_map_content(t_map *map)
{
	int	i;

	map->content = ft_calloc(map->height + 1, sizeof(char *));
	if(!map->content)
	{
		ft_putstr_fd(ERROR_MALLOC, 2);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		map->content[i] = ft_calloc(map->width + 1, sizeof(char));
		if(!map->content[i])
		{ 
			free_map(map, i);
			ft_putstr_fd(ERROR_MALLOC, 2);
			return (NULL);
		}
		ft_memset_char_bis(map->content[i], '1', map->width);
		i++;
	}
	return (map);
}

void	free_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map->content[i]);
		i++;
	}
	free(map->content);
	free(map);
}
