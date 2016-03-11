/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:48:38 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/11 09:51:00 by mchindri         ###   ########.fr       */
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
# define MAX_ITER 100
# define DIF 100
# define RADIOUS 2 
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

typedef struct	s_data
{
	enum
	{
		MANDLEBORT,
		JULIA,
		TYPE
	}		e_type;
	float	x_unit;
	float	y_unit;
	float	x_step;
	float	y_step;
	float	zoom;
	float complex start;
	t_point	center;

}				t_data;

void	ft_draw_mandlebort(t_mlx ptr, t_data *data);
int		mlx_pixel_put_to_image(void *img, int x, int y, int clr);
int		ft_set_color(unsigned char red, unsigned char gren, unsigned char blue);

#endif
