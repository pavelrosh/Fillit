int		ft_test(char **buffer)
{
//	char	map[12][12];
	int i;
	int j;

	i = 0;
	j = 0;

	ft_create_list(buffer);
	while (coord);
	{
		ft_left_corner(coord);
		if (ft_move(coord)) //двигает вправо(потом вниз и снова вправо) до тех пор 
		{//пока не стала или не вышли за размер мапы (если фигура вылезла за пол,то инкременти м 
			coord = coord->next;
		}
		else
		{
			coord = coord->prev;
		}
	}
	ft_push_in_map(tmp, size_of_maps); 
}

t_position		**ft_create_list(char **buf)
{
	int i;
	int j;
	t_position *head;
	t_position *elem;

	i = 0;
	j = 0;
	if ((elem = malloc(sizeof(t_position))) != NULL)
	{
		if ((head = malloc(sizeof(t_position))) != NULL)
		{
			head->xy = ft_parse(buf, 0, 0, 0); //?
			head->prev = NULL;
			head->next = elem;
			elem->prev = head;
			while (???)
			{
				elem->xy = ft_parse(buf, i + 4, 0, 0);
				elem->next = malloc(sizeof(t_position));
				elem->next->prev = elem;
				elem = elem->next;
				i += 4;
			}
			elem = NULL;
		}
	}
	return (NULL);
}
#include <stdio.h>

typedef struct			s_position 
{
	//int					xy[4][2];
	int					**xy;
	struct s_position	*next;
	struct s_position	*prev;
}						t_position;

// t_position *ft_left_corn(t_position *tetr, int nb_tetr)
// {
//  int i;
//  int k;

//  i = 1;
//  k = 0;
//  while (k < nb_tetr)
//  {
//   tetr[k].x[i] = tetr[k].x[i] - tetr[k].x[0];
//   tetr[k].y[i] = tetr[k].y[i] - tetr[k].y[0];
//   i++;
//   if (i > 3)
//   {
//    tetr[k].x[0] = 0;
//    tetr[k].y[0] = 0;
//    i = 1;
//    k++;
//   }
//  }
//  return (tetr);
// }

t_position  	ft_move_to_corner(t_position tetr, int min_x, int min_y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		// tetr.x[i] -= min_x;
		// tetr.y[i] -= min_y;
		// i++;
	}
	return (tetr);
}

t_position	ft_left_corn(t_position tetr)
{
	// int min_x;
	// int min_y;

	// min_x = tetr.x[0];
	// min_y = tetr.y[0];
	// i = 1;
	// k = 0;
	// while (i < 4)
	// {
	// 	if (tetr[k].x[i] < tetr[k].x[i + 1])
	// 		res_i_x = i;
	// 	i++;
	// 	if (i > 3)
	// 	{
	// 		i = 0;
	// 		while (i < 4)
	// 		{
	// 			if (tetr[k].y[i] < tetr[k].y[i + 1])
	// 				min_y = i;
	// 			i++;
	// 		}
	// 	}
	// }
 // 	return (ft_move_to_corner(tetr, min_x, min_y));
	int i;
	int j;
	int min_x;
	int min_y;

	min_x = tetr.xy[0][0];
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr.x[i][j] < tetr.x[i][j + 1])
		}
	}
}

int	main()
{
	t_position *tetr;
	char *pos[4];
	int i;

	pos[0] = "....";
	pos[1] = ".##.";
	pos[2] = "..##";
	pos[3] = "....";
	tetr = malloc();
	while (read...)
	{
		ft_left_corn(tetr, pos);
	}
		i = 0;
		while (i < 4)
		{
			printf("i = %d\tj = %d\n", tetr.x[i], tetr.y[i]);
			i++;
		}
	return (0);
}
