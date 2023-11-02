/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:34 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/19 12:19:11 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	if (!dst || !src)
		return (dst);
	i = 0;
	dest2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dest2 > src2 && dest2 < src2 + n)
	{
		while (i < n)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	else if (dest2 < src2 && dest2 + n > src2)
		while (i++ < n)
			dest2[i - 1] = src2[i - 1];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
