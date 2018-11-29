/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:08:57 by skunz             #+#    #+#             */
/*   Updated: 2018/11/27 16:09:01 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 546
# define MAX_TETRAMINOS 26

/*
**		algo.c
*/
int		ft_inbounds(char tetri[5][2], int size);
int		ft_inboundsy(char tetri[5][2], int size);
int		ft_place(char ***map, char tetri[5][2], char let);
int		ft_solver(char ***map, char tetri[26][5][2], int info[3]);

/*
**		map.c
*/
int		ft_getminmapsize(int tetricount);
char	**ft_setmap(int size);
void	ft_mapinitalise(char **map, int size);
char	**ft_increasemap(char **map, int size);

/*
**		tetri.c
*/
int		move_topleft(char (*tet_coord)[5][2], int size);
void	ft_movetetriright(char (*tetri)[5][2]);
void	ft_movetetridown(char (*tet_coord)[5][2], int size);
void	ft_cleantetri(char ***map, char (*tetri)[5][2]);

/*
**		print.c
*/
void	ft_printmap(char **map, int size);
int		print_error(int i);

#endif
