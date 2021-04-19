/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:30:44 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/19 17:40:19 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_if_duplic(t_push_swap *push_swap)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (push_swap->a && push_swap->a[i])
	{
		j = i + 1;
		while (push_swap->a && push_swap->a[j])
		{
			if (ft_atoi(push_swap->a[i]) == ft_atoi(push_swap->a[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_sort(t_push_swap *push_swap)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (push_swap->a && push_swap->a[i])
	{
		j = i + 1;
		while (push_swap->a[j])
		{
			if (ft_atoi(push_swap->a[i]) > ft_atoi(push_swap->a[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	free_ret(char **tab)
{
	ft_free_2dem_arr((void ***)&tab);
	return (1);
}

void	p_s_now(t_push_swap *push_swap, int len)
{
	push_swap->b = NULL;
	push_swap->checker = 0;
	len = count_line(push_swap->a);
	which_algo(push_swap, len);
}
