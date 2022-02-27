/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:27:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/27 17:11:14 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_clear_arr_struct(t_data *data, int flag)
{
	int	i;

	i = 0;
	while (i != data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	if (flag == 1)
		ft_putstr_fd("An error occurred when filling in an array of structures. \
		\nInhale, exhale and try again, by the way, \
		I freed up all allocated memory.\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Who wrote the MLX library?\nIt doesn't work\n", 2);
	else if (flag == 3)
	{
		ft_putstr_fd("Who wrote the MLX library?\nIt doesn't work\n", 2);
		exit (1);
	}
	if (flag > 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2 || argc < 2)
		return (ft_return_int_with_error(1));
	if (ft_check_extensions(argv[1]))
		return (ft_return_int_with_error(2));
	if (ft_read_fdf(argv[1], &data))
		return (1);
	data.map = malloc(sizeof(t_elem *) * data.height);
	if (data.map == NULL)
		return (1);
	if (ft_creating_structures(&data))
		return (ft_clear_arr_struct(&data, 1));
	if (ft_draw(&data, argv[1]))
		return (ft_clear_arr_struct(&data, 2));
	ft_clear_arr_struct(&data, 0);
	return (0);
}
