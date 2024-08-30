/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:26:43 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/30 21:26:45 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burning_ship(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITERATIONS)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = fabs(2 * zr * zi) + ci;
		zr = fabs(tmp);
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		n++;
	}
	return (n);
}
