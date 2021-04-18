/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:36:48 by amine             #+#    #+#             */
/*   Updated: 2021/04/18 15:59:45 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pri_check(t_push_swap *push_swap, char *msg)
{
	if (push_swap->check_flags == 2)
	{
		red();
		ft_putstr_fd(msg, 1);
		write(1, "\n", 1);
	}	
	else
		ft_putendl_fd(msg, 1);
	if (push_swap->check_flags == 3)
		print_a_b(push_swap);
}

void	rotate(char **a, t_push_swap *push_swap, char *msg)
{
	char	*p;
	int		i;
	int		j;

	j = 1;
	i = 0;
	if (!a)
	{
		push_swap->checker = 1;
		return ;
	}
	p = ft_strdup(a[0]);
	while (a[j])
	{
		free(a[i]);
		a[i] = ft_strdup(a[j]);
		i++;
		j++;
	}
	free(a[i]);
	a[i] = ft_strdup(p);
	ft_free_arr((void **)&p);
	pri_check(push_swap, msg);
}

void	ret_if_not_a(t_push_swap *push_swap)
{
	push_swap->checker = 1;
	return ;
}

void	pri_check_2(t_push_swap *push_swap, char *msg)
{
	if (push_swap->check_flags == 2)
	{
		yellow();
		ft_putstr_fd(msg, 1);
		write(1, "\n", 1);
	}	
	else
		ft_putendl_fd(msg, 1);
	if (push_swap->check_flags == 3)
		print_a_b(push_swap);
}

void	rot_rot(char **a, t_push_swap *push_swap, char *msg)
{
	char	**new_a;

	push_swap->len = count_line(a);
	push_swap->j = 1;
	push_swap->i = 0;
	if (!a)
		return (ret_if_not_a(push_swap));
	new_a = malloc(sizeof(char *) * (push_swap->len + 1));
	new_a[0] = ft_strdup(a[push_swap->len - 1]);
	while (push_swap->i < push_swap->len - 1)
	{
		new_a[push_swap->j] = ft_strdup(a[push_swap->i]);
		push_swap->j++;
		push_swap->i++;
	}
	new_a[push_swap->j] = NULL;
	push_swap->j = -1;
	while (new_a[++push_swap->j])
	{
		free(a[push_swap->j]);
		a[push_swap->j] = ft_strdup(new_a[push_swap->j]);
	}
	if (new_a)
		ft_free_2dem_arr((void ***)&new_a);
	pri_check_2(push_swap, msg);
}
