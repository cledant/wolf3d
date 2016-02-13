/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:33:22 by cledant           #+#    #+#             */
/*   Updated: 2016/02/13 20:52:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double		ft_ray_lenght(int *begin, double *end, double angle[8])
{
	double	ret;

	ret = 0;
	if (angle[0] >= -45 && angle[0] <= 45)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / angle[4];
		ret = fabs(ret);
	}
	else if (angle[0] > 45 && angle[0] < 135)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / angle[5];
		ret = fabs(ret);
	}
	else if (angle[0] >= 135 && angle[0] <= 225)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / angle[4];
		ret = fabs(ret);
	}
	else if (angle[0] > 225 && angle[0] < 315)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / angle[5];
		ret = fabs(ret);
	}
	else if (angle[0] >= 315 && angle[0] <= 405)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / angle[4];
		ret = fabs(ret);
	}
	else if (angle[0] < -45 && angle[0] > -135)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / angle[5];
		ret = fabs(ret);
	}
	else if (angle[0] <= -135 && angle[0] >= -225)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / angle[4];
		ret = fabs(ret);
	}
	else if (angle[0] < -225 && angle[0] > -315)
	{
		ret = (double)begin[1] - (double)end[1];
		ret = ret / angle[5];
		ret = fabs(ret);
	}
	else if (angle[0] <= -315 && angle[0] >= -405)
	{
		ret = (double)begin[0] - (double)end[0];
		ret = ret / angle[4];
		ret = fabs(ret);
	}
	return (ret);
}
