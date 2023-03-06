/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:46:16 by yodahani          #+#    #+#             */
/*   Updated: 2023/02/19 11:41:48 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit(void)
{
	ft_printf("\033[0;31m !Oop something is wrong \033[0m\n");
	exit(0);
}

void	ft_send(unsigned char *msg, int pid)
{
	int				j;
	char			i;
	unsigned char	r;

	j = 0;
	while (msg[j])
	{	
		i = 0;
		while (i < 8)
		{
			usleep(100);
			r = msg[j] & 128;
			i++;
			if (r == 128 && kill(pid, SIGUSR1) == -1)
				ft_exit();
			else if (r == 0 && kill(pid, SIGUSR2) == -1)
				ft_exit();
			msg[j] = msg[j] << 1;
			pause();
		}
		j++;
	}
}

void	ft_n(int signal)
{
	ft_printf("✅ \n");
	(void)signal;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	if (argc != 3)
	{
		ft_printf("\033[0;31m Entre 2 arguments !! \033[0m\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("\033[0;31m Invalid id \033[0m\n");
		return (0);
	}
	sig.sa_handler = ft_n;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	kill(pid, SIGUSR1);
	pause();
	ft_send((unsigned char *)argv[2], pid);
	return (0);
}
