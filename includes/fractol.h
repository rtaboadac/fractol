/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:07:43 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/27 23:58:13 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "constants.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractal_type;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
}			t_fractol;

void		render_fractal(t_fractol *data);
int			key_hook(int keycode, t_fractol *data);
int			mouse_hook(int button, int x, int y, t_fractol *data);
int			close_window(t_fractol *data);
void		handle_arrow_keys(int keycode, t_fractol *data);
void		handle_zoom_keys(int keycode, t_fractol *data);
void		zoom(int button, int x, int y, t_fractol *data);
void		put_pixel_to_image(t_fractol *data, int x, int y, int color);
int			get_color(int iteration);
int			mandelbrot(double cr, double ci);
int			julia_shift(int x, int y, t_fractol *data);
int			julia(t_fractol *data, double zr, double zi);

#endif
