#include "printf.h"

void print_c(t_pt *pt, char val)
{
	int i;

	i = -1;
	if (pt->minus == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		ft_putchar(val);
	}
	else
	{
		ft_putchar(val);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}
	g_bt += pt->b_len + pt->v_len;


}

void print_s(t_pt *pt, char *val)
{
	int i;

	i = -1;
	if (pt->minus == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		int k;
		k = -1;
		while (++k < pt->v_len)
			ft_putchar(val[k]);
	}
	else
	{
		int k;
		k = -1;
		while (++k < pt->v_len)
			ft_putchar(val[k]);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}
	g_bt += pt->b_len + pt->v_len;
}

void print_d(t_pt *pt, int val)
{
	int i;
	int k;

	printf("pt->v_len %d\n", pt->v_len);
	printf("pt->z_len %d\n", pt->z_len);
	printf("pt->b_len %d\n", pt->b_len);
	i = -1;
	k = -1;
	if (pt->minus % 10 == 0)
	{
		while (++i < pt->b_len)
			ft_putchar(' ');
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr(val);
	}
	else
	{
		if (pt->minus / 10 == 1)
			ft_putchar('-');
		while (++k < pt->z_len)
			ft_putchar('0');
		ft_putnbr(val);
		while (++i < pt->b_len)
			ft_putchar(' ');
	}

	g_bt += pt->b_len + pt->z_len + pt->v_len + pt->minus / 10;
}
