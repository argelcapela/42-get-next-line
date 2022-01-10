// #Include Guard technic to prevent double definition
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h> // FILE, 'O_RDONLY', open
# include <malloc.h> // malloc, free
# include <unistd.h> // read
# include <stdio.h>

// Function Protoctypes of file get_next_line_utils.c
char	*ft_strrchr(const char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Function Protoctypes of file get_next_line.c
char	*get_next_line(int fd);
char	*get_line_hold_rest(int fd, char **rest, ssize_t result, char *buffer);

#endif
