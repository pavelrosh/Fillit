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
	int i;
//	printf("%s\n", "fillit");
	if (ft_small_push_check(coord, map) == 1)
	{
//		printf("%s\n","0");
		ft_push(coord, map);
		coord = coord->next;
		// i = 0;
		// while (i < 4)
		// {
		// 	ft_putendl(map[i]);
		// 	i++;
		// }
		// printf("\n");
	}
	else
	{
		while (coord)
		{
			if (ft_push_check(coord, map, map_size) == 1)
			{
				ft_push(coord, map);
				coord = coord->next;
				// i = 0;
				// while (i <= 5)
				// {
				// 	ft_putendl(map[i]);
				// 	i++;
				// }
				// printf("\n");
			}
			else
			{
				if (coord->c == 'A')
				{
					map_size++;
					map = ft_increment_map(map, map_size);
					ft_left_corner(coord);
					ft_fillit(coord, map, map_size);
				}
				ft_left_corner(coord);
				coord = coord->prev;
				ft_clear(coord, map);
			}
		}
	}
	if (coord != NULL)
		ft_fillit(coord, map, map_size);
	else
		exit (0);
}

int	main(int argc, char **argv)
{
	int i;
	int  fd;
	int  bytes;
	char **buffer;
	char *buf;
	char **map;
	int map_size;
	t_position *coord;
//	buffer = ft_strsplit(".##.\n..#.\n..#.\n....\n\n....\n####\n....\n....\n\n#...\n###.\n....\n....\n\n....\n##..\n.##.\n....\n", '\n');
//	buffer = ft_strsplit(".##.\n..#.\n..#.\n....\n\n##\n##..\n....\n....\n", '\n');
//	buffer = ft_strsplit("###.\n#...\n....\n....\n\n....\n....\n#...\n###.\n\n....\n.##.\n.##.\n....\n\n...#\n...#\n...#\n...#\n", '\n');
//	buffer = ft_strsplit("...#\n...#\n...#\n...#\n\n....\n....\n....\n####\n\n.###\n...#\n....\n....\n\n....\n..##\n.##.\n....\n", '\n');
	fd = open(argv[1], O_RDONLY);
	buf = (char*)malloc(300 + 1);
	bytes = read(fd, buf, 300 + 1);
	buf[bytes] = '\0';
	buffer = ft_strsplit(buf, '\n');

	coord = ft_create_list(buffer, 8);
	map_size = 4;
	map = ft_create_map(map_size);
	//i = 0;
	ft_fillit(coord, map, map_size);
	return (0);
}














