/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:34:00 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/10 19:08:32 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

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
	unsigned int	pid;

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
	send_signal(pid, argv[2]);
	return (0);
}
