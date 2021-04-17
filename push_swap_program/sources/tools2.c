/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:09:01 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/17 03:39:50 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    push_now(t_push_swap *push_swap, int len_a, int i)
{
    int k;
    int j;
    
    k = 0;
    j = 0;
    while (push_swap->a && push_swap->a[0] && check_under_pivot(push_swap->a,
    ft_atoi(push_swap->med[i])))
    {
        len_a = count_line(push_swap->a) / 2;
        if (ft_atoi(push_swap->a[k]) < ft_atoi(push_swap->med[i]))
        {
            push_b(push_swap);
            j++;
        }
        else if (len_a >= get_index(push_swap, ft_atoi(push_swap->med[i])))
            rotate(push_swap->a, push_swap, "ra");
        else if (len_a < get_index(push_swap, ft_atoi(push_swap->med[i])))
            rot_rot(push_swap->a, push_swap, "rra");
    }
}

void    push_b_less_med(t_push_swap *push_swap , int len)
{
    int len_a = 0;
    int i = 0;

    if (len >= 2)
    {
        while (push_swap->med[i])
        {
            push_now(push_swap, len_a , i);
            i++;
        }
    }
    ft_free_2dem_arr((void ***)&push_swap->med);
}