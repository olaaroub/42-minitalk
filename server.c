/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:53:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/13 15:04:49 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

static void	signal_handler(int sig_val, siginfo_t *info, void *other)
{
	static unsigned char	curr_char;
	static int				curr_bit;
	static int				is_pid_diff;

	(void)(*other);
	if (is_pid_diff != info->si_pid)
	{
		curr_bit = 0;
		curr_char = 0;
		is_pid_diff = info->si_pid;
	}
	curr_char |= (sig_val == SIGUSR1);
	curr_bit++;
	if (curr_bit == 8)
	{
		if (curr_char == 0)
			write(1, "\n", 1);
		else
			write(1, &curr_char, 1);
		curr_bit = 0;
		curr_char = 0;
	}
	else
		curr_char <<= 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%s%d%s\n", GREEN, pid, RESET);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		;
	return (0);
}
