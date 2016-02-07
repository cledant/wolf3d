/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstseek_max_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:12:18 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 12:37:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t		ft_lstseek_max_x(t_list *list)
{
	size_t	result;
	size_t	max_result;
	char	**tmp;

	result = 0;
	max_result = 0;
	while (list != NULL)
	{
		if (list->content_size != 1)
		{
			tmp = list->content;
			while (*tmp != '\0')
			{
				result = result + ft_can_be_atoi(*tmp);
				tmp++;
			}
			if (result > max_result)
				max_result = result;
			result = 0;
			list = list->next;
		}
		else
			list = list->next;
	}
	return (max_result);
}
