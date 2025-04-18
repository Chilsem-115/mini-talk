

#include "minitalk.h"

int	g_flag;

static void	sig_handler(int sig)
{
	(void)sig;
	g_flag = 1;
}

static void	setup_signal(void)
{
	signal(SIGUSR1, sig_handler);
}

static void	send_bit(int bit, pid_t pid)
{
	g_flag = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if(bit == 1)
		kill(pid, SIGUSR2);
	usleep(200);
	while (!g_flag)
		pause();
}

static void	send_char(char c, pid_t pid)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		send_bit((c >> i) & 1, pid);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (!validate(argc, argv, &pid))
	{
		ft_dprintf(2, "Usage: ./client <pid> <msg>\n");
		return (1);
	}
	setup_signal();
	i = 0;
	while (argv[2][i])
	{
		send_char(argv[2][i], pid);
		i++;
	}
	return (0);
}
