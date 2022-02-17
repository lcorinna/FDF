/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:28:51 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/17 19:07:35 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# include <stdio.h> //printf
# include <fcntl.h>

typedef struct s_elem
{
	int	height;
	int	color;
}	t_elem;

typedef struct s_data
{
	int		width;
	int		height;
	t_elem	**map;
}	t_data;

int			ft_check_extensions(char *str);
int			ft_counting_spaces(char *str);
int			ft_chek_on_size(char **arr, t_data *data);
int			ft_chek_str(char **arr, t_data *data);

int			ft_return_int_with_error(int flag);
char		*ft_return_null(char *str, char *buf, int flag);
char		**ft_return_char_with_error(int flag, int fd);
int			ft_clean_char_arr(char **conv, char **arr);

char		**ft_read_fdf(char *file, char **arr, int fd, t_data *data);
char		*ft_gfl_fdf(char *buf, int fd);
char		*ft_strjoin_fdf(char *s1, char *s2);

int			ft_creating_structures(char **arr, t_data *data, int i);
long long	ft_number(char *done);
int			ft_atoi_fdf(char *s);

#endif