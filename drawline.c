/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/22 19:30:44 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_drawLine(int x1, int y1, int x2, int y2, t_data *data)
// {
// 	t_drawLine	params;

// 	if (x1 < x2)
// 		params.sign_x = 1;
// 	else if (x1 > x2)
// 		params.sign_x = -1;
// 	if (y1 < y2)
// 		params.sign_y = 1;
// 	else if (y1 > y2)
// 		params.sign_y = -1;
// 	params.delta_x = abs(x2 - x1);
// 	params.delta_y = abs(y2 - y1);
// 	params.error = params.delta_x - params.delta_y;
// 	params.error2 = params.error * 2;
// 	while (x1 != x2 || y1 != y2)
// 	{
// 		my_mlx_pixel_put(&data->img, x1, y1, data);
// 		if (params.error2 > -params.delta_y)
// 		{
// 			params.error -= params.delta_y;
// 			x1 += params.sign_x;
// 		}
// 		if (params.error2 < params.delta_x)
// 		{
// 			params.error += params.delta_x;
// 			y1 += params.sign_y;
// 		}
// 	}
// }

void	ft_draw_x(t_data *data)
{
	data->tmp.y = 0;
	while (data->tmp.y != data->height)
	{
		data->tmp.x = 0;
		while (data->tmp.x != (data->width - 1))
		{
			ft_drawLine_x(data->tmp.x * data->st, data->tmp.y * data->st, \
			(data->tmp.x + 1) * data->st, data->tmp.y * data->st, data);
			data->tmp.x++;
		}
		data->tmp.y++;
	}
}

void	ft_draw_y(t_data *data)
{
	data->tmp.x = 0;
	while (data->tmp.x != data->width)
	{
		data->tmp.y = 0;
		while (data->tmp.y != (data->height - 1))
		{
			ft_drawLine_y(data->tmp.x * data->st, data->tmp.y * data->st, \
			data->tmp.x * data->st, (data->tmp.y + 1) * data->st, data);
			data->tmp.y++;
		}
		data->tmp.x++;
	}
}
