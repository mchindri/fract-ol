/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:53:54 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/19 11:53:12 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		ft_rezoom(x, y, data, '+');
		ft_expose(data);
	}
	else if (button == 5)
	{
		ft_rezoom(x, y, data, '-');
		ft_expose(data);
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
		ft_expose(data);
	}
	if (key <= 126 && key >= 123)
	{
		if (key == 126)
			data->start.y -= 50 * data->step.y;
		else if (key == 125)
			data->start.y += 50 * data->step.y;
		else if (key == 123)
			data->start.x -= 50 * data->step.x;
		else if (key == 124)
			data->start.x += 50 * data->step.x;
		ft_expose(data);
	}
	return (0);
}

int		ft_expose_hook(int x, int y, t_data *data)
{
	data->c_julia.x = (x - data->center.x) * data->step.x;
	data->c_julia.y = (y - data->center.y) * data->step.y;
	ft_expose(data);
	return (0);
}

void	ft_usage(void)
{
	ft_putstr("Usage:\n");
	ft_putstr("./fractol mandlebort\n./fractol mandlebort2\n");
	ft_putstr("./fractol julia\n./fractol julia2\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_usage();
	if (ft_strcmp(argv[1], "mandlebort") == 0)
		data.type = MANDLEBORT;
	else if (ft_strcmp(argv[1], "julia") == 0)
		data.type = JULIA;
	else if (ft_strcmp(argv[1], "mandlebort2") == 0)
		data.type = MANDLEBORT2;
	else if (ft_strcmp(argv[1], "julia2") == 0)
		data.type = JULIA2;
	else
		ft_usage();
	data.ptr.mlx = mlx_init();
	data.ptr.win = mlx_new_window(data.ptr.mlx, WIN_WID, WIN_LEN, "fractol");
	ft_preset_data(&data);
	ft_expose(&data);
	mlx_hook(data.ptr.win, MOTIONNOTIFY, MOTIONMASK, ft_expose_hook, &data);
	mlx_key_hook(data.ptr.win, ft_key_hook, &data);
	mlx_mouse_hook(data.ptr.win, ft_mouse_hook, &data);
	mlx_loop(data.ptr.mlx);
	return (0);
}
