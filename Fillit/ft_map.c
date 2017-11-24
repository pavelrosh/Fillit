/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:23:31 by dsheptun          #+#    #+#             */
/*   Updated: 2017/11/24 16:56:32 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"
// #include "stdlib.h"
// #include "stdio.h"

char	**get_in_map(char *array, int count, int i, int j)
{
	char	**map;

	if (!(matrix = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	map[count] = NULL;
	while (i < count)
	{
		if (!(map[i++] = (char*)malloc(sizeof(char) * 16 + 1)))
			return (NULL);
		map[i - 1][16] = '\0';
	}
	count = 0;
	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] != '\n')
			map[j][count++] = array[i];
		if (((i + 1) % 21) == 0)
		{
			count = 0;
			j++;
		}
		i++;
	}
	return (map);
}

char	**fix_tetris(char **square, char *str, int i, int j)
{
	int		k;
	int		dots;

	dots = how_many_dots(str);
	k = dots - 1;
	while (str[++k])
	{
		if (str[k] != '.')
			square[j + (k / 4) - (dots / 4)][i + (k % 4) - (dots % 4)] = str[k];
	}
	return (square);
}

char	**get_out(char **square, char *str, int i, int j)
{
	char	chr;

	chr = str[how_many_dots(str)];
	while (square[j])
	{
		while (square[j][i])
		{
			if (square[j][i] == chr)
				square[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	return (square);
}

int		how_many_dots(char *str)
{
	int i;

	i = 0;
	while (str[i] == '.')
		i++;
	return (i);
}
char	**new_square(int size)

{
	char	**square;
	int		i;
	int		j;

	i = 0;
	if (!(square = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	square[size] = NULL;
	while (i < size)
	{
		if (!(square[i] = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		square[i][size] = '\0';
		i++;
	}
	i = 0;
	while (square[i])
	{
		j = 0;
		while (j < size)
			square[i][j++] = '.';
		i++;
	}
	return (square);
}


// int	main()
// {
// 	printf("%s\n",*ft_napoln_tabl(20));
// 	return (0);
// }
