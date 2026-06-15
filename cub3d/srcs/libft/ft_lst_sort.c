/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:43:50 by mvignes           #+#    #+#             */
/*   Updated: 2026/04/22 09:46:30 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lst_sort(t_list *lst)
{
	t_list	*i;
	t_list	*j;
	int		n;
	char	*tmp;

	i = lst;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (ft_strlen(i->content) >= ft_strlen(j->content))
				n = ft_strlen(i->content);
			else
				n = ft_strlen(j->content);
			if (ft_strncmp(i->content, j->content, n) > 0)
			{
				tmp = i->content;
				i->content = j->content;
				j->content = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
