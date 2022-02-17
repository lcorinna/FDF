/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:49:10 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/17 17:54:55 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_return_int_with_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("Check the number of arguments\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Invalid file extension\n", 2);
	else if (flag == 3)
		ft_putstr_fd("Just give me four 90 degree angles\n", 2);
	return (1);
}

char	*ft_return_null(char *str, char *buf, int flag)
{
	if (str != NULL)
		free(str);
	if (buf != NULL)
		free(buf);
	if (flag == 1)
		ft_putstr_fd("\"Strjoin\" sneezed and ", 2);
	return (NULL);
}

char	**ft_return_char_with_error(int flag, int fd)
{
	if (flag == 1)
		ft_putstr_fd("The file could not be opened, fd is \"-1\"\n", 2);
	else if (flag == 2)
		ft_putstr_fd("\"GNL\" got sick, and we were counting on him\n", 2);
	else if (flag == 3)
		ft_putstr_fd("\"Split\" chose the dark side\n", 2);
	if (fd != 0)
		close (fd);
	return (NULL);
}

int	ft_clean_char_arr(char **conv, char **arr)
{
	int	i;

	i = 0;
	if (conv != NULL)
	{
		while (conv[i])
		{
			free(conv[i]);
			i++;
		}
		free(conv);
	}
	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (1);
}
