/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:53:58 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/30 22:28:25 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_color_from_palette(int iteration, t_color *palette, int color_shift)
{
	t_color	color;
	int		color_value;

	if (iteration == MAX_ITERATIONS)
		return (COLOR_BLACK);
	color = palette[(iteration + color_shift) % MAX_ITERATIONS];
	color_value = (color.r << 16) | (color.g << 8) | color.b;
	return (color_value);
}
