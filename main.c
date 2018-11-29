/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 00:44:57 by kfonda            #+#    #+#             */
/*   Updated: 2018/11/28 00:45:02 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		make_tetramino(char *s, int tet_num, char tet_coord[26][5][2])
{
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			tet_coord[tet_num][c][0] = i % 5;
			tet_coord[tet_num][c][1] = i / 5;
			c++;
		}
		i++;
	}
	tet_coord[tet_num][4][0] = tet_num + 65;
	return (move_topleft(&tet_coord[tet_num], 3));
}

int		check_make_tetramino(char *s, int tet_num, char tet_coord[26][5][2])
{
	int		i;
	int		c;
	int		h;

	c = 0;
	i = 0;
	h = 0;
	while (i < 19)
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' && ((i + 1) < 20))
				c++;
			if (s[i + 5] == '#' && ((i + 5) < 20))
				c++;
			h++;
		}
		i++;
	}
	if (c >= 3 && h == 4)
		return (make_tetramino(s, tet_num, tet_coord));
	return (-1);
}

int		input_valid(char *s, char tetri[26][5][2])
{
	int		i;
	int		t_num;

	i = 0;
	t_num = 0;
	while (s[i] != '\0')
	{
		if ((i + 1) % 5 == 0 && s[i] != '\n')
			return (print_error(-1));
		else if ((i + 1) % 5 != 0 && s[i] != '.' && s[i] != '#')
			return (print_error(-1));
		i++;
		if (i == 19)
		{
			if (check_make_tetramino(s, t_num++, tetri) == -1)
				return (print_error(-1));
			if (s[i] != '\n')
				return (print_error(-1));
			if (s[i + 1] == '\0')
				return (t_num);
			i = 0;
			s = s + 21;
		}
	}
	return (print_error(-1));
}

int		read_str_make_tetr(char *av, char tetri[26][5][2])
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (((fd = open(av, O_RDWR)) == -1))
		return (print_error(0));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (ret == -1 || ret < 19 || ret > 545)
			return (print_error(-1));
	}
	if (close(fd) == -1)
		return (-1);
	return (input_valid(buf, tetri));
}

int		main(int ac, char **av)
{
	char	**map;
	char	tetri[26][5][2];
	int		info[3];

	if (ac == 2)
	{
		info[0] = 0;
		if ((info[1] = read_str_make_tetr(av[1], tetri)) == -1)
			return (-1);
		info[2] = ft_getminmapsize(info[1]);
		map = ft_setmap(info[2]);
		ft_mapinitalise(map, info[2]);
		while (ft_solver(&map, tetri, info))
			map = ft_increasemap(map, info[2]++);
		ft_printmap(map, info[2]);
		ft_free2d(map, info[2]);
		return (0);
	}
	else
		print_error(0);
}
