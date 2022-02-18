/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:27:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/18 19:23:02 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.arr = NULL;
	if (argc > 2 || argc < 2)
		return (ft_return_int_with_error(1));
	if (ft_check_extensions(argv[1]))
		return (ft_return_int_with_error(2));
	if (ft_read_fdf(argv[1], &data))
		return (1);
	printf("data->width %d\n", data.width); //dell
	printf("data->height %d\n\n", data.height); //dell
	data.map = malloc(sizeof(t_elem *) * data.height);
	printf("%lu sizeofpointer\n", sizeof(data.map));
	if (data.map == NULL)
		return (1);
	if (ft_creating_structures(&data))
		return (3);
	free(data.map);
	return (0);
}
