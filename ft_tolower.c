

int ft_tolower(int a)
{
	if (a >= 'A' && a <= 'Z')
		a = a + ('a' - 'A');
	return (a);
}
