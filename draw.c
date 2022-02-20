/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:00:12 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/20 19:27:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_draw(t_data *data)
{
	int		x;
	int		y;
	int		h;
	int		w;
	int		i;

	h = 0;
	w = 0;
	x = 0;
	y = 100;
	data->tmp.mlx = mlx_init();
	data->tmp.window = mlx_new_window(data->tmp.mlx, 1920, 1080, "FDF");
	while (w != data->width - 1)
	{
		i = 0;
		x = x + 100;
		while (i != 100)
		{
			mlx_pixel_put(data->tmp.mlx, data->tmp.window, x + i, y, data->map[h][w].color);
			i++;
		}
		w++;
	}
	while (h != data->height)
	{
		w = 0;
		x = 0;
		y = y + 100;
		while (w != data->width)
		{
			x = x + 100;
			i = 100;
			while (i != 0)
			{
				mlx_pixel_put(data->tmp.mlx, data->tmp.window, x, y - i, data->map[h][w].color);
				i--;
			}
			w++;
		}
		w = 0;
		x = 100;
		while (w != data->width - 1)
		{
			x = x + 100;
			i = 100;
			while (i != 0)
			{
				mlx_pixel_put(data->tmp.mlx, data->tmp.window, x - i, y, data->map[h][w].color);
				i--;
			}
			w++;
		}
		h++;
	}
	mlx_loop(data->tmp.mlx);
	return (0);
}


void	drawLine(int x1, int y1, int x2, int y2)
{
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	error;
	int	error2;


	if (x1 < x2)
		sign_x = 1;
	else if (x1 > x2)
		sign_x = -1;
	if (y1 < y2)
		sign_y = 1;
	else if (y1 > y2)
		sign_y = -1;
	delta_x = abs(x2 - x1);
	delta_y = abs(y2 - y1);
	error = delta_x - delta_y;
	error2 = error * 2;
	setPixel(x2, y2);
	while (x1 != x2 || y1 != y2)
	{
		setPixel(x1, y1);
		if (error2 > -delta_y)
		{
			error -= delta_y;
			x1 += sign_x;
		}
		if (error2 < delta_x)
		{
			error += delta_x;
			y1 += sign_y;
		}
	}
}

https://ru.wikibooks.org/wiki/%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D0%B8_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%91%D1%80%D0%B5%D0%B7%D0%B5%D0%BD%D1%85%D1%8D%D0%BC%D0%B0#%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F_%D0%BD%D0%B0_C++