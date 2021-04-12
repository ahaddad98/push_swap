/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:09:59 by amine             #+#    #+#             */
/*   Updated: 2021/04/13 01:14:44 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


int check_under_pivot(char **ag, int pivot)
{
    int i;
    i = 0;
    while (ag && ag[i])
    {
        if (ft_atoi(ag[i]) < pivot)
            return (1);
        i++;
    }
    return (0);
}

int check_bigg_pivot(char **ag, int pivot)
{
    int i;
    i = 0;

    while (ag && ag[i])
    {
        if (ft_atoi(ag[i]) >= pivot)
            return (1);
        i++;
    }
    return (0);
}

int get_index(t_push_swap *push_swap, int med)
{
    int i = 0;

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

int get_index2(t_push_swap *push_swap, int med)
{
    int i = 0;

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

int get_index1(t_push_swap *push_swap, int med)
{
    int i = 0;

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

int get_max(t_push_swap *push_swap)
{
    int i = 1;
    push_swap->max_index = 0;
    if (push_swap->b && push_swap->b[0])
        push_swap->max_in_arr = ft_atoi(push_swap->b[0]);
    while (push_swap->b && push_swap->b[i]) //&& i != 20
    {
        if (push_swap->max_in_arr < ft_atoi(push_swap->b[i]))
        {
            push_swap->max_in_arr = ft_atoi(push_swap->b[i]);
        }
        i++;
    }
    return (push_swap->max_in_arr);
}

int get_min(t_push_swap *push_swap)
{
    int i = 1;
    push_swap->max_index = 0;
    if (push_swap->a && push_swap->a[0])
        push_swap->max_in_arr = ft_atoi(push_swap->a[0]);
    while (push_swap->a && push_swap->a[i]) //&& i != 20
    {
        if (push_swap->max_in_arr > ft_atoi(push_swap->a[i]))
        {
            push_swap->max_in_arr = ft_atoi(push_swap->a[i]);
        }
        i++;
    }
    return (push_swap->max_in_arr);
}