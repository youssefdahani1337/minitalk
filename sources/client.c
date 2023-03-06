/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:29:49 by yodahani          #+#    #+#             */
/*   Updated: 2023/02/19 10:10:59 by yodahani         ###   ########.fr       */
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
			r = msg[j] & 128;
			if (r == 128 && kill(pid, SIGUSR1) == -1)
				ft_exit();
			else if (r == 0 && kill(pid, SIGUSR2) == -1)
				ft_exit();
			msg[j] = msg[j] << 1;
			i++;
			usleep(400);
		}
		usleep(200);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

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
	ft_send((unsigned char *)argv[2], pid);
	return (0);
}
