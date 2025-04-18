
#include "minitalk.h"

double	ft_atoi(const char *str)
{
	double	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (-1);
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	valid_pid(const char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate(int argc, char **argv, pid_t *pid)
{
	if (argc != 3 || !valid_pid(argv[1]))
		return (0);
	*pid = ft_atoi(argv[1]);
	if (*pid <= 0)
		return (0);
	return (1);
}
