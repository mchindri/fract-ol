/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:15:09 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/18 11:04:42 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_rezoom(int x, int y, t_data *data, char type)
{	
	t_fpoint	cmplx_point;

	cmplx_point.x = x * data->step.x + data->start.x;
	cmplx_point.y = y * data->step.y + data->start.y;
	if (type == '-')
	{
		data->step.x *= 1.5;
		data->step.y *= 1.5;
	}
	else
	{
		data->step.x /= 1.5;
		data->step.y /= 1.5;
	}
	data->start.x = cmplx_point.x - x * data->step.x;
	data->start.y = cmplx_point.y - y * data->step.y;
}

void	ft_preset_data(t_data *data)
{
	data->color = 0;
	ft_preset_paletes(data->palete);
	if (data->type == MANDLEBORT)
	{
		data->step.x = 3.0 / WIN_WID;
		data->center.x = (WIN_WID / 3) * 2;
	}
	else
	{
		data->step.x = 4.0 / WIN_WID;
		data->center.x = WIN_WID / 2;
	}
	data->step.y = 2.0 / WIN_LEN;
	data->center.y = WIN_LEN / 2;
	data->start.x = (-1) * data->center.x * data->step.x;
	data->start.y = (-1) * data->center.y * data->step.y;
}

void	ft_double_swap(float *a, float *x, float *b, float *y)
{
	float aux;

	aux = *a;
	*a = *b;
	*b = aux;
	aux =*x;
	*x  = *y;
	*y = aux;
}

int		ft_iterate(float x, float y, t_data *data)
{
	int		iter;
	float	x0;
	float	y0;
	float	temp;

	if (data->type == JULIA)
	{
		x0 = data->c_julia.x;
		y0 = data->c_julia.y;
	}
	else
	{
		x0 = 0.0;
		y0 = 0.0;
		ft_double_swap(&x, &y, &x0, &y0);
	}
	iter = 0;
	while (x * x + y * y < RADIOUS * RADIOUS  &&  iter < MAX_ITER)
	{
		temp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = temp;
		iter = iter + 1;
	}
	return (iter);
}

void ft_expose(t_data *data)
{
	t_point	count;
	float	x;
	float	y;
	int		iter;
	int		color;

	data->ptr.img = mlx_new_image(data->ptr.mlx, WIN_WID, WIN_LEN);
	count.x	= 0;
	x = data->start.x;
	while (count.x < WIN_WID)
	{
		count.y = 0;
		y = data->start.y;
		while (count.y < WIN_LEN)
		{
			iter = ft_iterate(x, y, data);
			color = ft_chose_color(iter, data);
			mlx_pixel_put_to_image(data->ptr.img, count.x, count.y, color);
			count.y++;
			y += data->step.y;
		}
		x += data->step.x;
		count.x++;
	}
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
	mlx_destroy_image(data->ptr.mlx, data->ptr.img);
}
