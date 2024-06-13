/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:34:00 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/13 14:50:37 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

#define RED "\033[0;31m"
#define RESET "\033[0m"

static void	send_signal(int pid, char *str)
{
	unsigned char	hold;
	int				i;
	int				j;
	int				k;

	j = strlen(str);
	k = 0;
	hold = 0;
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
	int	pid;

	if (argc != 3)
	{
		ft_printf("%sUsage: ./client <PID> <message>%s\n", RED, RESET);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1 || kill(pid, 0) == -1)
	{
		ft_printf("%sInvalid PID%s\n", RED, RESET);
		return (1);
	}
	send_signal(pid, argv[2]);
	return (0);
}
