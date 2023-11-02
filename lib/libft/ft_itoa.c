/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:22:55 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/17 14:02:47 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	len;

	len = n == 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = (long) n;
	len = ft_intlen(nb);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0 || (len == 1 && nb == 0 && str[0] != '-'))
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
