/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:00:39 by anthony           #+#    #+#             */
/*   Updated: 2023/12/05 14:30:57 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_signal_received = 0;

void	handler(int bit, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (bit == SIGUSR1)
	{
		g_signal_received = 1;
	}
	return ;
}

void	send_char(int pid, char *texte)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (texte[++i])
	{
		while (j < 8)
		{
			k = (texte[i] >> j++) & 1;
			g_signal_received = 0;
			if (k == 1)
				kill(pid, SIGUSR2);
			else if (k == 0)
				kill(pid, SIGUSR1);
			while (g_signal_received == 0)
			{
			}
		}
		j = 0;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	signal;

	if (argc != 3)
	{
		ft_printf("Error with message information, please retry\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	signal.sa_sigaction = handler;
	signal.sa_flags = 0;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	send_char(pid, argv[2]);
}
