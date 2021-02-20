/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:34:29 by naykim            #+#    #+#             */
/*   Updated: 2021/02/20 18:18:15 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_newline(const char *save)
{
    int i;

    i = 0;
    while (save[i])
    {
        if (save[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

int update_save(char **save, int index, char **line) {
    char *tmp;
    int len;

    if (index == 0)
        *line = ft_strdup("");
    else
        *line = ft_substr(*save, 0, index);
    len = ft_strlen(*save) - index - 1;
    if (len <= 0)
    {
		*save = 0;
        return (1);
    }
    tmp = ft_substr(*save, index + 1, len);
    free(*save);
    *save = tmp;
    return (1);
}

int get_next_line(int fd, char **line) {
    static char *save;
    char buf[BUFFER_SIZE + 1];
    int size;
    int index;

    if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
        return (-1);
	if (!save)
		save = ft_strdup("");
	//printf("save:\n%s\n", save);
    while ((size = read(fd, buf, BUFFER_SIZE)) > 0) {
        buf[size] = '\0';
	//	printf("buf:\n%s\n", buf);
	//	printf("here?\n");
        save = ft_strjoin(save, buf);
	//	printf("here2?\n");
	//	printf("save with buf:\n%s\n", save);
        if ((index = ft_newline(save)) >= 0)
            return (update_save(&save, index, line));
   }
	if (size < 0)
		return (-1);
	if ((index = ft_newline(save)) >= 0)
		return (update_save(&save, index, line));
	if (save)
	{
		*line = ft_strdup(save);	
		save = 0;
	//	printf("%p\n", save);
		return (0);
	}
    return(0);
}
