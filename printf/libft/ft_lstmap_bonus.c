/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:05:39 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 12:49:32 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	result = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp != 0)
			ft_lstadd_back(&result, temp);
		else
		{
			ft_lstclear(&result, del);
			return (0);
		}
		lst = lst->next;
	}
	return (result);
}
