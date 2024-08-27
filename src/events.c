/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:50:23 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/27 19:20:47 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int keycode, t_fractol *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	handle_arrow_keys(keycode, data);
	handle_zoom_keys(keycode, data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *data)
{
	zoom(button, x, y, data);
	return (0);
}

int	close_window(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
