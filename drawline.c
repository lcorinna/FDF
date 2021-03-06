/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 12:05:21 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(1);
	*y = (*x + *y) * sin(0.8) - z;
}

void	ft_take_step(float *x2, float *y2, t_data *data)
{
	data->draw.x1 *= data->tmp.st;
	data->draw.y1 *= data->tmp.st;
	*x2 *= data->tmp.st;
	*y2 *= data->tmp.st;
}

void	ft_moving(float *x2, float *y2, t_data *data)
{
	data->draw.x1 += data->tmp.shift_x;
	data->draw.y1 += data->tmp.shift_y;
	*x2 += data->tmp.shift_x;
	*y2 += data->tmp.shift_y;
}

void	ft_brasenham(float x2, float y2, t_data *data)
{
	data->draw.z2 = data->map[(int)y2][(int)x2].height;
	ft_take_step(&x2, &y2, data);
	if (data->i == 2)
	{
		ft_isometric(&data->draw.x1, &data->draw.y1, data->draw.z1);
		ft_isometric(&x2, &y2, data->draw.z2);
	}
	ft_moving(&x2, &y2, data);
	data->draw.x_step = x2 - data->draw.x1 ;
	data->draw.y_step = y2 - data->draw.y1;
	data->draw.max = fmax(fabs(data->draw.x_step), fabs(data->draw.y_step));
	data->draw.x_step /= data->draw.max;
	data->draw.y_step /= data->draw.max;
	while ((int)(data->draw.x1 - x2) || (int)(data->draw.y1 - y2))
	{
		if (data->draw.x1 < 0 || data->draw.x1 > WIDTH \
		|| data->draw.y1 < 0 || data->draw.y1 > HEIGHT)
			return ;
		my_mlx_pixel_put(data, data->draw.x1, \
		data->draw.y1, data->draw.color);
		data->draw.x1 += data->draw.x_step;
		data->draw.y1 += data->draw.y_step;
	}
}

void	ft_drawline(t_data *data)
{
	data->tmp.y = 0;
	data->img.img = mlx_new_image(data->tmp.mlx, WIDTH, HEIGHT);
	if (data->img.img == NULL)
		ft_clear_arr_struct(data, 3);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	while (data->tmp.y < data->height)
	{
		data->tmp.x = 0;
		while (data->tmp.x < data->width)
		{
			data->draw.z1 = data->map[data->tmp.y][data->tmp.x].height;
			data->draw.color = data->map[data->tmp.y][data->tmp.x].color;
			data->draw.x1 = (float)data->tmp.x;
			data->draw.y1 = (float)data->tmp.y;
			if (data->tmp.x < data->width - 1)
				ft_brasenham(data->tmp.x + 1, data->tmp.y, data);
			data->draw.x1 = (float)data->tmp.x;
			data->draw.y1 = (float)data->tmp.y;
			if (data->tmp.y < data->height - 1)
				ft_brasenham(data->tmp.x, data->tmp.y + 1, data);
			data->tmp.x++;
		}
		data->tmp.y++;
	}	
	mlx_put_image_to_window(data->tmp.mlx, data->tmp.win, data->img.img, 0, 0);
	mlx_destroy_image(data->img.img, data->img.addr);
}
