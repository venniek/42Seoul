#include "printf.h"

int make_print_c(t_flag *flag, va_list *ap, t_pt *pt)
{
    char c;

    c = va_arg(*ap, char);
    if (flag->zero == 1 || flag->prec != -1)
        return (UNDEFINED);
    if (flag->minus == 1)
        pt->minus = 1;
    if (flag->width != -1)
        pt->b_len = flag->width - 1;
    
    
}


int make_print_s(t_flag *flag, va_list *ap)
{
    
}

int make_print_d(t_flag *flag, va_list *ap)
{
    
}

