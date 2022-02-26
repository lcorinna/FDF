/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:00:12 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/26 16:32:54 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_size_step(t_data *data)
{
	int	step[2];

	step[0] = WIDTH / (data->width - 1);
	step[1] = HEIGHT / (data->height - 1);
	data->tmp.st = step[0];
	if (data->tmp.st > step[1])
		data->tmp.st = step[1];
	data->tmp.shift_x = 750;
	data->tmp.shift_y = 150;
}

void	my_mlx_pixel_put(t_pix *img, int x, int y, t_data *data)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = data->map[data->tmp.y][data->tmp.x].color;
}

void	ft_program_completion(t_data *data)
{
	ft_clear_arr_struct(data, 0);
	exit (0);
}

int	ft_buttons(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->tmp.mlx, data->tmp.win);
		ft_program_completion(data);
	}
	else if (key >= 123 && key <= 126)
	{
		if (key == 126)
			data->tmp.shift_y -= MOVE;
		else if (key == 125)
			data->tmp.shift_y += MOVE;
		else if (key == 123)
			data->tmp.shift_x -= MOVE;
		else if (key == 124)
			data->tmp.shift_x += MOVE;
		mlx_clear_window(data->tmp.mlx, data->tmp.win);
		ft_drawline(data);
	}
	else if (key >= 0 && key <= 273)
		key++;
	else
		exit (0);
	return (0);
}

int	ft_draw(t_data *data, char *name)
{
	ft_size_step(data);
	data->tmp.mlx = mlx_init();
	if (data->tmp.mlx == NULL)
		return (1);
	data->tmp.win = mlx_new_window(data->tmp.mlx, WIDTH, HEIGHT, name);
	if (data->tmp.win == NULL)
		return (1);
	data->img.img = mlx_new_image(data->tmp.mlx, WIDTH, HEIGHT);
	if (data->img.img == NULL)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	mlx_put_image_to_window(data->tmp.mlx, data->tmp.win, data->img.img, 0, 0);
	ft_drawline(data);
	mlx_hook(data->tmp.win, 2, (1L << 0), ft_buttons, data);
	mlx_hook(data->tmp.win, 17, (1L << 0), ft_buttons, data);
	mlx_loop(data->tmp.mlx);
	return (0);
}
