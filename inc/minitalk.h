#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	validate(int argc, char **argv, pid_t *pid);
int	valid_pid(const char *str);

#endif
