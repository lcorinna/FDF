/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:38:21 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/17 18:52:49 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_extensions(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == 'f' && str[i + 1] == 'd' && str[i + 2] == 'f' \
	&& str[i + 3] == '\0')
		return (0);
	return (1);
}

int	ft_counting_spaces(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != '\0')
		{
			size++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				size--;
			i--;
		}
		i++;
	}
	return (size);
}

int	ft_chek_on_size(char **arr, t_data *data)
{
	int	j;
	int	size;
	int	standard;

	size = 0;
	standard = 0;
	if (arr[1] == NULL)
		return (1);
	standard = ft_counting_spaces(arr[0]);
	j = 1;
	while (arr[j])
	{
		size = ft_counting_spaces(arr[j]);
		if (standard != size)
			return (1);
		j++;
	}
	data->height = j;
	data->width = 1 + standard;
	return (0);
}

int	ft_chek_str(char **arr, t_data *data)
{
	if (ft_chek_on_size(arr, data))
		return (ft_return_int_with_error(3));
	return (0);
}
