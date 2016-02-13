/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_faces_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:59:49 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 19:07:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_what_faces_ray(double alpha)
{
	if (alpha >= 0 && alpha <= 180)
		return (1);
	else if (alpha <= -180 && alpha >= -360)
		return (1);
	else
		return (-1);
}
