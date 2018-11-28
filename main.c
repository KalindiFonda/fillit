

#include <stdio.h>
#include "fillit.h"

int print_error()
{
	ft_putendl_fd("Error", 2);
	return (-1);
}

int move_topleft(int ***tet_coord)
{
	int		min_x;
	int		min_y;
	int		c;

	min_x = 3;
	min_y = 3;
	c = 0;
	while (c < 4)
	{
		if (min_x > (*tet_coord)[c][0])
			min_x = (*tet_coord)[c][0];
		if (min_y > (*tet_coord)[c][1])
			min_y = (*tet_coord)[c][1];
		c++;
	}
	c = 0;
	while (c < 4)
	{
		(*tet_coord)[c][0] = (*tet_coord)[c][0] - min_x;
		(*tet_coord)[c][1] = (*tet_coord)[c][1] - min_y;
		c++;
	}
	return (1);
}



int make_tetramino(char *s, int tet_num, char tet_coord[26][5][2])
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
	printf("%d\n", tet_coord[tet_num][4][0]);

	return 1;

}

int check_make_tetramino(char *s, int tet_num, char tet_coord[26][5][2])
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
			if (s[i + 5] == '#' && ((i + 5) < 20)) 			//if ((s[i + 1] == '#' && (i + 1) < 20) || (s[i + 5] == '#' && (i + 5) < 20))
				c++;
			h++;
		}
		i++;
	}
	if (c >= 3 && h == 4)
		return (make_tetramino(s, tet_num, tet_coord));
	return(print_error());
}

int input_valid(char *s, char tet_coord[26][5][2])
{
	int		i;
	int		tet_num;

	i = 0;
	tet_num = 0;
	while (s[i] != '\0')
	{
		if ((i + 1) % 5 == 0 && s[i] != '\n')
			return (print_error());
		else if ((i + 1) % 5 != 0 && s[i] != '.' && s[i] != '#')
			return (print_error());
		i++;
		if (i == 19)
		{
			if (s[i] != '\n' || (check_make_tetramino(s, tet_num++, tet_coord) == -1))
				return (print_error());
			i = 0;
			s = s + 20;
			if (s[i] != '\0')
				s++;
		}
	}
	if (s[i] == '\0' && i != 0)
		return (print_error());
	return (1);
}

char	*read_str(char *av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*read_s;
	char	*temp;

	if(!(read_s = ft_strnew(1)))
		return (NULL);
	if (((fd = open(av, O_RDWR)) == -1))
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		temp = read_s;
		if (ret == -1 || !(read_s = ft_strjoin(temp, buf)))
			return (NULL);
		free(temp);
	}
	if (close(fd) == -1)
		return (NULL);
	return (read_s);
}

int main(int ac, char **av)
{
	char	**map;
	char	*read_s;
	char	tetri[26][5][2];
	int		info[3]; //current, max, size TODO

	if (ac == 2)
	{
		if (!(read_s = read_str(av[1])))
		{
			ft_putstr("read_s Error\n");
			return (-1);
		}
		if (input_valid(read_s, tetri) == -1)
		{
			ft_putstr("valid map Error\n");
			return (-1);
		}
			info[0] = 0;
			info[1] = 2;
			info[2] = ft_getminmapsize(info[1]);
			map = ft_setmap(info[2]);
			ft_mapinitalise(map, info[2]);
			map = ft_solver(map, tetri, info);
			ft_printmap(map);
	}
	else
	{
		ft_putstr_fd("usage: fillit filename\n", 2);
		exit(1);
	}
}
