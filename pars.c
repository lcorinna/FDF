/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:10:01 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/26 16:58:21 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin_fdf(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	j = 0;
	i = 0;
	join = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i])
			join[j++] = s1[i++];
	}
	i = 0;
	if (s2 != NULL)
	{
		while (s2[i])
			join[j++] = s2[i++];
	}
	join[j] = '\0';
	ft_return_null(s1, s2, 0);
	return (join);
}

char	*ft_gfl_fdf(char *str, int fd)
{
	char	*buf;
	int		rd;

	rd = 1;
	while (rd)
	{
		buf = (char *) malloc(sizeof (char *) * 5000);
		if (buf == NULL)
			return (NULL);
		rd = read(fd, buf, 4999);
		buf[rd] = '\0';
		if (rd == -1)
			ft_return_null(NULL, buf, 0);
		str = ft_strjoin_fdf(str, buf);
		if (str == NULL)
			return (ft_return_null(str, NULL, 1));
	}
	return (str);
}

int	ft_read_fdf(char *file, t_data *data)
{
	char	*one_line;
	int		fd;

	one_line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_return_close_with_error(1, 0));
	one_line = ft_gfl_fdf(one_line, fd);
	if (one_line == NULL)
		return (ft_return_close_with_error(2, fd));
	if (ft_strlen(one_line) == 0)
	{
		free(one_line);
		return (ft_return_close_with_error(4, fd));
	}
	data->arr = ft_split(one_line, '\n');
	free(one_line);
	if (data->arr == NULL)
		return (ft_return_close_with_error(3, fd));
	if (ft_chek_str(data))
		return (ft_return_close_with_error(0, fd));
	close (fd);
	return (0);
}
