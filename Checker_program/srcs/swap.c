/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:22:41 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/19 17:42:27 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	if ((!s1 || !s2))
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0')))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	swap_a(t_push_swap *push_swap)
{
	char		*p;

	if (count_line(push_swap->a) <= 1)
	{
		push_swap->checker = 1;
		return ;
	}
	p = ft_strdup(push_swap->a[0]);
	free(push_swap->a[0]);
	push_swap->a[0] = ft_strdup(push_swap->a[1]);
	free(push_swap->a[1]);
	push_swap->a[1] = ft_strdup(p);
	ft_free_arr((void **)&p);
}

void	swap_b(t_push_swap *push_swap)
{
	char	*p;

	if (count_line(push_swap->b) <= 1)
	{
		push_swap->checker = 1;
		return ;
	}
	p = ft_strdup(push_swap->b[0]);
	free(push_swap->b[0]);
	push_swap->b[0] = ft_strdup(push_swap->b[1]);
	free(push_swap->b[1]);
	push_swap->b[1] = ft_strdup(p);
	ft_free_arr((void **)&p);
}
