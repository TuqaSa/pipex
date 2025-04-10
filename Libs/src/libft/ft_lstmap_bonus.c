/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:11:03 by tsaeed            #+#    #+#             */
/*   Updated: 2024/09/18 17:00:09 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*ret;
	void	*new;

	ret = NULL;
	while (lst)
	{
		new = f(lst->content);
		n = ft_lstnew(new);
		if (!n)
		{
			ft_lstclear(&ret, del);
			del(new);
			return (NULL);
		}
		ft_lstadd_back(&ret, n);
		lst = lst->next;
	}
	return (ret);
}
