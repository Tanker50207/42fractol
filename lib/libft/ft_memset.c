/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:36 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/18 16:36:53 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (!b)
		return (0);
	ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
		ptr[i++] = (unsigned char) c;
	return (b);
}
