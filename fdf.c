/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:27:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/17 19:15:39 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	**arr;
	int		i;
	t_data	data;

	i = 0;
	arr = NULL;
	if (argc > 2 || argc < 2)
		return (ft_return_int_with_error(1));
	if (ft_check_extensions(argv[1]))
		return (ft_return_int_with_error(2));
	arr = ft_read_fdf(argv[1], arr, i, &data);
	if (arr == NULL)
		return (1);
	printf("data->width %d\n", data.width); //dell
	printf("data->height %d\n", data.height); //dell
	data.map = malloc(sizeof(t_elem *) * data.height);
	if malloc
	if (ft_creating_structures(arr, &data, i))
		return (1);
	free(data.map);
	return (0);
}
