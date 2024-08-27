/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:45:09 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/27 23:58:46 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	calculate_point(t_fractol *data, int x, int y)
{
	double	zr;
	double	zi;
	int		n;
	int		color;

	zr = data->min_r + (double)x * (data->max_r - data->min_r) / WIDTH;
	zi = data->max_i + (double)y * (data->min_i - data->max_i) / HEIGHT;
	if (data->fractal_type == 0)
		n = mandelbrot(zr, zi);
	else
		n = julia(data, zr, zi);
	color = get_color(n);
	put_pixel_to_image(data, x, y, color);
}

static void	iterate_fractal(t_fractol *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_point(data, x, y);
			x++;
		}
		y++;
	}
}

void	render_fractal(t_fractol *data)
{
	iterate_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
