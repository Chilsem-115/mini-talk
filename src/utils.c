
#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		nb = 0;
	int		sign = 1;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
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
