/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:58:28 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/22 14:11:48 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_checker(char *s)
{
	int i;
	int n;
	int line_len;

	n = 1;
	i = 0;
	line_len = 0;
	while (i < 4)
	{
		while (*s != '\n' && *s != '\0')
		{
			if ((*s == '.' || *s == '#') && line_len < 4)
			{
				s++;
				line_len++;
			}
			else
				return (0);
		}
		if (line_len == 4)
		{
			line_len = 0;
			s++;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int		main()
{
	printf("%d\n", size_checker("....\n..##\n..##\n...."));
	return (0);
}