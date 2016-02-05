/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_pos_x_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:27:28 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 15:02:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_seek_pos_x_player(int **tab, int x, int y)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			if (tab[j][i] == 2)
				return (i);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
