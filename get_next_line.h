/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:17:43 by naykim            #+#    #+#             */
/*   Updated: 2021/02/24 15:23:05 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char **s1, char *s2);
unsigned int	ft_strlen(char *s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s);

#endif
