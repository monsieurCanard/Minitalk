/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:02:34 by anthony           #+#    #+#             */
/*   Updated: 2023/12/06 09:13:55 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid_sign = 0;

void	handler(int bit, siginfo_t *info, void *context)
{
	(void)context;
	if (bit == SIGUSR1)
	{
		g_pid_sign = info->si_pid;
	}
	else if (bit == SIGUSR2)
	{
		g_pid_sign = info->si_pid;
		g_pid_sign *= -1;
	}
}

void	initialize_text(struct my_char *text)
{
	int	i;

	i = 0;
	text->nb_bits = 0;
	text->binary = malloc(8);
	if (!text->binary)
		return ;
	while (i <= 8)
	{
		text->binary[i] = 0;
		i++;
	}
	return ;
}

void	print_letter(char *binary)
{
	int	decimal;
	int	i;

	i = 7;
	decimal = 0;
	while (i >= 0)
	{
		decimal = decimal * 2;
		if (binary[i] == '1')
			decimal += 1;
		i--;
	}
	write (1, &decimal, 1);
	return ;
}

void	update_char(struct my_char *text, int pid)
{
	if (pid > 0)
	{
		text->binary[text->nb_bits] = '0';
		text->nb_bits++;
		g_pid_sign = 0;
		if (text->nb_bits == 8)
		{
			print_letter(text->binary);
			initialize_text(text);
		}
		kill (pid, SIGUSR1);
	}
	else
	{
		text->binary[text->nb_bits] = '1';
		text->nb_bits++;
		g_pid_sign = 0;
		if (text->nb_bits == 8)
		{
			print_letter(text->binary);
			initialize_text(text);
		}
		kill (pid * (-1), SIGUSR1);
	}
	return ;
}

int	main(void)
{
	struct my_char		text;
	struct sigaction	signal;
	int					check_pid;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID du serveur est : %d\n", pid);
	ft_bzero(&signal, sizeof(signal));
	initialize_text(&text);
	signal.sa_sigaction = handler;
	signal.sa_flags = SA_SIGINFO;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
		if (g_pid_sign)
		{
			if (check_pid != g_pid_sign && check_pid != g_pid_sign * (-1))
				initialize_text(&text);
			check_pid = g_pid_sign;
			update_char(&text, check_pid);
		}
	}
	return (0);
}
