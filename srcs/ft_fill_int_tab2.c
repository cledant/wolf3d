/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_int_tab2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:32:55 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 12:35:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_next_lst(t_list **list, size_t *pos, size_t *counter)
{
	*list = (*list)->next;
	pos[0]++;
	pos[1] = 0;
	*counter = 0;
}

static void	ft_mod_counter(size_t *counter, t_list *list, char ***tmp)
{
	*counter = 1;
	*tmp = list->content;
}

static int	**ft_tab_fill(t_list *list, int **tab, size_t *pos, size_t counter)
{
	char **tmp;

	while (list != NULL)
	{
		if (list->content_size > 1)
		{
			if (counter == 0)
				ft_mod_counter(&counter, list, &tmp);
			if (*tmp != NULL)
			{
				if (ft_can_be_atoi(*tmp) == 1)
				{
					tab[pos[0]][pos[1]] = ft_atoi(*tmp);
					pos[1]++;
				}
				tmp++;
			}
			if (*tmp == '\0')
				ft_next_lst(&list, pos, &counter);
		}
		else
			ft_next_lst(&list, pos, &counter);
	}
	return (tab);
}

int			**ft_fill_int_tab2(t_list *list, int x, int y)
{
	int		**tab;
	size_t	pos[2];
	size_t	counter;

	counter = 0;
	pos[0] = 0;
	pos[1] = 0;
	tab = ft_int_tab2_new(x, y);
	if (tab == NULL)
		return (NULL);
	tab = ft_tab_fill(list, tab, pos, counter);
	return (tab);
}
