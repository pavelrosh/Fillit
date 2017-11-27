/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 09:19:43 by dsheptun          #+#    #+#             */
/*   Updated: 2017/11/24 09:19:45 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_H
# define F_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 546

char			**ft_napoln_tabl(int size);
void			ft_putchar(int c);
void			ft_putstr(char *src);
char			*ft_reader(int argc, char **argv);
int				ft_sqrt(int nb);
char			**new_square(int size);

#endif