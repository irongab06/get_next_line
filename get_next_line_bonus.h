#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line_bonus(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *line, const char *buffer);

//--------------------------------------------------------------

size_t	ft_strlen(const char *str);

//--------------------------------------------------------------

void	*ft_calloc(size_t count, size_t size);

//--------------------------------------------------------------

#endif
