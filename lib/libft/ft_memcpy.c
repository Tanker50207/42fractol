/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:30 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/19 12:15:49 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	if (!dst || !src)
		return (dst);
	dest2 = (unsigned char *) dst;
	src2 = (const unsigned char *) src;
	while (n--)
		*dest2++ = *src2++;
	return (dst);
}
