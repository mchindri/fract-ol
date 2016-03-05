/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 12:53:54 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/05 14:55:44 by mchindri         ###   ########.fr       */
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


int		ft_key_hook(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_usage()
{
	ft_putstr("Usage:\n./fractol mandlebort\n./fractol julia\n./fractol da");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_s		e;
	t_mlx	ptr;
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

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIN_WID, WIN_LEN, "fractol");
	if (fr == 'm')
		ft_draw_mandlebort(ptr);
	mlx_key_hook(ptr.win, ft_key_hook, &e);
	mlx_loop(ptr.mlx);
	return (0);
}
