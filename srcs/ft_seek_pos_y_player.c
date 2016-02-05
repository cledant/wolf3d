/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_pos_y_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:27:28 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 15:01:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_seek_pos_y_player(int **tab, int x, int y)
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
				return (j);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
