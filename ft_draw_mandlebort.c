/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandlebort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:44 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/05 15:29:13 by mchindri         ###   ########.fr       */
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

void	 ft_draw_mandlebort(t_mlx ptr)
{
	int		i;
	int		j;
	ptr.img = mlx_new_image(ptr.mlx, WIN_WID, WIN_LEN);
	
	t_point c;
	c.x = (4 / 7.) * WIN_WID;
	c.y = WIN_LEN / 2;
	double complex	z0;
	double complex	z;
//	double complex  temp;
	int				iter;
	int color;
	i = 0;
	while (i < WIN_WID)
	{
		j = 0;
		while (j < WIN_LEN)
		{
			z0 = (i - c.x) + I * (j - c.y);
		//	z = CMPLX(c.x, c.y);
			z = 0 + 0 * I;
			iter = 0;
			
			//NB(creal(z0));
			//NB(cimag(z0));
			while (cabs(z) < RADIOUS && iter < MAX_ITER)
			{
				z = creal(cpow(z, 2) + z0) + I * cimag(cpow(z, 2) + z0);
				iter++;
			}
			color = ft_chose_color(iter);
			mlx_pixel_put_to_image(ptr.img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_destroy_image(ptr.mlx, ptr.img);
}
