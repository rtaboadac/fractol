/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:05:46 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/25 14:43:49 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_shift(int x, int y, t_fractol *data)
{
	data->kr = data->min_r + (double)x * (data->max_r - data->min_r) / WIDTH;
	data->ki = data->max_i + (double)y * (data->min_i - data->max_i) / HEIGHT;
	render_fractal(data);
	return (0);
}

int	julia(t_fractol *data, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + data->ki;
		zr = zr * zr - zi * zi + data->kr;
		zi = tmp;
		n++;
	}
	return (n);
}
