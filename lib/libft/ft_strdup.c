/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:39 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/18 16:37:37 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len);
	return (res);
}
