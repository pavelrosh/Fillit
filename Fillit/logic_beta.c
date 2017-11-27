int		ft_test(t_list **coord)
{
	int i;
	int j;

	i = 0;
	j = 0;
	t_list **tmp;
	while (coord[i] != NULL);
	{
		coord[i] = ft_left_corner(&coord[i]);
		if (ft_compare(coord[i],i, size_of_map) == 1)//сравнить координаты текущей фигуры с размерами мапы и с предыдущей фигурой
		{ 
			i++;
		}
		else
		{
			tmp->next = coord->next;
			if ((tmp = ft_move(coord[i]) != NULL)) //двигает вправо(потом вниз и снова вправо) до тех пор 
			{//пока не стала или не вышли за размер мапы (если фигура вылезла за пол,то инкременти м 
				coord = tmp; //мапу + возвращаем текущие координаты) или возвращаем налл
				coord = coord->next;
				i++;
			}
			else
			{
				coord = coord->prev;
				i--;
			}
		}
	}
	ft_push_in_map(tmp, size_of_maps); 
}

struct t_list 
{
	int x[4];
	int y[4];
	coord *next;
	coord *prev;
}coord;

t_position *ft_left_corn(t_position *tetr, int nb_tetr)
{
 int i;
 int k;

 i = 1;
 k = 0;
 while (k < nb_tetr)
 {
  tetr[k].x[i] = tetr[k].x[i] - tetr[k].x[0];
  tetr[k].y[i] = tetr[k].y[i] - tetr[k].y[0];
  i++;
  if (i > 3)
  {
   tetr[k].x[0] = 0;
   tetr[k].y[0] = 0;
   i = 1;
   k++;
  }
 }
 return (tetr);
}


void	ft_left_corn(t_position tetr)
{
	int min_x;
	int min_y;

	min_x = tetr.x[0];
	min_y = tetr.y[0];
	i = 1;
	k = 0;
	while (i < 4)
	{
		if (tetr[k].x[i] < tetr[k].x[i + 1])
			res_i_x = i;
		i++;
		if (i > 3)
		{
			i = 0;
			while (i < 4)
			{
				if (tetr[k].y[i] < tetr[k].y[i + 1])
					min_y = i;
				i++;
			}
		}
	}
	ft_move_to_corner(&tetr, min_x, min_y);
}

t_position  	*ft_move_to_corner(t_position tetr, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetr.x[i] = tetr.x[i] - min_x;
		tetr.y[i] = tetr.y[i] - min_y;
		i++;
	}
	return (tetr);
}




















