/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:37:13 by naykim            #+#    #+#             */
/*   Updated: 2021/06/29 14:37:14 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				ft_newline(const char *save)
{
	int			i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				update_save(char **save, int index, char **line)
{
	char		*tmp;
	int			len;

	if (index == 0)
		*line = ft_strdup("");
	else
		*line = ft_substr(*save, 0, index);
	len = ft_strlen(*save) - index - 1;
	if (len <= 0)
	{
		free(*save);
		*save = 0;
		return (1);
	}
	tmp = ft_substr(*save, index + 1, len);
	free(*save);
	*save = tmp;
	return (1);
}

int				read_done(char **line, char **save, int size)
{
	int			index;

	if (size < 0)
	{
		free(*save);
		*save = 0;
		return (-1);
	}
	if ((index = ft_newline(*save)) >= 0)
		return (update_save(save, index, line));
	if (*save)
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = 0;
		return (0);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			index;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!save)
		save = ft_strdup("");
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		save = ft_strjoin(&save, buf);
		if ((index = ft_newline(save)) >= 0)
			return (update_save(&save, index, line));
	}
	return (read_done(line, &save, size));
}
