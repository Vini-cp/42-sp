#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		get_end_line (char *s);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
