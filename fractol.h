/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:48:38 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/05 16:14:19 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <complex.h>
# include <fenv.h>
# include <float.h>

//
	#include "debug.h"
//


# define WIN_LEN 500
# define WIN_WID 700
# define MAX_ITER 90
# define DIF 100
# define RADIOUS 100
# define SHADOW 0

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_point
{
	int	x;
	int y;
}				t_point;

typedef struct	s_s
{
	int a;
}				t_s;

void	ft_draw_mandlebort(t_mlx ptr);
int		mlx_pixel_put_to_image(void *img, int x, int y, int clr);
int		ft_set_color(unsigned char red, unsigned char gren, unsigned char blue);

#endif
