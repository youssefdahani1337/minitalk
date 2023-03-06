/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:30:19 by yodahani          #+#    #+#             */
/*   Updated: 2023/02/19 12:37:33 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define  MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

void	ft_send(unsigned char *msg, int p_id);
void	ft_receive(int signal, siginfo_t *info, void *context);
void	ft_convert(char *msg);
void	ft_receive(int signal, siginfo_t *info, void *context);
#endif