/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:55:52 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/19 12:01:41 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	nb;

	if (!str)
		return (0);
	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		neg = -1 + 0 * (i++);
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	nb = nb * neg;
	return (nb);
}
