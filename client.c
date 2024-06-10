/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:34:00 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/10 15:36:05 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int msg = -1;
void	handle_sig(int sig)
{
	if(sig == SIGUSR1)
	{
		write(1, "msg wsel\n", 9);
		msg = 1;
	}
}

void send_signal(int pid, char *str)
{
	unsigned char hold;
	int i;
	int  j = strlen(str);
	int k = 0;
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
			usleep(42);
			i--;
		}
		k++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    struct sigaction sa;

    sa.sa_handler = handle_sig;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    send_signal(pid, argv[2]);

    while (msg == -1)
        	; // Wait for signals

    return 0;
}
// 	int pid;
// 	(void)ac;
// 	struct sigaction sa;
	
// 	sa.sa_handler = handle_sig;
// 	pid = atoi(av[1]);
// 	send_signl(pid, av[2]);
// 	sigaction(SIGUSR1, &sa, NULL);
// 	while(1)
// 		if(msg == 1)
// 			break;
// }
