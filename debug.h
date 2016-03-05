/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:37:02 by mchindri          #+#    #+#             */
/*   Updated: 2016/02/01 16:38:46 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEB
# define DEB

#include <stdio.h>
#include "libft.h"

#define OK write(1, "ok\n", 3);
#define FAIL write(1, "fail\n", 5);
#define NB(x) {ft_putstr(#x "=");\
				ft_putnbr(x);\
				ft_putchar('\n');}
#define _CH(x) {ft_putstr(#x "=");\
				ft_putchar(x);\
				ft_putchar('\n');}
#define _STR(x) {ft_putstr(#x "=");\
				ft_putstr(x);}
#define _STRN(x) ft_putstr(#x "="),ft_putendl(x);

#define CH(x) {	ft_putchar(x);\
				ft_putchar('\n');}
#define STR(x) ft_putstr(x);
#define STRN(x) ft_putendl(x);


#endif
