/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:51:37 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/07 16:51:44 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_last;

	if (!lst)
		return ;
	temp_last = ft_lstlast(*lst);
	if (!temp_last)
		*lst = new;
	else
		temp_last->next = new;
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
// 	t_list	*n4;
//     n1 = ft_lstnew("a1");
//     n2 = ft_lstnew("a2");
//     n3 = ft_lstnew("a3");
// 	n4 = ft_lstnew("lalalalast");
// 	ft_lstadd_back(&n1, n2);
// 	ft_lstadd_back(&n2, n3);
// 	ft_lstadd_back(&n3, n4);
// 	show_list(n1);
// 	t_list *last;
// 	last = ft_lstlast(n1);
//     printf("coutent = %s \n", last->content);
// }