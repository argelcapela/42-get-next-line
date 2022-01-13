/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:58:24 by acapela-          #+#    #+#             */
/*   Updated: 2022/01/13 04:08:58 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #Include Guard technic to prevent double definition
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE__BONUS_H
# include <fcntl.h> // FILE, 'O_RDONLY', open
# include <malloc.h> // malloc, free
# include <unistd.h> // read

// Function Protoctypes of file get_next_line_utils.c
char	*ft_strrchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Function Protoctypes of file get_next_line.c
char	*get_next_line(int fd);
int		index_last_bn(char *str);

#endif
