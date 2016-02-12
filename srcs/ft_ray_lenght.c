/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:33:22 by cledant           #+#    #+#             */
/*   Updated: 2016/02/12 17:20:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		ft_ray_lenght(int *begin, double *end, double rad_alpha, double alpha)
{
	double	ret;

	ret = 0;
	if (alpha >= -45 && alpha <= 45)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / cos(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha > 45 && alpha < 135)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / sin(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha >= 135 && alpha <= 225)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / cos(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha > 225 && alpha < 315)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / sin(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha >= 315 && alpha <= 405)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / cos(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha < -45 && alpha > -135)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / sin(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha <= -135 && alpha >= -225)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / cos(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha < -225 && alpha > -315)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / sin(rad_alpha);
		ret = fabs(ret);
	}
	else if (alpha <= -315 && alpha >= -405)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / cos(rad_alpha);
		ret = fabs(ret);
	}
	return (ret);
}
