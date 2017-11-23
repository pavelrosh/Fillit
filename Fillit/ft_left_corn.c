/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_corn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:15:00 by dsheptun          #+#    #+#             */
/*   Updated: 2017/11/23 09:15:02 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef struct	s_position
// {
// 	int	x[4];
// 	int	y[4];
// }				t_position;

#include "fct.h"

t_position	*ft_left_corn(t_position *tetr, int nb_tetr)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (k < nb_tetr)
	{
		tetr[k].x[i] = tetr[k].x[i] - tetr[k].x[0];
		tetr[k].y[i] = tetr[k].y[i] - tetr[k].y[0];
		i++;
		if (i > 3)
		{
			tetr[k].x[0] = 0;
			tetr[k].y[0] = 0;
			i = 1;
			k++;
		}
	}
	return (tetr);
}
