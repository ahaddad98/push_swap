/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:09:59 by amine             #+#    #+#             */
/*   Updated: 2021/04/18 13:31:55 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_under_pivot(char **ag, int pivot)
{
	int		i;

	i = 0;
	while (ag && ag[i])
	{
		if (ft_atoi(ag[i]) < pivot)
			return (1);
		i++;
	}
	return (0);
}

int	check_bigg_pivot(char **ag, int pivot)
{
	int		i;

	i = 0;
	while (ag && ag[i])
	{
		if (ft_atoi(ag[i]) >= pivot)
			return (1);
		i++;
	}
	return (0);
}

int	get_index(t_push_swap *push_swap, int med)
{
	int		i;

	i = 0;
	while (push_swap->a[i])
	{
		if (ft_atoi(push_swap->a[i]) < med)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	get_index2(t_push_swap *push_swap, int med)
{
	int		i;

	i = 0;
	while (push_swap->a[i])
	{
		if (ft_atoi(push_swap->a[i]) > med)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	get_index1(t_push_swap *push_swap, int med)
{
	int		i;

	i = 0;
	while (push_swap->b[i])
	{
		if (ft_atoi(push_swap->b[i]) >= med)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
