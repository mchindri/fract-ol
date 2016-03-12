/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:48:38 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/12 18:53:13 by mchindri         ###   ########.fr       */
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

# define MOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6

//
	#include "debug.h"
//


# define PI (3.141592653589793)
# define WIN_LEN 600
# define WIN_WID 800
# define MAX_ITER 80
# define DIF 100
# define RADIOUS 2//0.7885
# define SHADOW 0
# define FI 1.618034

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

typedef struct	s_fpoint
{
	float	x;
	float	y;
}				t_fpoint;

typedef struct	s_data
{
	enum
	{
		MANDLEBORT,
		JULIA,
		TYPE
	}		e_type;
	t_fpoint	step;
	t_fpoint	start;
	t_fpoint new_step;
	t_point	center;
	t_point	new_coord;
	t_mlx	ptr;
	t_fpoint j;
	int		color;
	int		palete[3][8];
}				t_data;

int		ft_chose_color(int iter, t_data *data);
void	ft_preset_julia(t_data *data);
void	ft_preset_paletes(int palete[][8]);
void	ft_set_data(t_data *data);
void	ft_preset_mandlebort(t_data *data);
void	ft_draw_mandlebort(t_data *data);
void	ft_draw_julia(t_data *data);
int		mlx_pixel_put_to_image(void *img, int x, int y, int clr);
int		ft_set_color(unsigned char red, unsigned char gren, unsigned char blue);

#endif
