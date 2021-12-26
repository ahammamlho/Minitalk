/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:10:33 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 12:16:34 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
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
// 	t_list	*n1, *n2, *n3, *n4;
//     n1 = ft_lstnew("n1");
//     n2 = ft_lstnew("n2");
//     n3 = ft_lstnew("n3");
// 	n4 = ft_lstnew("n4");

//     ft_lstadd_back(&n1, n2);
//     ft_lstadd_back(&n2, n3);
// 	ft_lstadd_back(&n3, n4);

//     show_list(n1);
//    ft_lstdelone( n2, free);
//     // printf("-------------\n");
//     // show_list(n1);

// }