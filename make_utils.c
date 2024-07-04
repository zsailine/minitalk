/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:34 by zsailine          #+#    #+#             */
/*   Updated: 2024/06/21 13:04:17 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*next;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

t_list	*ft_lstnew(char content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->c = content;
	new->next = NULL;
	return (new);
}

void	add_back(t_list **list, char content)
{
	t_list	*new_node;
	t_list	*last;

	new_node = ft_lstnew(content);
	if (*list == NULL)
		*list = new_node;
	else
	{
		last = get_last(*list);
		last->next = new_node;
	}
}

t_list	*get_last(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_print(t_list *list)
{
	char	tmp;

	while (list)
	{
		tmp = list->c;
		write(1, &tmp, 1);
		list = list->next;
	}
}
