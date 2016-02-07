/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_double_to_size_t.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:29:09 by cledant           #+#    #+#             */
/*   Updated: 2016/02/03 15:29:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_round_double_to_size_t(double nb)
{
	size_t	nb_int;

	nb_int = (size_t)nb;
	if (ft_abs(nb_int - nb) >= 0.5)
		nb_int++;
	return (nb_int);
}
