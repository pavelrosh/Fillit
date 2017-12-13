/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:27:25 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/13 18:28:22 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valid_helper(t_position *tetr)
{
	ft_to_left_wall(tetr);
	ft_y_increment(tetr);
}

void	ft_oshibka(char *buf)
{
	if (ft_validation(buf) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
}
