/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:00:12 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/25 19:26:50 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_size_step(t_data *data)
{
	int	step[2];

	step[0] = 1920 / (data->width - 1);
	step[1] = 1080 / (data->height - 1);
	data->st = step[0];
	if (data->st > step[1])
		data->st = step[1];
	printf("data->step - %d\n", data->st); //del
}

void	my_mlx_pixel_put(t_pix *img, int x, int y, t_data *data)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = data->map[data->tmp.y][data->tmp.x].color;
}

int	ft_buttons(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->tmp.mlx, data->tmp.win);
		exit (0); //del
	}
	else if (key >= 123 && key <= 126)
	{
		if (key == 126)
			data->shift_y -= 10;
		else if (key == 125)
			data->shift_y += 10;
		else if (key == 123)
			data->shift_x -= 10;
		else if (key == 124)
			data->shift_x += 10;
		mlx_clear_window(data->tmp.mlx, data->tmp.win); //удалить при повороте
		ft_drawline(data);
	}
	else if (key >= 0 && key <= 273)
		key++;
	else
		exit (0); //del
	return (0);
}

int	ft_draw(t_data *data, char *name)
{
	ft_size_step(data);
	data->shift_x = 700;
	data->shift_y = 300;
	data->tmp.mlx = mlx_init(); //запуск движка (программа для графики)
	data->tmp.win = mlx_new_window(data->tmp.mlx, 1920, 1080, name); //окно
	data->img.img = mlx_new_image(data->tmp.mlx, 1920, 1080); //создать картинку
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	mlx_put_image_to_window(data->tmp.mlx, data->tmp.win, data->img.img, 0, 0);
	ft_drawline(data);
	mlx_hook(data->tmp.win, 17, (1L << 0), ft_buttons, data);
	mlx_hook(data->tmp.win, 2, (1L << 0), ft_buttons, data);
	mlx_loop(data->tmp.mlx);
	return (0);
}

// https://ru.wikibooks.org/wiki/%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D0%B8_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%91%D1%80%D0%B5%D0%B7%D0%B5%D0%BD%D1%85%D1%8D%D0%BC%D0%B0#%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F_%D0%BD%D0%B0_C++