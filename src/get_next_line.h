/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:58:24 by acapela-          #+#    #+#             */
/*   Updated: 2022/01/14 00:33:48 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <malloc.h>
# include <unistd.h>

char	*ft_strrchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		index_first_bn(char *str);
char	*clean_leak(char **ptr);
char	*get_next_line(int fd);
char	*get_line_hold_rest(int fd, char **rest,
			ssize_t result, char *buffer);

#endif
