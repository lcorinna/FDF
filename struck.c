/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:25:35 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/17 19:31:36 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_creating_structures(char **arr, t_data *data, int i)
{
	char	**conv;
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		conv = ft_split(arr[i], ' ');
		if (conv == NULL)
			return (ft_clean_char_arr(conv, arr));
		data->map[i] = malloc(sizeof(t_elem) * data->width);
		while (conv[j])
		{
			data->map[i][j].height = ft_atoi_fdf(conv[j]);
			if (data->map[i][j].height == 2147483647)
				return (); //почистить все массивы и структуры
			//дойти до запятой если она есть и передать в хтои цвет
			// перевести из 16 в 10
			// data->map[i][j].color = ft_htoi(conv[j + res_atoi->lenght])
			// data->map[i][j].color
		}
		i++;
	}
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
