/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:00:47 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/02 13:00:49 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_xv;
int g_yv;

static t_position		*ft_x_increment(t_position *tetr)
{
	int x;

	x = 0;
	while (x < 4)
		tetr->xy[x++][0] += 1;
	return (tetr);
}

t_position				*ft_y_increment(t_position *tetr)
{
	int x;

	x = 0;
	while (x < 4)
		tetr->xy[x++][1] += 1;
	return (tetr);
}

static int				ft_walls_check(t_position *tetr, int map_size, int i)
{
	int x;

	x = 0;
	if (i == 1)
	{
		while (x < 4)
		{
			if (tetr->xy[x++][0] >= map_size)
				return (0);
		}
	}
	x = 0;
	while (x < 4)
		if (tetr->xy[x++][1] >= map_size)
			return (2);
	return (1);
}

t_position				*ft_to_left_wall(t_position *tetr)
{
	int min_x;
	int x;

	x = 0;
	min_x = tetr->xy[0][0];
	while (x < 4)
	{
		if (min_x > tetr->xy[x][0])
			min_x = tetr->xy[x][0];
		x++;
	}
	x = 0;
	while (x < 4)
	{
		tetr->xy[x][0] -= min_x;
		x++;
	}
	return (tetr);
}

int						ft_push_check(t_position *tetr, int map_size)
{
	g_xv = 0;
	g_yv = 0;
	ft_x_increment(tetr);
	while (g_xv < 4)
	{
		if (ft_walls_check(tetr, map_size, 1) == 1)
		{
			if (g_map[tetr->xy[g_xv][g_yv + 1]][tetr->xy[g_xv][g_yv]] != '.')
			{
				ft_x_increment(tetr);
				g_xv = 0;
			}
			else
				g_xv++;
		}
		else
		{
			valid_helper(tetr);
			if (ft_walls_check(tetr, map_size, -1) == 1)
				g_xv = 0;
			else
				return (0);
		}
	}
	return (1);
}
