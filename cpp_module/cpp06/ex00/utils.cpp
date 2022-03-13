#include <iostream>

bool ft_isidigit(char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}