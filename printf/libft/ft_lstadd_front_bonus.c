/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:56:29 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 16:40:10 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

// void show_list(t_list *head)
// {
//     while (head)
//     {
//      printf("%s - %p \n",head->content,head);
//      head = head->next;
//     }
// }
// t_list *ft_lstnew(void *content)
// {
//     t_list	*result;
// 	result = (t_list *)malloc(sizeof(t_list));
// 	result->content = content;
// 	result->next = 0;
// 	return(result);
// }
// int main()
// {
// 	t_list	*n1;
//     t_list	*n2;
//     t_list	*n3;

//     n1 = ft_lstnew("a1");
//     n2 = ft_lstnew("a2");
//     n3 = ft_lstnew("a3");
//     ft_lstadd_front( &n3, n2);
//     ft_lstadd_front( &n2, n1);

//     show_list(n1);
// }