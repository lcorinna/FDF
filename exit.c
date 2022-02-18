/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:49:10 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/18 19:30:43 by lcorinna         ###   ########.fr       */
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

int	ft_return_close_with_error(int flag, int fd)
{
	if (flag == 1)
		ft_putstr_fd("The file could not be opened, fd is \"-1\"\n", 2);
	else if (flag == 2)
		ft_putstr_fd("\"GNL\" got sick, and we were counting on him\n", 2);
	else if (flag == 3)
		ft_putstr_fd("\"Split\" chose the dark side\n", 2);
	if (fd != 0)
		close (fd);
	return (1);
}

int	ft_clean_char_arr(t_data *data)
{
	int	i;

	i = 0;
	if (data->conv != NULL)
	{
		while (data->conv[i])
		{
			free(data->conv[i]);
			i++;
		}
		free(data->conv);
	}
	if (data->arr != NULL)
	{
		i = 0;
		while (data->arr[i])
		{
			free(data->arr[i]);
			i++;
		}
		free(data->arr);
	}
	return (1);
}

int	ft_clean_struct(t_data *data, int flag)
{
	free(data->map[0]);
	while (data->i != -1)
	{
		free(data->map[data->i]);
		data->i--;
	}
	free(data->map);
	data->map = NULL;
	ft_clean_char_arr(data);
	if (flag == 1)
		ft_putstr_fd("During the creation of structures, \"malloc\" \
		did not allocate memory\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Incorrect height in the map\n", 2);	
	else if (flag == 3)
		ft_putstr_fd("Wrong color on the map\n", 2);
	return (1);
}
