/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:41:38 by zsailine          #+#    #+#             */
/*   Updated: 2024/06/21 13:04:30 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_list
{
	char			c;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(char content);
void	add_back(t_list **list, char content);
t_list	*get_last(t_list *list);
void	ft_print(t_list *list);
void	send_binary(pid_t pid, char c);
int		ft_atoi(const char *nptr);
void	get_signal(int sent);
void	free_list(t_list **list);
char	*ft_itoa(int n);
size_t	ft_strlen(char *src);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif