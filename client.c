/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:34:00 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/09 14:41:11 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void send_signl(int pid, char *str)
{
	unsigned char hold;
	int i;
	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			hold = ((*str) >> i);
			if ((hold & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(42);
			i--;
		}
		str++;
	}
}

int main(int ac, char **av)
{
	int pid;
	(void)ac;
	pid = atoi(av[1]);
	send_signl(pid, av[2]);
}
