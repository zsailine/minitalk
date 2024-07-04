/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:21:54 by zsailine          #+#    #+#             */
/*   Updated: 2024/06/29 09:46:47 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	nbr = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr *= 10;
		nbr += nptr[i] - '0';
		i++;
	}
	if (!(sign))
		return (nbr);
	else
		return (-nbr);
}

void	send_binary(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(250);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (!av[2])
		{
			write(2, "error\n", 6);
			return (0);
		}
		while (av[2][i])
		{
			send_binary(pid, av[2][i]);
			i++;
		}
		send_binary(pid, '\0');
	}
	else
		write(2, "error\n", 6);
	return (0);
}
