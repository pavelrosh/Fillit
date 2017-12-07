/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:15:09 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/04 17:15:11 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "f.h"

void		ft_fillit(t_position *coord, char **map, int map_size)
{
	printf("%s\n", "fillit");
	if (ft_small_push_check(coord, map) == 1)
	{
//		printf("%s\n","0");
		ft_push(coord, map);
		coord = coord->next;
//		printf("%s\n",coord);
	}
	else
	{
		while (coord)
		{
			if (ft_push_check(coord, map, map_size) == 1)
			{
			//	printf("%s\n", "1");
				ft_push(coord, map);
				coord = coord->next;
			}
			else
			{
				if (coord->c == 'A')
				{
					map_size++;
					map = ft_increment_map(map, map_size);
					ft_fillit(coord, map, map_size);
				}
				ft_left_corner(coord);
				coord = coord->prev;
				ft_clear(coord, map);
			}
		}
		//ft_fillit(coord, map, map_size);
	}
	if (coord != NULL)
		ft_fillit(coord, map, map_size);
}

int	main()
{
	int i;
	char **buffer;
	char **map;
	t_position *coord;
	buffer = ft_strsplit(".##.\n..#.\n..#.\n....\n\n....\n####\n....\n....\n\n#...\n###.\n....\n....\n\n....\n##..\n.##.\n....\n", '\n');
//	buffer = ft_strsplit(".##.\n..#.\n..#.\n....\n\n##\n##..\n....\n....\n", '\n');
//	buffer = ft_strsplit("###.\n#...\n....\n....\n\n....\n....\n#...\n###.\n\n....\n.##.\n.##.\n....\n\n...#\n...#\n...#\n...#\n", '\n');
	coord = ft_create_list(buffer, 8);
	map = ft_create_map(3);
	i = 0;
	ft_fillit(coord, map, 3);
	while (i <= 4)
	{
		ft_putendl(map[i]);
		i++;
	}
	return (0);
}