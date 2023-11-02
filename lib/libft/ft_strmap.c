/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:20 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/31 12:43:23 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	char			*str;
	unsigned int	index;

	if (!s || !f)
		return (0);
	str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!str)
		return (0);
	index = 0;
	while (s[index])
	{
		str[index] = f(index);
		index++;
	}
	return (str);
}
