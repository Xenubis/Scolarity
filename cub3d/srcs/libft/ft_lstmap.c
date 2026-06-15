/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:59:18 by mvignes           #+#    #+#             */
/*   Updated: 2026/01/30 13:51:12 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy_list;
	t_list	*tmp_element;

	cpy_list = 0;
	while (lst)
	{
		tmp_element = ft_lstnew(f((lst)->content));
		if (!tmp_element)
		{
			ft_lstclear(&cpy_list, del);
			return (0);
		}
		ft_lstadd_back(&cpy_list, tmp_element);
		lst = lst->next;
	}
	return (cpy_list);
}
