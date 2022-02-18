/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:28:51 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/18 19:34:38 by lcorinna         ###   ########.fr       */
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
	int	xyj;
}	t_elem;

typedef struct s_data
{
	char	**arr;
	int		width;
	int		height;
	char	**conv;
	int		i;
	t_elem	**map;
}	t_data;

int			ft_check_extensions(char *str);
int			ft_counting_spaces(char *str);
int			ft_chek_on_size(t_data *data);
int			ft_chek_str(t_data *data);

int			ft_return_int_with_error(int flag);
char		*ft_return_null(char *str, char *buf, int flag);
int			ft_return_close_with_error(int flag, int fd);
int			ft_clean_char_arr(t_data *data);
int			ft_clean_struct(t_data *data, int flag);

int			ft_read_fdf(char *file, t_data *data);
char		*ft_gfl_fdf(char *buf, int fd);
char		*ft_strjoin_fdf(char *s1, char *s2);

int			ft_creating_structures(t_data *data);
long long	ft_number(char *done);
int			ft_atoi_fdf(char *s);
int			ft_validation(t_data *data);
void		ft_django_unchained(t_data *data);

int			ft_htoi_fdf(char *s);

#endif