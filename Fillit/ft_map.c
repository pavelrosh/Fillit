/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:23:31 by dsheptun          #+#    #+#             */
/*   Updated: 2017/11/23 14:23:33 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "stdlib.h"
// #include "stdio.h"

char			**ft_napoln_tabl(int size)
{
	int		i;
	int		j;
	char	**tabl;

	i = 0;
	j = 0;
	tabl = (char **)malloc((size + 1) * sizeof(*tabl));
	while (i != size + 1)
	{
		tabl[i] = (char*)malloc((size + 1) * sizeof(tabl));
		i++;
	}
	i = 0;
	while (i < size)
	{
		tabl[i][j] = '.';
		j++;
		if (j == size)
		{
			tabl[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	return (tabl);
}

// int	main()
// {
// 	printf("%s\n",*ft_napoln_tabl(20));
// 	return (0);
// }
