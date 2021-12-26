/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:45:12 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 16:39:46 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

// void show_list(t_list *head)
// {
//     while (head)
//     {
//      printf("%s \n",head->content);
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
// 	t_list	*n4;
//     n1 = ft_lstnew("a1");
//     n2 = ft_lstnew("a2");
//     n3 = ft_lstnew("a3");
// 	n4 = ft_lstnew("lalalalast");
//     ft_lstadd_front( &n3, n2);
//     ft_lstadd_front( &n2, n1);
// 	ft_lstadd_front( &n, n4);
//     show_list(n1);
// 	t_list *last;
// 	last = ft_lstlast(n2);
//     printf("coutent = %s \n", last->content);
// }