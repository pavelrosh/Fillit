/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:56:55 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/02 14:56:58 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_helper(t_position *elem, char **buf, int i)
{
	elem->xy = ft_parse(buf, (i - 1), 0, 0);
	elem->c = ++g_l_list;
	elem->next = malloc(sizeof(t_position));
	elem->next->prev = elem;
}

t_position		*ft_create_list(char **buf, int lines_numb)
{
	t_position	*head;
	t_position	*elem;

	g_i_list = 4;
	g_l_list = 'A';
	elem = malloc(sizeof(t_position));
	head = malloc(sizeof(t_position));
	head->xy = ft_parse(buf, -1, 0, 0);
	head->prev = NULL;
	head->c = g_l_list;
	if (lines_numb > 4)
	{
		head->next = elem;
		elem->prev = head;
		while (buf[g_i_list] != NULL)
		{
			ft_helper(elem, buf, g_i_list);
			elem = elem->next;
			g_i_list += 4;
		}
		elem->prev->next = NULL;
	}
	else
		head->next = NULL;
	return (head);
}
