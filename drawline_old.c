/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:38:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/24 18:28:21 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_drawline_branch(t_drawline *params, t_data *data)
// {
// 	printf("params->x1(%d) != params->x2(%d) || params->y1(%d) != params->y2(%d)\n", params->x1, params->x2, params->y1, params->y2); //del
// 	while (params->x1 != params->x2 || params->y1 != params->y2)
// 	{
// 		if (params->x1 >= 0 && params->x1 < 1920 && params->y1 >= 0 && params->y1 < 1080)
// 			my_mlx_pixel_put(&data->img, params->x1, params->y1, data);
// 		if (params->error2 > -params->delta_y)
// 		{
// 			params->error -= params->delta_y;
// 			params->x1 += params->sign_x;
// 		}
// 		if (params->error2 < params->delta_x)
// 		{
// 			params->error += params->delta_x;
// 			params->y1 += params->sign_y;
// 		}
// 	}
// }

// void	ft_drawline(t_drawline *params, t_data *data)
// {
// 	if (params->x1 < params->x2)
// 		params->sign_x = 1;
// 	else if (params->x1 > params->x2)
// 		params->sign_x = -1;
// 	if (params->y1 < params->y2)
// 		params->sign_y = 1;
// 	else if (params->y1 > params->y2)
// 		params->sign_y = -1;
// 	params->delta_x = abs(params->x2 - params->x1);
// 	params->delta_y = abs(params->y2 - params->y1);
// 	params->error = params->delta_x - params->delta_y;
// 	params->error2 = params->error * 2;
// 	ft_drawline_branch(params, data);
// }

// void	ft_draw_x(t_data *data)
// {
// 	t_drawline	params;
// 	int			tmp;

// 	data->tmp.y = 0;
// 	while (data->tmp.y != data->height)
// 	{
// 		data->tmp.x = 0;
// 		while (data->tmp.x != (data->width - 1))
// 		{
// 			params.x1 = data->tmp.x * data->st;
// 			params.y1 = data->tmp.y * data->st;
// 			params.x2 = (data->tmp.x + 1) * data->st;
// 			params.y2 = data->tmp.y * data->st;

// 			tmp = params.x1;
// 			params.x1 = params.x1 - params.y1;
// 			params.y1 = (tmp + params.y1) / 2 - \
// 			data->map[data->tmp.y][data->tmp.x].height;
// 			tmp = params.x2;
// 			params.x2 = params.x2 - params.y2;
// 			params.y2 = (tmp + params.y2) / 2 - \
// 			data->map[data->tmp.y][data->tmp.x].height;
// 			params.y1 = abs(params.y1);
// 			ft_drawline(&params, data);
// 			data->tmp.x++;
// 		}
// 		data->tmp.y++;
// 	}
// }

// void	ft_draw_y(t_data *data)
// {
// 	t_drawline	params;

// 	data->tmp.x = 0;
// 	while (data->tmp.x != data->width)
// 	{
// 		data->tmp.y = 0;
// 		while (data->tmp.y != (data->height - 1))
// 		{
// 			params.x1 = data->tmp.x * data->st;
// 			params.y1 = data->tmp.y * data->st;
// 			params.x2 = data->tmp.x * data->st;
// 			params.y2 = (data->tmp.y + 1) * data->st;
// 			ft_drawline(&params, data);
// 			data->tmp.y++;
// 		}
// 		data->tmp.x++;
// 	}
// }
