/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:23:42 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/17 13:03:37 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!(s[i] == c) && s[i])
			nb_words++;
		while (!(s[i] == c) && s[i])
			i++;
	}
	return (nb_words);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (!(s[len] == c) && s[len])
		len++;
	return (len);
}

static	void	*ft_free(char **result, int nb_words)
{
	int	i;

	i = 0;
	while (i < nb_words)
		free(result[i++]);
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nb_words;
	int		i;

	if (!s)
		return (0);
	result = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (0);
	nb_words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			result[nb_words++] = ft_substr(s, i, ft_wordlen(&s[i], c));
			if (!result[nb_words - 1])
				return ((char **)ft_free(result, nb_words));
			i += ft_wordlen(&s[i], c);
		}
	}
	return (result);
}
