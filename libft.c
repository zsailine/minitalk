/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:43:28 by zsailine          #+#    #+#             */
/*   Updated: 2024/06/19 10:46:25 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

static int	count_digit(int nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		nb *= (-1);
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		nbr_len;
	int		i;

	nbr_len = count_digit(n);
	i = count_digit(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	dest = (char *)ft_calloc(nbr_len + 1, sizeof(char));
	if (!dest)
		return (0);
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		dest[i--] = (n % 10) + 48;
		n /= 10;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	i = 0;
	if (!(dest))
		return (0);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;
	size_t	calculation;

	calculation = size * nmemb;
	calloc = malloc(calculation);
	if (!calloc)
		return (0);
	ft_bzero(calloc, calculation);
	return (calloc);
}
