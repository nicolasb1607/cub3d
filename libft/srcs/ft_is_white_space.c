/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_white_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:59:19 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/24 10:35:33 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sp_or_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
