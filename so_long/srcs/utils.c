#include "../includes/so_long.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2, t_vars *v)
{
	size_t	i;

	i = 0;
	if (!s1)
		map_error(v, 8);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}
