#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*new_array(size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		del(void **ptr);
int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
