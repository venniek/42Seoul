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

void print_d(t_pt *pt, long long val)
{
	int i;
	int k;

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

void print_u(t_pt *pt, unsigned int val)
{
	int i;
	int k;
//	printf("pt->v_len %d\n", pt->v_len);
//	printf("pt->z_len %d\n", pt->z_len);
//	printf("pt->b_len %d\n", pt->b_len);
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

void print_per(t_pt *pt, char val)
{
	int i;


	
	i = -1;
	if (pt->z_len > 0)
	{
		while(++i < pt->z_len)
			ft_putchar('0');
		ft_putchar(val);
	}
	else
	{
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
	}
	g_bt += pt->z_len + pt->b_len + 1;
}
