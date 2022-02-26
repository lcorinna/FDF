/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:08:02 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/26 13:38:21 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (c == 'a' || c == 'A')
		*dec += 10 * ft_degree(j);
	else if (c == 'b' || c == 'B')
		*dec += 11 * ft_degree(j);
	else if (c == 'c' || c == 'C')
		*dec += 12 * ft_degree(j);
	else if (c == 'd' || c == 'D')
		*dec += 13 * ft_degree(j);
	else if (c == 'e' || c == 'E')
		*dec += 14 * ft_degree(j);
	else if (c == 'f' || c == 'F')
		*dec += 15 * ft_degree(j);
}

void	ft_hex_to_dec(char *str, int *dec)
{
	int		i;
	int		j;
	int		atoi;

	i = 0;
	j = 5;
	if (ft_strlen(str) == 8)
		i = 2;
	else
		j = (ft_strlen(str) - 1);
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'f') \
		|| (str[i] >= 'A' && str[i] <= 'F'))
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
	if ((s[0] != '0' && s[1] != 'x'))
		return (255255256);
	if (ft_check_on_hex(s + 2))
		return (255255256);
	ft_hex_to_dec(s + 2, &i);
	return (i);
}
