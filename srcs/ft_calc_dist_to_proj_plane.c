/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_dist_to_proj_plane.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:20:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/03 12:15:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t	ft_calc_dist_to_proj_plane(void)
{
	double	calc;

	calc = (WIN_X / 2) / tan(ft_angle_dec_to_rad(90 - FOV));
	return (ft_round_double(calc));
}
