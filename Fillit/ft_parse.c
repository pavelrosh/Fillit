/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:28:12 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/29 11:28:16 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int				**ft_parse(char **buf, int i, int r, int c)
{
	int **row_col;
	int j;
	int counter;

	counter = 0;
	if ((row_col = (int **)malloc((sizeof(int *) * 4))) != NULL)
	{
		while (counter++ < 4 && i++ < 104)
		{
			j = -1;
			while (j++ < 4)
			{
				if (buf[i][j] == '#')
				{
					if ((row_col[r] = (int *)malloc(sizeof(int) * 2)) != NULL)
					{
						row_col[r][c] = j;
						row_col[r][c + 1] = i;
						r++;
					}
					else
						return (0);
				}
			}
		}
		return (row_col);
	}
	return (0);
}

int		main()
{
	char **buf;
	int **res;
	int i = 0;
	int j = 0;
	buf[0] = "#...";
	buf[1] = "#...";
	buf[2] = ".##.";
	buf[3] = "....";
	res = ft_parse(buf, -1, 0, 0);
	// while (i < 4 && j < 4)
	// {
	// 	printf("%d %d\n", res[i][j], res[i][j + 1]);
	// 	i++;
	// 	j++;
	// }
	printf("%d %d\n", res[0][0], res[0][1]);
	printf("%d %d\n", res[1][0], res[1][1]);
	printf("%d %d\n", res[2][0], res[2][1]);
	printf("%d %d\n", res[3][0], res[3][1]);
	return(0);
}