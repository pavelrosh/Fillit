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
//		if (ft_move(coord)) //двигает вправо(потом вниз и снова вправо) до тех пор 
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
#include "libft.h"

typedef struct			s_position 
{
	//int					xy[4][2];
	int					**xy;
	struct s_position	*next;
	struct s_position	*prev;
}						t_position;

t_position		*ft_left_corner(t_position *tetr)
{
	int min_x;
	int min_y;
	int x;
	int y;

	x = 1;
	y = 0;
	min_x = tetr->xy[0][0];
	min_y = tetr->xy[0][1];
	while (x < 4)
	{
		if (min_x > tetr->xy[x][0])
			min_x = tetr->xy[x][0];
		if (min_y > tetr->xy[x][1])
			min_y = tetr->xy[x][1];
		x++;
	}
	x = 0;
	while (x < 4)
	{
		tetr->xy[x][0] -= min_x;
		tetr->xy[x][1] -= min_y;
		x++;
	}
	return (tetr);
}

int				**ft_parse(char **buf, int i, int r, int c)
{
	int **row_col;
	int j;
	int counter;

	counter = -1;
	if ((row_col = (int **)malloc((sizeof(int *) * 4))) != NULL)
	{
		while (++counter < 4 && i++ < 104)
		{
//			printf("%d %d\n",counter, i);
			j = -1;
			while (++j < 4)
			{
				if (buf[i][j] == '#')
				{
					if ((row_col[r] = (int *)malloc(sizeof(int) * 2)) != NULL)
					{
						row_col[r][c] = j;
						row_col[r][c + 1] = counter;
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

	i = 4;
	j = 0;
	if ((elem = malloc(sizeof(t_position))) != NULL)
	{
		if ((head = malloc(sizeof(t_position))) != NULL)
		{
			head->xy = ft_parse(buf, -1, 0, 0);
			head->prev = NULL;
			if (lines_numb > 4)
			{
				head->next = elem;
				elem->prev = head;
				while (buf[i] != NULL)
				{
				//	printf("i :%d\n", i);
					elem->xy = ft_parse(buf, (i - 1), 0, 0);
				//	printf("%d%s\n", i,"ft_parse OK");
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
		return (NULL);
	return (head);
}


int	main()
{
	t_position *head;
// 	char *pos[41];
// 	int i;
	int i;

// 	 pos[0] = "...#";
// 	 pos[1] = "...#";
// 	 pos[2] = "...#";
// 	 pos[3] = "...#";

// 	 pos[4] = "....";
// 	 pos[5] = ".##.";
// 	 pos[6] = "..##";
// 	 pos[7] = "....";

// 	 pos[8] = "....";
// 	 pos[9] = ".##.";
// 	pos[10] = "..##";
// 	pos[11] = "....";

// 	pos[12] = "....";
// 	pos[13] = ".##.";
// 	pos[14] = "..##";
// 	pos[15] = "....";

// 	pos[16] = "....";
// 	pos[17] = ".##.";
// 	pos[18] = "..##";
// 	pos[19] = "....";

// 	pos[20] = "####";
// 	pos[21] = "....";
// 	pos[22] = "....";
// 	pos[23] = "....";

// 	pos[24] = "....";
// 	pos[25] = ".##.";
// 	pos[26] = "..##";
// 	pos[27] = "....";

// 	pos[28] = "....";
// 	pos[29] = ".##.";
// 	pos[30] = "..##";
// 	pos[31] = "....";

// 	pos[32] = "....";
// 	pos[33] = ".##.";
// 	pos[34] = "..##";
// 	pos[35] = "....";

// 	pos[36] = "....";
// 	pos[37] = "....";
// 	pos[38] = "..##";
// 	pos[39] = "..##";

//	pos[40] = "\0";
	char **pos;

	pos = ft_strsplit("...#\n...#\n...#\n...#\n\n.##.\n.##.\n....\n....\n\n...#\n...#\n...#\n...#\n\n....\n..##\n..##\n....\n\n", '\n');
	i = 1;
	head = ft_create_list(pos, 10);
//	ft_left_corner(head);
	while (head->next)
	{
		printf("tetrim # :%d", i);
		ft_left_corner(head);
		printf(" %d%d\n" ,head->xy[0][0], head->xy[0][1]);
		printf(" %d%d\n" ,head->xy[1][0], head->xy[1][1]);
		printf(" %d%d\n" ,head->xy[2][0], head->xy[2][1]);
		printf(" %d%d\n" ,head->xy[3][0], head->xy[3][1]);
		head = head->next;
		i++;
	}

	return (0);
}












