#include "../includes/so_long.h"

int main(int ac, char *av[])
{
	t_vars v;

	default_map(&v);
	if (ac < 2)
	{
		ft_putstr_fd("no maps\n", 2);
		ft_putstr_fd("Error\n", 2);
		ft_exit(&v, 1);
	}
	ft_memset(&v, 0, sizeof(t_vars));
	make_map(av, &v);
	check_map_error(&v);
	make_all(&v);
	map_repeat(&v);
	mlx_hook(v.win, 2, 1L<<0, ft_keypress, &v);
	mlx_hook(v.win, 17, 0, ft_click, &v);
	mlx_loop(v.mlx);
	
	return 0;
}

char *print_integer(t_vars *v)  //move to bonus
{
	char *move;
	int mcopy;
	int len;

	len = 0;
	mcopy = v->move;
	while (mcopy > 0)
	{
		len++;
		mcopy /= 10;
	}
	mcopy = v->move;
	move = (char *)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
	{
		move[i] = mcopy % 10 + '0';
		mcopy /= 10;
	}
	move[len] = '\0';
	for (int i = 0; i < len / 2; i++)
	{
		char tmp;
		tmp = move[i];
		move[i] = move[len - i - 1];
		move[len - i - 1] = tmp;
	}
	return (move);
}