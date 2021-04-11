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

