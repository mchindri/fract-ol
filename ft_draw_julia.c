/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandlebort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:25:44 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/12 18:54:26 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_data(t_data *data)
{
	t_fpoint	man_point;
	
	man_point.x = data->new_coord.x * data->step.x + data->start.x;	
	man_point.y = data->new_coord.y * data->step.y + data->start.y;


	data->step = data->new_step;


	data->start.x = man_point.x - data->step.x * (WIN_WID / 2);
	data->start.y = man_point.y - data->step.y * (WIN_LEN / 2);
}



void	ft_preset_mandlebort(t_data *data)
{
	data->color = 0;
	ft_preset_paletes(data->palete);
	data->step.x = 4.0 / WIN_WID;
	data->step.y = 2.0 / WIN_LEN;
	data->center.x = (WIN_WID / 2);
	data->center.y = (WIN_LEN / 2);
	data->start.x = (-1) * data->center.x * data->step.x;
	data->start.y = (-1) * data->center.y * data->step.y;
	data->j.x = 0;
	data->j.y = 0;
}

void	revert(float *a, float *x, float *b, float *y)
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

	x0 = data->j.x;
	y0 = data->j.y;
	//revert(&x, &y, &x0, &y0);
	//x0 = data->j.x;
	//y0 = data->j.y;
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

void	ft_draw_mandlebort(t_data *data)
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
