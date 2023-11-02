/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:53 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/18 16:39:29 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	if (!s)
		return (0);
	index = ft_strlen(s);
	while (index > 0)
	{
		if (s[index] == (char) c)
			return ((char *) &s[index]);
		index--;
	}
	if (s[index] == (char) c)
		return ((char *) &s[index]);
	return (0);
}
