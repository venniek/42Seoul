/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:34:29 by naykim            #+#    #+#             */
/*   Updated: 2021/02/13 02:34:50 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line) {
    static char *save = "\0";
    char buf[BUFF_SIZE];
    int size;
    int index;

    if (fd < 0 || line == 0 || BUFF_SIZE <= 0)
        return (-1);
    size = read(fd, buf, BUFF_SIZE);
    buf[size] = '\0';
    printf("%s\n", buf);
    save = ft_strjoin(save, buf);
    printf("%s", save);
    *line = save;
    return (0);
}
