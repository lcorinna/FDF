/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:38:21 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/22 19:15:35 by lcorinna         ###   ########.fr       */
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

int	ft_chek_on_size(t_data *data)
{
	int	i;
	int	size;
	int	standard;

	size = 0;
	standard = 0;
	if (data->arr[1] == NULL)
		return (1);
	standard = ft_counting_spaces(data->arr[0]);
	i = 1;
	while (data->arr[i])
	{
		size = ft_counting_spaces(data->arr[i]);
		if (standard != size)
			return (1);
		i++;
	}
	data->height = i;
	data->width = 1 + standard;
	return (0);
}

int	ft_chek_str(t_data *data)
{
	if (ft_chek_on_size(data))
	{
		ft_django_unchained(data->arr);
		return (ft_return_int_with_error(3));
	}
	if (data->height == 1)
		return (ft_return_int_with_error(3));
	if (data->width == 1)
		return (ft_return_int_with_error(3));
	return (0);
}

long long	ft_check_on_hex(char *str)
{
	int	i;
	int	bingo;

	i = 0;
	bingo = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) \
		|| (str[i] >= 71 && str[i] <= 96) || (str[i] >= 103 && str[i] <= 127))
			return (1);
		if (str[i] == '0')
			bingo++;
		i++;
	}
	if (bingo == 6)
		return (1);
	return (0);
}
