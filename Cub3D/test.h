#ifndef TEST_H
# define TEST_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 32

typedef	struct		s_map
{
	char			*resolution_width;
	char			*resolution_height;
	char			*north_text;
	char			*south_text;
	char			*west_text;
	char			*east_text;
	char			*sprite_text;
	char			*floor_rgb;
	char			*ceilling_rgb;
	char			**map;
	int				width;
	int				height;
}					t_map;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
int		ft_memdel(void **ptr);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		get_next_line(int fd, char **line);

#endif
