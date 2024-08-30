/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:59:36 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/30 22:22:36 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_palette_one(t_color *palette)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		palette[i].r = (i * 255 / MAX_ITERATIONS);
		palette[i].g = (i * 255 / MAX_ITERATIONS);
		palette[i].b = 255 - (i * 255 / MAX_ITERATIONS);
		i++;
	}
}

void	init_palette_two(t_color *palette)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		palette[i].r = 255 - (i * 255 / MAX_ITERATIONS);
		palette[i].g = (i * 128 / MAX_ITERATIONS);
		palette[i].b = (i * 255 / MAX_ITERATIONS);
		i++;
	}
}

void	init_palette_three(t_color *palette)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		palette[i].r = (i * 128 / MAX_ITERATIONS);
		palette[i].g = 255 - (i * 255 / MAX_ITERATIONS);
		palette[i].b = 255 - (i * 255 / MAX_ITERATIONS);
		i++;
	}
}

void	init_palette_four(t_color *palette)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		palette[i].r = (i * 7) % 256;
		palette[i].g = (i * 5) % 256;
		palette[i].b = (i * 11) % 256;
		i++;
	}
}

void	init_palette_five(t_color *palette)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		palette[i].r = (i * 255 / MAX_ITERATIONS);
		palette[i].g = (i * 255 / MAX_ITERATIONS);
		palette[i].b = (i * 255 / MAX_ITERATIONS);
		i++;
	}
}
