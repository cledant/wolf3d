/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_int2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:26:17 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 15:01:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_putendl_int2(int **tab, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			ft_putnbr(tab[j][i]);
			if (i != x - 1)
				ft_putstr("");
			else
				ft_putendl("");
			i++;
		}
		i = 0;
		j++;
	}
}
