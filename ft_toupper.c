

int ft_toupper(int a)
{
	if (a >= 'a' && a <= 'z')
		a = a - ('a' - 'A');
	return (a);
}
