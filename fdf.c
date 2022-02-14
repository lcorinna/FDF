/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:27:43 by lcorinna          #+#    #+#             */
/*   Updated: 2022/02/14 19:41:42 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc > 2 || argc < 2)
		return (ft_return_with_error(1));
	if (ft_check_extensions(argv[1]) == 1)
		return (ft_return_with_error(2));
	return (0);
}
