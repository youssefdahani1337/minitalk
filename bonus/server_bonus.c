/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:30:08 by yodahani          #+#    #+#             */
/*   Updated: 2023/02/19 11:45:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit(void)
{
	ft_printf("\033[0;31m \n!Oop something is wrong \033[0m\n");
	exit(0);
}

void	ft_set(unsigned char *msg, char *len)
{
	*msg = 0;
	*len = 0;
	write(1, "\n", 1);
}

void	ft_receive(int signal, siginfo_t *info, void *context)
{
	static char				len;
	static unsigned char	msg;
	static int				id;

	(void)context;
	if (id != info->si_pid)
	{
		id = info->si_pid;
		ft_set(&msg, &len);
		kill(id, SIGUSR1);
		return ;
	}
	if (signal == SIGUSR1)
		msg |= 1;
	if (++len == 8)
	{
		write(1, &msg, 1);
		msg = 0;
		len = 0;
	}
	msg = msg << 1;
	usleep(300);
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_exit();
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("\033[0;32m The server is ready \033[0m \n");
	ft_printf(" The ID is: %d \n", getpid());
	sig.sa_sigaction = ft_receive;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
