/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:48:38 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/19 11:52:57 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <math.h>

# define MOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6

# define WIN_LEN 600
# define WIN_WID 800
# define MAX_ITER 100
# define RADIOUS 2

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
	double	x;
	double	y;
}				t_fpoint;

typedef struct	s_data
{
	enum
	{
		MANDLEBORT,
		JULIA,
		MANDLEBORT2,
		JULIA2
	}			type;
	t_fpoint	step;
	t_fpoint	start;
	t_fpoint	c_julia;
	t_point		center;
	t_mlx		ptr;
	int			color;
	int			palete[3][8];
}				t_data;

int				ft_chose_color(int iter, t_data *data);
void			ft_preset_paletes(int palete[][8]);

int				mlx_pixel_put_to_image(void *img, int x, int y, int clr);

void			ft_rezoom(int x, int y, t_data *data, char type);
void			ft_expose(t_data *data);
void			ft_preset_data(t_data *data);

#endif
