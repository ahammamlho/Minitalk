/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:37:03 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/08 12:54:18 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// t_list *ft_lstnew(void *content)
// {
//     t_list	*result;
// 	result = (t_list *)malloc(sizeof(t_list));
// 	result->content = content;
// 	result->next = 0;
// 	return(result);
// }

// void f(void *s)
// {
//     s++;
// }

// int main()
// {
//     t_list *n1;
//     n1 = ft_lstnew("12345689");
//     printf("%s \n", n1->content);
//     ft_lstiter(n1, f);
//     printf("%s \n", n1->content);
// }