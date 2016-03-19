/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:15:09 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/19 11:55:08 by mchindri         ###   ########.fr       */
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
	data->step.y = 2.0 / WIN_LEN;
	data->center.y = WIN_LEN / 2;
	if (data->type == MANDLEBORT)
	{
		data->step.x = 3.0 / WIN_WID;
		data->center.x = (WIN_WID / 3) * 2;
	}
	else if (data->type == JULIA || data->type == JULIA2)
	{
		data->step.x = 4.0 / WIN_WID;
		data->center.x = WIN_WID / 2;
	}
	else
	{
		data->step.y = 4.0 / WIN_LEN;
		data->step.x = 6.0 / WIN_WID;
		data->center.y = (WIN_LEN / 2);
		data->center.x = (WIN_WID / 3) - 50;
	}
	data->start.x = (-1) * data->center.x * data->step.x;
	data->start.y = (-1) * data->center.y * data->step.y;
}

void	ft_set_z_and_c(double *x, double *y, t_fpoint *z0, t_data *data)
{
	double aux;

	aux = *x * *x + *y * *y;
	z0->x = data->c_julia.x;
	z0->y = data->c_julia.y;
	if (data->type == MANDLEBORT)
	{
		z0->x = *x;
		z0->y = *y;
		*x = 0.0;
		*y = 0.0;
	}
	else if (data->type == MANDLEBORT2)
	{
		z0->x = *x / aux;
		z0->y = ((-1) * *y) / aux;
		*x = 0.0;
		*y = 0.0;
	}
	else if (data->type == JULIA2)
	{
		*x = *x / aux;
		*y = ((-1) * *y) / aux;
	}
}

int		ft_iterate(double x, double y, t_data *data)
{
	int			iter;
	t_fpoint	z0;
	double		temp;

	ft_set_z_and_c(&x, &y, &z0, data);
	iter = 0;
	while (x * x + y * y < RADIOUS * RADIOUS && iter < MAX_ITER)
	{
		temp = x * x - y * y + z0.x;
		y = 2 * x * y + z0.y;
		x = temp;
		iter = iter + 1;
	}
	return (iter);
}

void	ft_expose(t_data *data)
{
	t_point		count;
	t_fpoint	coord;
	int			iter;
	int			color;

	data->ptr.img = mlx_new_image(data->ptr.mlx, WIN_WID, WIN_LEN);
	count.x = 0;
	coord.x = data->start.x;
	while (count.x < WIN_WID)
	{
		count.y = 0;
		coord.y = data->start.y;
		while (count.y < WIN_LEN)
		{
			iter = ft_iterate(coord.x, coord.y, data);
			color = ft_chose_color(iter, data);
			mlx_pixel_put_to_image(data->ptr.img, count.x, count.y, color);
			count.y++;
			coord.y += data->step.y;
		}
		coord.x += data->step.x;
		count.x++;
	}
	mlx_put_image_to_window(data->ptr.mlx, data->ptr.win, data->ptr.img, 0, 0);
	mlx_destroy_image(data->ptr.mlx, data->ptr.img);
}
