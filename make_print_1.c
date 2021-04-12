#include "printf.h"

int make_print_c(t_flag *flag, va_list *ap, t_pt *pt)
{
    char val;

    val = va_arg(*ap, int);
    if (flag->zero == 1 || flag->prec != -1)
        return (UNDEFINED);
    if (flag->minus == 1)
        pt->minus = 1;
    if (flag->width != -1)
        pt->b_len = flag->width - 1;
    pt->v_len = 1;
    print_c(pt, val);
    return (0);
}

int make_print_s(t_flag *flag, va_list *ap, t_pt *pt)
{
    char *val;

    val = va_arg(*ap, char *);
    if (val == NULL)
        val = "(null)";
    if (flag->zero == 1)
        return (UNDEFINED);
    if (flag->sign == 1)
        return (INVALID);
    if (flag->minus == 1)
        pt->minus = 1;
    if (flag->sign == 2)
    {
        pt->v_len = ft_strlen(val);
        pt->minus = 0; // wrong. gochigi.
    }
    else if (flag->dot == 1 && flag->prec <= 0)
        pt->v_len = 0;
    else if (flag->dot == 1)
        pt->v_len = ft_min(ft_strlen(val), flag->prec);
    else
        pt->v_len = ft_strlen(val);
    if (pt->v_len < flag->width)
        pt->b_len = flag->width - pt->v_len;
    print_s(pt, val);
    return (0);
}

int make_print_d(t_flag *flag, va_list *ap, t_pt *pt)
{
    int val;

    val = va_arg(*ap, int);
    if (val < 0)
    {
        pt->minus += 10;
        val *= -1;
    }
    pt->v_len = ft_len(val);
    if (flag->minus == 1)
        pt->minus += 1;
    if (flag->dot == 1)
    {
        if (val == 0)
        {
            g_bt += flag->width;
            while (flag->width-- > 0)
                ft_putchar(' ');
            return (0);
        }
        pt->z_len = ft_max(0, flag->prec - pt->v_len);
        pt->b_len = ft_max(0, flag->width - ft_max(flag->prec, pt->v_len) - pt->minus / 10);
    }
    else
    {
        if (flag->zero == 1)
            pt->z_len = ft_max(0, flag->width - pt->v_len);
        else
            pt->b_len = ft_max(0, flag->width - pt->v_len);
    }
    print_d(pt, val);
    return (0);
}
/*
int make_print_p(t_flag *flag, va_list *ap, t_pt *pt)
{

}

int make_print_u(t_flag *flag, va_list *ap, t_pt *pt)
{

}

int make_print_x(t_flag *flag, va_list *ap, t_pt *pt)
{

}

*/