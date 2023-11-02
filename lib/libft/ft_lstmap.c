/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:42:46 by gcrepin           #+#    #+#             */
/*   Updated: 2023/10/17 15:17:06 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*tmp;
	void	*content;

	if (!(lst) || !(f))
		return (0);
	n_lst = 0;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!(tmp))
		{
			free(content);
			ft_lstclear(&n_lst, del);
			return (0);
		}
		ft_lstadd_back(&n_lst, tmp);
		lst = lst->next;
	}
	return (n_lst);
}
