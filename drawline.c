/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/25 19:31:40 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.8) - z;
}

void	ft_brasenham(float x1, float y1, float x2, float y2, t_data *data)
{
	double	x_step;
	double	y_step;
	double	max;
	int		z1;
	int		z2;
	int 	color;

	z1 = data->map[(int)y1][(int)x1].height;
	z2 = data->map[(int)y2][(int)x2].height;
	color = data->map[(int)y1][(int)x1].color;

	x1 *= data->st;
	y1 *= data->st;
	x2 *= data->st;
	y2 *= data->st;

	ft_isometric(&x1, &y1, z1);
	ft_isometric(&x2, &y2, z2);

	x1 += data->shift_x;
	y1 += data->shift_y;
	x2 += data->shift_x;
	y2 += data->shift_y;

	x_step = x2 - x1;
	y_step = y2 - y1;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		if (x1 < 0 || x1 > 1919 || y1 < 0 || y1 > 1079)
			return ;
		mlx_pixel_put(data->tmp.mlx, data->tmp.win, x1, y1, color);
		x1 += x_step;
		y1 += y_step;
	}
}

void	ft_drawline(t_data *data)
{
	int	x1;
	int	y1;

	y1 = 0;
	while (y1 < data->height)
	{
		x1 = 0;
		while (x1 < data->width)
		{
			if (x1 < data->width - 1)
				ft_brasenham(x1, y1, x1 + 1, y1, data);
			if (y1 < data->height - 1)
				ft_brasenham(x1, y1, x1, y1 + 1, data);
			x1++;
		}
		y1++;
	}	
}
