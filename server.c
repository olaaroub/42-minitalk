/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:53:36 by olaaroub          #+#    #+#             */
/*   Updated: 2024/06/09 16:55:10 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define END_TRANSMISSION 0x04
void signal_handler(int sig_val)
{
	static unsigned char curr_char;
	static int curr_bit;
	curr_char |= (sig_val == SIGUSR1);
	curr_bit++;
	if (curr_bit == 8)
	{
		if (curr_char == END_TRANSMISSION)
			write(1, "\n", 1);
		else
			write(1, &curr_char, 1);
		curr_bit = 0;
		curr_char = 0;
	}
	else
		curr_char <<= 1;
}

int main(void)
{
	int pid;
	struct sigaction action;

	action.sa_handler = signal_handler;
	pid = getpid();
	printf("%d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		;
}
