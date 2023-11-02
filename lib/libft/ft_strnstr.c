/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:51 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/18 16:39:10 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	hay_index;
	unsigned int	needle_index;

	if (!haystack || !needle)
		return (0);
	hay_index = 0;
	if (!needle[hay_index])
		return ((char *)haystack);
	while (haystack[hay_index] && hay_index < len)
	{
		needle_index = 0;
		while (needle[needle_index] && haystack[hay_index + needle_index]
			&& needle[needle_index] == haystack[hay_index + needle_index]
			&& hay_index + needle_index < len)
			needle_index++;
		if (!needle[needle_index])
			return ((char *)&haystack[hay_index]);
		hay_index++;
	}
	return (0);
}
