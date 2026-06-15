/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create_and_addback.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:39:30 by mvignes           #+#    #+#             */
/*   Updated: 2026/04/22 09:45:46 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lst_create_and_addback(t_list **lst, char *str)
{
	char	*tmp;
	t_list	*new_node;

	tmp = ft_strdup(str);
	if (!tmp)
		return ;
	new_node = ft_lstnew(tmp);
	if (!new_node)
	{
		free(tmp);
		return ;
	}
	ft_lstadd_back(lst, new_node);
}
