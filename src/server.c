
#include "minitalk.h"

// this is to prevent any issues related to changing the client
static void	reset_client(pid_t pid, pid_t *client, char *ch, int *count)
{
	if (*client != pid)
	{
		if (*client)
			write(1, "\n", 1);
		*client = pid;
		*ch = 0;
		*count = 0;
	}
}

// this is for processing each bit with its signal
static void	process_bit(int sig, char *ch)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		*ch <<= 1;
		if (sig == SIGUSR2)
			*ch |= 1;
	}
}

// this is for printing out the character once we're done
static void	handle_byte(char *ch, int *count)
{
	(*count)++;
	if (*count == 8)
	{
		write(1, ch, 1);
		*ch = 0;
		*count = 0;
	}
}

static void	handle_signal(int sig, siginfo_t *info, void *ptr)
{
	static char	ch;
	static int	count;
	static pid_t	client;

	(void)ptr;
	reset_client(info->si_pid, &client, &ch, &count);
	process_bit(sig, &ch);
	handle_byte(&ch, &count);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t		pid;

	pid = getpid();
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
