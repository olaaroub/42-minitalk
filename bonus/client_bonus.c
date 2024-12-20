/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:25:34 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/13 15:01:37 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int			g_recieved_signal = 0;

static void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("%sMessage sent successfully%s\n", GREEN, RESET);
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
			usleep(80);
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
		ft_printf("%sUsage: ./client_bonus <PID> <message>%s\n", YELLOW, RESET);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1 || pid == -1)
	{
		ft_printf("%sInvalid PID%s\n", RED, RESET);
		return (1);
	}
	sa.sa_handler = handle_sig;
	sigaction(SIGUSR1, &sa, NULL);
	send_signal(pid, argv[2]);
	while (g_recieved_signal == 0)
		;
	return (0);
}
