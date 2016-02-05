/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:33:22 by cledant           #+#    #+#             */
/*   Updated: 2016/02/04 14:05:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t		ft_ray_lenght(int begin, int end, double rad_alpha)
{
	double	ret;
	
	ret = (double)begin - (double)end;
//	printf("WTF 1 : %f\n", ret);
	ret = ret / cos(rad_alpha);
//	printf("WTF 2 : %f\n", ret);
	ret = fabs(ret);
//	printf("WTF 3 : %f\n", ret);
//	ft_putendl("CHECK RAYLEN");
	ft_putnbrendl(begin);
	ft_putnbrendl(end);
//	printf("%f\n", rad_alpha);
//	printf("%f\n", cos(rad_alpha));
//	ft_putendl("FIN CHECK RAYLEN");
//	printf("AVANT ROUND : %f\n", ret);
	return (ft_round_double_to_size_t(ret));
}
