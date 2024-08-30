/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:27:37 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/30 22:28:58 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	zr_squared;
	double	zi_squared;

	zr = 0.0;
	zi = 0.0;
	zr_squared = 0.0;
	zi_squared = 0.0;
	n = 0;
	while (zr_squared + zi_squared <= 4.0 && n < MAX_ITERATIONS)
	{
		zi = 2.0 * zr * zi + ci;
		zr = zr_squared - zi_squared + cr;
		zr_squared = zr * zr;
		zi_squared = zi * zi;
		n++;
	}
	if (n == MAX_ITERATIONS)
		return (MAX_ITERATIONS);
	return (n);
}
