#include "test.h"

void	print_test(char *s)
{
	char **str;

	str = ft_split(s, ' ');
	if (!ft_strncmp(str[0], "R\0", 1))
		printf("Resolution: %s x %s\n", str[1], str[2]);
	else if (!ft_strncmp(str[0], "NO\0", 2))
		printf("North texture: %s\n", str[1]);
	else if (!ft_strncmp(str[0], "SO\0", 2))
		printf("South texture: %s\n", str[1]);
	else if (!ft_strncmp(str[0], "WE\0", 2))
		printf("West texture: %s\n", str[1]);
	else if (!ft_strncmp(str[0], "EA\0", 2))
		printf("East texture: %s\n", str[1]);
	else if (!ft_strncmp(str[0], "S\0", 2))
		printf("Sprite texture: %s\n", str[1]);
	else if (!ft_strncmp(str[0], "F\0", 1))
		printf("Floor colors: %s\n", str[1]);
	else if (!ft_strncmp(str[0], "C\0", 1))
		printf("Ceilling colors: %s\n", str[1]);
}

int		get_nb_of_lines(char *file)
{
	int		fd;
	int		out;
	int		nb_of_lines;
	char	*s;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FALSE);
	out = 1;
	nb_of_lines = 0;
	while (out > 0)
	{
		out = get_next_line(fd, &s);
		if (s[0])
		{
			if (nb_of_lines < 8)
				print_test(s);
			nb_of_lines++;
		}
	}
	return (nb_of_lines);
}

int		read_map_file(int size, char *file)
{
	int		fd;
	int		out;
	int		nb_of_lines;
	char	*s;
	char	**str;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FALSE);
	str = malloc((size - 8 + 1) * sizeof(char *));
	out = 1;
	nb_of_lines = 0;
	while (out > 0)
	{
		out = get_next_line(fd, &s);
		if (s[0])
		{
			if (nb_of_lines >= 8)
				str[nb_of_lines - 8] = ft_strdup(s);
			nb_of_lines++;
		}
	}
	str[nb_of_lines - 8] = NULL;
	printf("TESTANDO ...\n");
	while (*str)
		printf("%s\n", *str++);
	return (TRUE);
}

int main (int argc, char **argv)
{
	int	i;
	char *file = ft_strjoin("./maps/\0", argv[1]);

	i = get_nb_of_lines(file);
	printf("%d\n", i);
	i = read_map_file(i - 8, file);
	printf("%d\n", i);
}
