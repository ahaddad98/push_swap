/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:44:11 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/18 16:48:22 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	is_empty_com(t_push_swap *push_swap, char **new_a)
{
	int		i;
	int		j;

	new_a = malloc(sizeof(char *) * (count_line(push_swap->a) + 1));
	i = 0;
	j = 1;
	while (push_swap->a[j])
	{
		new_a[i] = ft_strdup(push_swap->a[j]);
		free(push_swap->a[i]);
		i++;
		j++;
	}
	free(push_swap->a[i]);
	new_a[i] = NULL;
	i = 0;
	while (new_a[i])
	{
		push_swap->a[i] = ft_strdup(new_a[i]);
		i++;
	}
	push_swap->a[i] = NULL;
	if (new_a)
		ft_free_2dem_arr((void ***)&new_a);
}

void	is_empty(t_push_swap *push_swap, char **new_a, char **new_b)
{
	new_b = malloc(sizeof(char *) * 2);
	new_b[0] = ft_strdup(push_swap->a[0]);
	new_b[1] = NULL;
	push_swap->b = ft_strdup_2d(new_b);
	if (new_b)
		ft_free_2dem_arr((void ***)&new_b);
	if ((count_line(push_swap->a) - 1) <= 0)
	{
		if (push_swap->a)
			ft_free_2dem_arr((void ***)&push_swap->a);
	}
	else
		is_empty_com(push_swap, new_a);
}

void	isnt_empty_com(t_push_swap *push_swap, char **new_a)
{
	int		i;
	int		j;

	new_a = malloc(sizeof(char *) * (count_line(push_swap->a) + 1));
	i = 0;
	j = 1;
	while (push_swap->a[j])
	{
		new_a[i] = ft_strdup(push_swap->a[j]);
		free(push_swap->a[i]);
		i++;
		j++;
	}
	free(push_swap->a[i]);
	new_a[i] = NULL;
	i = 0;
	while (new_a[i])
	{
		push_swap->a[i] = ft_strdup(new_a[i]);
		i++;
	}
	push_swap->a[i] = NULL;
	if (new_a)
		ft_free_2dem_arr((void ***)&new_a);
}

void	isnt_empty(t_push_swap *push_swap, char **new_a, char **new_b, int i)
{
	int		j;

	j = 1;
	new_b = NULL;
	new_b = malloc(sizeof(char *) * (count_line(push_swap->b) + 2));
	new_b[0] = ft_strdup(push_swap->a[0]);
	while (push_swap->b[++i])
	{
		new_b[j] = ft_strdup(push_swap->b[i]);
		free(push_swap->b[i]);
		j++;
	}
	free(push_swap->b);
	new_b[j] = NULL;
	push_swap->b = ft_strdup_2d(new_b);
	if (new_b)
		ft_free_2dem_arr((void ***)&new_b);
	if ((count_line(push_swap->a) - 1) <= 0)
	{
		if (push_swap->a)
			ft_free_2dem_arr((void ***)&push_swap->a);
	}
	else
		is_empty_com(push_swap, new_a);
}

void	push_b(t_push_swap *push_swap)
{
	char	**new_a;
	char	**new_b;
	int		i;

	i = -1;
	new_a = NULL;
	new_b = NULL;
	if (push_swap->a == NULL)
	{
		push_swap->checker = 1;
		return ;
	}
	if (!push_swap->b)
		is_empty(push_swap, new_a, new_b);
	else
		isnt_empty(push_swap, new_a, new_b, i);
	if (push_swap->check_flags == 2)
		ft_putendl_fd("\e[1;31mpb\e[0;27m", 1);
	else
		ft_putendl_fd("pb", 1);
	if (push_swap->check_flags == 3)
		print_a_b(push_swap);
}
