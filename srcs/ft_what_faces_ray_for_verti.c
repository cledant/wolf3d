/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_faces_ray_for_verti.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:45:59 by cledant           #+#    #+#             */
/*   Updated: 2016/02/06 11:51:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_what_faces_ray_for_verti(double alpha)
{
	if (alpha <= 90 && alpha >= 0)
		return (1);
	else if (alpha >= 270  && alpha < 360)
		return (1);
	else if (alpha <= 0 && alpha >= -90)
		return (1);
	else if (alpha <= -270  && alpha > -360)
		return (1);
	else
		return (-1);
}
