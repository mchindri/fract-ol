/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandlebort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:44 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/11 09:50:57 by mchindri         ###   ########.fr       */
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
	/*else if (iter % 3 == 0)
	  return (ft_set_color(255, 0, 0));
	  else if (iter % 3 == 1)
	  return (ft_set_color(0, 255, 0));
	  */	else 
	return (ft_set_color(0, 0, 255));
}

int		ft_iterate(int i, int j)
{
	double x;
	double y;
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

			z0 = CMPLX(i, j);
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

int		ft_iterate2(float x, float y)
{
	double complex	z0;
	double complex	z;
	int				iter;

	z0 = CMPLX(x, y);
	z = 0 + 0 * I;
	iter = 0;

//	dprintf(2,"cabs=%f\n",cabs(z));
	while (cabs(z) < RADIOUS && iter < MAX_ITER)
	{
		z = creal(cpow(z, 2) + z0) + I * cimag(cpow(z, 2) + z0);
		iter++;
	}
	return (iter);
}

void	ft_set_data(t_data *data)
{
	float x;
	float y;

	data->x_unit = WIN_WID / 3.0;
	data->y_unit = WIN_LEN / 2.0;
	data->x_step = 1.0 / data->x_unit;
	data->y_step = 1.0 / data->y_unit;
	data->center.x = (WIN_WID / 3) * 2;
	data->center.y = WIN_LEN / 2;
	x = data->center.x * data->x_step;
	x *= -1;
	y = data->center.y * data->y_step;
	y *= -1;
	data->start = CMPLX(x, y);	
}

void	 ft_draw_mandlebort(t_mlx ptr, t_data *data)
{
	t_point	count;
	float	x;
	float	y;
	int		iter;
	int		color;

	ptr.img = mlx_new_image(ptr.mlx, WIN_WID, WIN_LEN);
	ft_set_data(data);
  	count.x	= 0;
	x = creal(data->start);
	while (count.x < WIN_WID)
	{
		count.y = 0;
		y = cimag(data->start);
		while (count.y < WIN_LEN)
		{

			iter = ft_iterate2(x, y);
			color = ft_chose_color(iter);
			mlx_pixel_put_to_image(ptr.img, count.x, count.y, color);
			count.y++;
			y += data->y_step;
		}
		x += data->x_step;
		count.x++;
	}
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_destroy_image(ptr.mlx, ptr.img);
}
