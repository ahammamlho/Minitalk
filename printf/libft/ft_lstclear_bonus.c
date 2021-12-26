/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:24:37 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 12:16:14 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		ft_lstdelone(temp, del);
		temp = temp->next;
	}
	*lst = 0;
}

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	del(lst->content);
// 	free(lst);
// }
// int main()
// {
// }