/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 13:23:23 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/19 09:53:03 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_chose_color(int iter, t_data *data)
{
	if (iter == MAX_ITER)
		return (0);
	else
		return (data->palete[data->color % 3][iter % 8]);
}

void	ft_preset_paletes(int palete[][8])
{
	palete[0][0] = 0xff0000;
	palete[0][1] = 0xff8000;
	palete[0][2] = 0xffff00;
	palete[0][3] = 0x80ff00;
	palete[0][4] = 0xccff99;
	palete[0][5] = 0x99ff99;
	palete[0][6] = 0x99ffcc;
	palete[0][7] = 0x99ffff;
	palete[1][0] = 0x8000ff;
	palete[1][1] = 0x0000ff;
	palete[1][2] = 0x0080ff;
	palete[1][3] = 0x00ffff;
	palete[1][4] = 0xff9999;
	palete[1][5] = 0xff99cc;
	palete[1][6] = 0xff99ff;
	palete[1][7] = 0xcc99ff;
	palete[2][0] = 0x00cc00;
	palete[2][1] = 0x33ff00;
	palete[2][2] = 0x66cc00;
	palete[2][3] = 0x999933;
	palete[2][4] = 0xcc9933;
	palete[2][5] = 0xcc6699;
	palete[2][6] = 0xff66cc;
	palete[2][7] = 0xffcccc;
}
