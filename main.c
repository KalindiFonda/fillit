


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

int tetramino_coord(char *s, int tet_num, int ***tet_coord)
{
	int		c;
	int		i;

	c = 0;
	i = 0;
	*tet_coord = (int **)malloc(sizeof(int *) * 4);
	while (s[i])
	{
		if (s[i] != '.')
		{
			(*tet_coord)[c] = (int *)malloc(sizeof(int) * 2);
			(*tet_coord)[c][0] = i % 4;
			(*tet_coord)[c][1] = i / 4;
			c++;
		}
		i++;
	}
	return(1);
}


int tetramino_valid(char *s)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '.')
		{
			if (ft_isalpha(s[i + 1]) && ((i + 1) < 16))
				c++;
			if (ft_isalpha(s[i + 4]) && ((i + 4) < 16))
				c++;
		}
		if (c >= 3)
			return (1);
		i++;
	}
	return(print_error());
}

int get_tetraminos(char *s, char ***tetraminos)
{
	int		tet_num;
	int		i;

	*tetraminos = (char **)malloc(sizeof(char *) * (MAX_TETRAMINOS + 1));// protec
	tet_num = 0;
	while (*s)
	{
		i = 0;
		(*tetraminos)[tet_num] = (char *)malloc(sizeof(char *) * 17); // protec
		while (i < 16)
		{
			if (*s == '#')
				(*tetraminos)[tet_num][i++] = tet_num + 65;
			else if (*s == '.')
				(*tetraminos)[tet_num][i++] = '.';
			s++;
		}
		if (!(tetramino_valid((*tetraminos)[tet_num])))
			return (print_error());
		while (*s == '\n')
			s++;
		tet_num++;
	}
	return (tet_num);
}

int input_valid(char *s)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (*s != '\0')
	{
		if ((i + 1) % 5 == 0 && *s != '\n')
			return (print_error());
		else if ((i + 1) % 5 != 0)
		{
			if (*s != '.' && *s != '#')
				return (print_error());
			if (*s == '#')
				c++;
		}
		i++;
		s++;
		if (i == 19)
		{
			if (*s != '\n' || c != 4)
				return (print_error());
			i = 0;
			c = 0;
			s++;
			if (*s != '\0')
				s++;
		}
	}
	if (*s == '\0' && i != 0)
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

	char	*read_s;
	char	**tetraminos;
	int		**tet_coord;

	if (ac == 2)
	{
		if (!(read_s = read_str(av[1])))
		{
			ft_putstr("read_s Error\n");
			return (-1);
		}
		if (input_valid(read_s) == -1)
		{
			ft_putstr("valid map Error\n");
			return (-1);
		}
		if (get_tetraminos(read_s, &tetraminos) == -1)
		{
			ft_putstr("get_tetraminos Error\n");
			return (-1);
		}
		if (tetramino_coord(read_s, &tet_coord) == -1)
		{
			ft_putstr("tetraminos_coord Error\n");
			return (-1);
		}




	}
	else
	{
		ft_putstr_fd("usage: fillit filename\n", 2);
		exit(1);
	}
}
