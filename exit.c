/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:49:10 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/14 19:34:54 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_return_with_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("Check the number of arguments\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Invalid file extension\n", 2);
	return (0);
}
