/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:28:51 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/22 19:05:32 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# define ZOOM 10 //del
# include <stdio.h> //printf
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_elem
{
	int	height;
	int	color;
}	t_elem;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}	t_mlx;

typedef struct s_pix
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_pix;

typedef struct s_drawLine
{
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_x3;
	int	sign_y;
	int	sign_y3;
	int	error;
	int	error2;
}	t_drawLine;

typedef struct s_data
{
	char	**arr;
	int		width;
	int		height;
	char	**conv;
	int		i;
	int		st;
	t_elem	**map;
	t_mlx	tmp;
	t_pix	img;
}	t_data;

int			ft_check_extensions(char *str);
int			ft_counting_spaces(char *str);
int			ft_chek_on_size(t_data *data);
int			ft_chek_str(t_data *data);
long long	ft_check_on_hex(char *str);

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
void		ft_django_unchained(char **arr);

int			ft_htoi_fdf(char *s);
void		ft_hex_to_dec(char *str, int *dec);
void		ft_part_hex_to_dec(int *dec, int j, char c);
int			ft_degree(int i);

int			ft_draw(t_data *data, char *name);
void		ft_size_step(t_data *data);
void		my_mlx_pixel_put(t_pix *img, int x, int y, t_data *data);

void		ft_draw_x(t_data *data);
void		ft_draw_y(t_data *data);
void		ft_drawLine(int x1, int y1, int x2, int y2, t_data *data);

#endif