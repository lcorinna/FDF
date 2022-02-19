/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:08:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/19 17:55:12 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long long	ft_check_on_hex(char *str)
{
	int	i;
	int	bingo;

	i = 0;
	bingo = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 96) \
		|| (str[i] >= 103 && str[i] <= 127))
			return (1);
		if (str[i] == '0')
			bingo++;
		i++;
	}
	if (bingo == 6)
		return (1);
	return (0);
}

int	ft_degree(int i)
{
	int	res;

	res = 16;
	if (i == 0)
		return (1);
	while (i != 1)
	{
		res *= 16;
		i--;
	}
	return (res);
}

void	ft_part_hex_to_dec(int *dec, int j, char c)
{
	if (c == 'a')
		*dec += 10 * ft_degree(j);
	else if (c == 'b')
		*dec += 11 * ft_degree(j);
	else if (c == 'c')
		*dec += 12 * ft_degree(j);
	else if (c == 'd')
		*dec += 13 * ft_degree(j);
	else if (c == 'e')
		*dec += 14 * ft_degree(j);
	else if (c == 'f')
		*dec += 15 * ft_degree(j);
}

void	ft_hex_to_dec(char *str, int *dec)
{
	int		i;
	int		j;
	int		atoi;

	i = 0;
	j = 5;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			ft_part_hex_to_dec(dec, j, str[i]);
		else if (str[i] == '0')
			*dec += 0;
		else if (str[i] >= '1' && str[i] <= '9')
		{
			atoi = str[i] - 48;
			*dec += atoi * ft_degree(j);
		}
		j--;
		i++;
	}
}

int	ft_htoi_fdf(char *s)
{
	int	i;

	i = 0;
	if ((s[0] != '0' && s[1] != 'x') || (ft_strlen(s) != 8))
		return (255255256);
	if (ft_check_on_hex(s + 2))
		return (255255256);
	ft_hex_to_dec(s + 2, &i);
	return (i);
}
