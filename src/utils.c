/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:53:51 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/31 00:48:36 by rtaboada         ###   ########.fr       */
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
		color = (iteration * 0xFF / MAX_ITERATIONS) << 16;
	else
		color = COLOR_BLACK;
	return (color);
}

void	color_shift(t_fractol *data)
{
	static int	i;

	i = i % 3 + 1;
	if (i == 1)
		data->color = 0xFF;
	else if (i == 0)
		data->color = 0xFF00;
	else
		data->color = 0xFABADA;
	(void)data;
}

int	close_window(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
