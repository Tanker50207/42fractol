/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:24:25 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/17 12:05:18 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static int	ft_start(char const *s1, char const *set)
{
	int	index;

	index = 0;
	while (s1[index] && ft_isinset(s1[index], set))
		index++;
	return (index);
}

static int	ft_end(char const *s1, char const *set)
{
	int	index;

	index = ft_strlen(s1) - 1;
	while (index >= 0 && ft_isinset(s1[index], set))
		index--;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (0);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
