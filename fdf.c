/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:27:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/25 14:02:24 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i != data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
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
	printf("data->width %d\n", data.width); //dell
	printf("data->height %d\n\n", data.height); //dell
	data.map = malloc(sizeof(t_elem *) * data.height);
	if (data.map == NULL)
		return (1);
	if (ft_creating_structures(&data))
		return (1);
	if (ft_draw(&data, argv[1]))
		return (1);
	ft_clear_struct(&data);
	return (0);
}
