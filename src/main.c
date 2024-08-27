/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:53:26 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/27 20:14:21 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mlx(t_fractol *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!data->win)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		exit(EXIT_FAILURE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

static void	init_fractal(t_fractol *data, char *fractal_type)
{
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->min_r = -2.0;
	data->max_r = 2.0;
	data->min_i = -2.0;
	data->max_i = 2.0;
	if (ft_strncmp(fractal_type, "mandelbrot", ft_strlen("mandelbrot")) == 0)
		data->fractal_type = 0;
	else if (ft_strncmp(fractal_type, "julia", ft_strlen("julia")) == 0)
	{
		data->fractal_type = 1;
		data->kr = -0.7;
		data->ki = 0.27015;
	}
	else
	{
		ft_printf("Unknown fractal type: %s\n", fractal_type);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	if (argc != 2)
	{
		ft_printf("Available fractal types: mandelbrot, julia\n");
		return (1);
	}
	init_mlx(&data);
	init_fractal(&data, argv[1]);
	render_fractal(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
