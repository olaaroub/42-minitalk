/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:26:16 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/12 19:34:37 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

void	inform_client(siginfo_t *info)
{
	write(1, "\n", 1);
	kill(info->si_pid, SIGUSR1);
}

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
			inform_client(info);
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
	ft_printf("\033[0;32m%d\033[0m\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		;
	return (0);
}
