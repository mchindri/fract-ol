/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandlebort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:44 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/05 16:13:42 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
ch pixel (Px, Py) on the screen, do:
{
x0 = scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
y0 = scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
x = 0.0
y = 0.0
	iteration = 0
	max_iteration = 1000
	while (x*x + y*y < 2*2  AND  iteration < max_iteration) {
		xtemp = x*x - y*y + x0
			y = 2*x*y + y0
			x = xtemp
			iteration = iteration + 1
	}
	color = palette[iteration]
	plot(Px, Py, color)
}

x = RE(z^2 + c)
*/

int		ft_chose_color(int iter)
{

	if (iter == MAX_ITER)
		return (ft_set_color(0, 0, 0));
	else if (iter % 3 == 0)
		return (ft_set_color(255, 0, 0));
	else if (iter % 3 == 1)
		return (ft_set_color(0, 255, 0));
	else 
		return (ft_set_color(0, 0, 255));
}

int		ft_iterate(int i, int j)
{
	double x;double y;
	double complex	z0;
	double complex	z;
	int				iter;
	double pas;
	int	iter_n[MAX_ITER];
	int nb_max;
	int iter_i;
	pas = 1 / DIF;
	
	iter_i = MAX_ITER;
	ft_bzero(iter_n, sizeof(iter_n));
	nb_max = 0;
	x = i - pas * DIF / 2;
	while (x < i + pas * DIF / 2)
	{
		y = j - pas * DIF / 2;
		while (y < j + pas * DIF / 2)
		{
			z0 = CMPLX(x, y);
			z = 0 + 0 * I;
			iter = 0;	
			while (cabs(z) < RADIOUS && iter < MAX_ITER)
			{
				z = creal(cpow(z, 2) + z0) + I * cimag(cpow(z, 2) + z0);
				iter++;
			}
			iter_n[iter]++;
			if (iter_n[iter] > nb_max)
			{
				nb_max = iter_n[iter];
				iter_i = iter;
			}
			y += pas;
		}
		x += pas;
	}
	return (iter_n[iter_i]);
}

void	 ft_draw_mandlebort(t_mlx ptr)
{
	int		i;
	int		j;
	int iter;
	ptr.img = mlx_new_image(ptr.mlx, WIN_WID, WIN_LEN);
	
	t_point c;
	c.x = (4 / 7.) * WIN_WID;
	c.y = WIN_LEN / 2;
	int color;
	i = 0;
	while (i < WIN_WID)
	{
		j = 0;
		while (j < WIN_LEN)
		{
			iter = ft_iterate(i - c.x, j - c.y);
			color = ft_chose_color(iter);
			mlx_pixel_put_to_image(ptr.img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_destroy_image(ptr.mlx, ptr.img);
}
