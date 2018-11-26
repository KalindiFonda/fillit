


#include "fillit.h"

int print_error()
{
	ft_putendl_fd("Error", 2);
	return (-1);
}


int get_tetraminos(char *s, char ***tetraminos)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (*s != '\0')
	{
		ft_putnbr(i);
		if ((i + 1) % 5 == 0)
		{
			ft_putstr("4\n");
			if (*s != '\n')
				return (print_error());
		}
		else
		{
			ft_putstr("5\n");
			ft_putchar(*s);
			if (*s != '.' && *s != '#')
				return (print_error());
			if (*s == '#')
				c++;
		}
		i++;
		s++;
		if (i == 19)
		{

			ft_putstr("1\n");
			if (*s != '\n' || c != 4)
			{
				ft_putstr("1\n");
				ft_putnbr(c);
				return (print_error());
			}
			i = 0;
			c = 0;
			ft_putstr("2\n");
			// create tetramino
			if (!tetraminos)
				ft_putstr("\n");

			ft_putstr("ok\n");
			ft_putstr("3\n");
			ft_putchar(*s);
			if (*s != '\0')
				s++;
			if (*s != '\0')
				s++;
			ft_putchar(*s);
		}
	}
	if (*s == '\0' && i != 0)
		return (print_error());
	ft_putstr("finito\n");
	return (1);
}

char	*read_str(char *av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*read_s;

	read_s = "";
	if (((fd = open(av, O_RDWR)) == -1))
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		read_s = ft_strjoin(read_s, buf);
		// temp = *read_s;
		// if (ret == -1 || !(*read_s = ft_strjoin(temp, buf)))
		// {
		// 	ft_putendl(buf);
		// 	ft_putstr("0\n");
		// 	ft_putendl(*read_s);
		// 	ft_putstr("1\n");
		// 	ft_putnbr(ret);
		// 	return (-1);
		// }
		// ft_putstr("here1\n");
		// free(temp);

	}
	if (close(fd) == -1)
		return (NULL);
	return (read_s);

}

int main(int ac, char **av)
{

	char	*read_s;
	char	**tetraminos;

	read_s = NULL;

	if (ac == 2)
	{
		if (!(read_s = read_str(av[1])))
		{
			ft_putstr("read_s Error\n");
			return (-1);
		}
		if (get_tetraminos(read_s, &tetraminos) == -1)
		{
			ft_putstr("get_tetraminos Error\n");
			return (-1);
		}
	}
	else
	{
		ft_putstr_fd("usage: fillit filename\n", 2);
		exit(1);
	}
}
