/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:25:35 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/22 17:14:55 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_django_unchained(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

int	ft_validation(t_data *data)
{
	int	j;
	int	pass;

	j = 0;
	while (data->conv[j])
	{
		pass = 0;
		data->map[data->i][j].height = ft_atoi_fdf(data->conv[j]);
		if (data->map[data->i][j].height == 2147483647)
			return (ft_clean_struct(data, 2));
		while (data->conv[j][pass] != '\0' && data->conv[j][pass] != ',')
			pass++;
		if (data->conv[j][pass] == ',')
			data->map[data->i][j].color = ft_htoi_fdf(&data->conv[j][++pass]);
		if (data->map[data->i][j].color == 255255256)
			return (ft_clean_struct(data, 3));
		else if (data->conv[j][pass] == '\0')
			data->map[data->i][j].color = 16777215;
		// printf("\nheight %d\n", data->map[data->i][j].height); //del
		// printf("color %d\n", data->map[data->i][j].color); //del
		j++;
	}
	return (0);
}

int	ft_creating_structures(t_data *data)
{
	int	f;

	data->i = 0;
	while (data->arr[data->i])
	{
		f = 0;
		data->conv = ft_split(data->arr[data->i], ' ');
		if (data->conv == NULL)
			return (ft_clean_char_arr(data));
		data->map[data->i] = malloc(sizeof(t_elem) * (data->width));
		if (data->map[data->i] == NULL)
			return (ft_clean_struct(data, 1));
		if (ft_validation(data))
			return (1);
		ft_django_unchained(data->conv);
		data->i++;
	}
	ft_django_unchained(data->arr);
	return (0);
}

long long	ft_number(char *done)
{
	long long	res;
	int			i;

	i = 0;
	res = 0;
	while (done[i] > 47 && done[i] < 58)
	{
		res = res * 10 + (done[i] - 48);
		i++;
	}
	return (res);
}

int	ft_atoi_fdf(char *s)
{
	long long	res;
	int			i;
	int			j;

	res = 0;
	i = 0;
	while ((s[i] == 32) || (s[i] > 8 && s[i] < 14))
		i++;
	j = i;
	while (s[j] && s[j] != ',')
	{
		if (s[j] == 45 || s[j] == 43)
			j++;
		if (s[j] < '0' || s[j++] > '9')
			return (2147483647);
	}
	if (s[i] == 45)
		res = (ft_number(&s[++i]) * (-1));
	else if (s[i] == 43)
		res = (ft_number(&s[++i]));
	else
		res = (ft_number(&s[i]));
	if (res > 2147483647 || res < -2147483648)
		return (2147483647);
	return (res);
}
