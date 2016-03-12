/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:53:54 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/12 18:53:12 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_set_color(unsigned char red, unsigned char green, unsigned char blue)
{
	int color;

	color = 0;
	color += blue;
	color += green << 8;
	color += red << 16;
	color += SHADOW << 24;
	return (color);
}

int		ft_mouse_hook(int button, int x, int y, t_data *data)
{
	NB(button)
		NB(x)
		NB(y)
	if (button == 4)
	{
		data->new_coord.x = x;
		data->new_coord.y = y;
		data->new_step.x = data->step.x / 1.5;
		data->new_step.y = data->step.y / 1.5;
		ft_set_data(data);
		ft_draw_mandlebort(data);
	}
	else if (button == 5 && data->step.x < 3.0 / WIN_WID)
	{
		data->new_coord.x = x;
		data->new_coord.y = y;
		data->new_step.x = data->step.x * 1.5;
		data->new_step.y = data->step.y * 1.5;
		ft_set_data(data);
		ft_draw_mandlebort(data);
	}
	else if (button == 1)
	{
		data->new_coord.x = x;
		data->new_coord.y = y;
	//	ft_set_data(data);
	//	ft_draw_mandlebort(data);
	}
	return (0);
}

int		ft_key_hook(int key, t_data *data)
{
	if (key == 53)
			exit(0);
	else if (key == 8)
	{
		data->color++;
		ft_draw_mandlebort(data);
	}
	if (key <= 126 && key >= 123)
	{
		if (key == 126)
			data->center.y += 50;	
		else if (key == 125)
			data->center.y -= 50;		
		else if (key == 123)
			data->center.x += 50;
		else if (key == 124)
			data->center.x -= 50;
		ft_set_data(data);
		ft_draw_mandlebort(data);
	}
	return (0);
}

int		ft_expose_hook(int x, int y, t_data *data)
{
	data->j.x = (x - data->center.x) * data->step.x;
	data->j.y = (y - data->center.y) * data->step.y;
//	ft_set_data(data);
	ft_draw_mandlebort(data);
	return (0);
}

void	ft_usage()
{
	ft_putstr("Usage:\n./fractol mandlebort\n./fractol julia\n./fractol da");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_data	data;
	char	fr;

	if (argc != 2)
		ft_usage();

	fr = 'm';
	if (ft_strcmp(argv[1], "mandlebort") == 0)
		fr = 'm';
	else if (ft_strcmp(argv[1], "julia") == 0)
		fr = 'j';
	else if (ft_strcmp(argv[1], "da") == 0)
		fr = 'd';
	else
		ft_usage();

	data.ptr.mlx = mlx_init();
	data.ptr.win = mlx_new_window(data.ptr.mlx, WIN_WID, WIN_LEN, "fractol");
	if (fr == 'm')
	{
		ft_preset_mandlebort(&data);
		ft_draw_mandlebort(&data);
	}
	/*else if (fr == 'j')
	{
		ft_preset_julia(&data);
		ft_draw_julia(&data);
	}*/
	mlx_hook(data.ptr.win, MOTIONNOTIFY, MOTIONMASK, ft_expose_hook, &data);
	mlx_key_hook(data.ptr.win, ft_key_hook, &data);
	mlx_mouse_hook(data.ptr.win, ft_mouse_hook, &data);
	mlx_loop(data.ptr.mlx);
	return (0);
}
