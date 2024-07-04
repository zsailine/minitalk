/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:22:14 by zsailine          #+#    #+#             */
/*   Updated: 2024/06/22 09:40:06 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (n--)
		*a++ = 0;
}

void	get_signal(int sent)
{
	static char		c;
	static int		i = 0;
	static t_list	*dest = NULL;

	c = c | (sent == (SIGUSR1));
	i++;
	if (i <= 7)
		c = c << 1;
	else if (i == 8)
	{
		if (c == 0)
		{
			add_back(&dest, c);
			ft_print(dest);
			free_list(&dest);
		}
		else
			add_back(&dest, c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*print;

	pid = getpid();
	print = ft_itoa(pid);
	write(1, print, ft_strlen(print));
	free(print);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, get_signal);
		signal(SIGUSR2, get_signal);
	}
	return (0);
}
