/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:18:49 by pfile             #+#    #+#             */
/*   Updated: 2020/09/13 13:49:00 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(int err)
{
	ft_putstr(strerror(err));
	exit(0);
}

void	error_exit_self(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		error_standart(char *str)
{
	perror(str);
	exit(0);
}
