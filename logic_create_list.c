// int		ft_test(char **buffer)
// {
// //	char	map[12][12];
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;

// 	ft_create_list(buffer);
// 	while (coord);
// 	{
// 		ft_left_corner(coord);
// 		if (ft_move(coord)) //двигает вправо(потом вниз и снова вправо) до тех пор 
// 		{//пока не стала или не вышли за размер мапы (если фигура вылезла за пол,то инкременти м 
// 			coord = coord->next;
// 		}
// 		else
// 		{
// 			coord = coord->prev;
// 		}
// 	}
// 	ft_push_in_map(tmp, size_of_maps); 
// }
#include <stdlib.h>
#include <stdio.h>

typedef struct			s_position 
{
	//int					xy[4][2];
	int					**xy;
	struct s_position	*next;
	struct s_position	*prev;
}						t_position;

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
			while (j++ < 3)
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

t_position		*ft_create_list(char **buf, int lines_numb)
{
	int i;
	int j;
	t_position *head;
	t_position *elem;

	i = 0;
	j = 0;
	printf("0");
	if ((elem = malloc(sizeof(t_position))) != NULL)
	{
		printf("1");
		if ((head = malloc(sizeof(t_position))) != NULL)
		{
			printf("2");
			head->xy = ft_parse(buf, 0, 0, 0); //?
			head->prev = NULL;
			if (lines_numb > 4)
			{
				head->next = elem;
				elem->prev = head;
				while (buf[i - 1][j])
				{
					elem->xy = ft_parse(buf, i + 4, 0, 0);
					elem->next = malloc(sizeof(t_position));
					elem->next->prev = elem;
					elem = elem->next;
					i += 4;
				}
				elem = NULL;
			}
			else
				head->next = NULL;
		}
	}
	else
	{
		printf("NULL");
		return (NULL);
	}
	return (head);
}


int	main()
{
	t_position *head;
	char **pos;
//	int i;

	pos[0] = "....";
	pos[1] = ".##.";
	pos[2] = "..##";
	pos[3] = "....";
	// while (read...)
	// {
	// 	ft_left_corn(tetr, pos);
	// }
	// 	i = 0;
	// 	while (i < 4)
	// 	{
	// 		printf("i = %d\tj = %d\n", tetr.x[i], tetr.y[i]);
	// 		i++;
	// 	}
	printf("%s\n", "before call");
	head = ft_create_list(pos, 4);
//	printf("%d\n" ,head->xy[0][0]);
	return (0);
}























