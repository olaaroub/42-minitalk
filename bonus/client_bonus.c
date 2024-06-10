/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:25:34 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/10 20:02:23 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

int			g_recieved_signal = 0;

static void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message sent successfully\n", 26);
		g_recieved_signal = 1;
	}
}

static void	send_signal(int pid, char *str)
{
	unsigned char	hold;
	int				i;
	int				j;
	int				k;

	j = strlen(str);
	hold = 0;
	k = 0;
	while (k <= j)
	{
		i = 7;
		while (i >= 0)
		{
			hold = ((str[k]) >> i);
			if ((hold & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			i--;
		}
		k++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n");
		return (1);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_printf("<PID> Should be > 0\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_handler = handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	send_signal(pid, argv[2]);
	while (recieved_signal == 0)
		;
	return (0);
}
