/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:49 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/18 16:38:58 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	if (!s1 || !s2)
		return (0);
	i = 0;
	res = 0;
	while (i < n && res == 0 && s1[i] && s2[i])
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (res == 0 && i < n)
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}
