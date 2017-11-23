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
#include <stdio.h>

int		newline_check(char *s)
{
	int count;
	int i;

	count = 1;
	i = 0;

	while (count >= 1)
	{
		if ((s[i] != '.' || s[i] != '#') && s[i + 4] != '\n')
			return (0);
		if (count == 4)
		{
			if (s[i + 5] == '\n' && (s[i + 6] == '.' || s[i + 6] == '#'))
				return (1);
			else if (s[i + 5] == '\0')
				return (1);
			else
				return (0);
		}
		count++;
		i += 5;
	}
	return (1);
}

int		tetr_check(char **str, int j, int i)
{
	int conn;

	conn = 0;
	if (str[j][i + 1] == '#')
		conn++;
	if (str[j][i - 1] == '#')
		conn++;
	if (str[j][i + 5] == '#')
		conn++;
	if (str[j][i - 5] == '#')
		conn++;
return (conn);
}

int		find_sharp(char *buf)
{
	char **str;
	int s;
	int l;
	int conn;

	s = 0;
	l = 0;
	conn = 0;
	if ((str = ft_strsplit(buf, '\n')) != NULL)
	{
		while (l < 4)
		{
			while (s < 4)
			{
				if (str[l][s] != '#')
					s++;
				else
					conn += tetr_check(str, l, s);
			}
			s = 0;
			l++;
		}
		if (conn == 6 || conn == 8)
			return (1);
	}
	return (0);
}

int		main()
{
	printf("result: %d\n", find_sharp("####\n....\n....\n....\n"));
	return (0);
}


























