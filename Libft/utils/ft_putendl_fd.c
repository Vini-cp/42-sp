#include <unistd.h>

static	void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
    ft_putchar_fd('\n', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
