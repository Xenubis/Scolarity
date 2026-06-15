/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvignes <mvignes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:05:33 by mvignes           #+#    #+#             */
/*   Updated: 2026/03/17 17:50:13 by mvignes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	if (!content)
		return (NULL);
	element = malloc(sizeof(t_list));
	if (!element)
		return (0);
	element->content = content;
	element->next = 0;
	return (element);
}
