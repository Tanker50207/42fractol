/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:14:06 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/18 16:37:26 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	if (str[i] == (char)c)
	{
		return (&str[i]);
	}
	return (0);
}
