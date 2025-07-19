#include "push_swap.h"

int	is_spaces(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_operator(char c)
{
	return (c == '+' || c == '-');
}

int	ft_atoi(char *str)
{
	int		result;
	int		sign;

	while (*str && is_spaces(*str))
		++str;
	sign = 1;
	if (is_operator(*str))
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		++str;
	}
	return (sign * result);
}
