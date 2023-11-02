/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:38:32 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/31 12:44:14 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return ;
	while (s[index])
		f(&s[index++]);
}
