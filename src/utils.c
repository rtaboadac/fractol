/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:53:51 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/30 22:23:18 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel_to_image(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iteration)
{
	int	color;

	if (iteration == MAX_ITERATIONS)
		color = COLOR_BLACK;
	else
		color = (iteration * 0xFF / MAX_ITERATIONS) << 16;
	return (color);
}

void	color_shift(t_fractol *f)
{
	(void)f;
}

int	close_window(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
