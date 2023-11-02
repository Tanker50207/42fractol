/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:13 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/17 13:03:29 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[index] = f(index, s[index]);
		index++;
	}
	return (str);
}
