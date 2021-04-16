/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:27:58 by amine             #+#    #+#             */
/*   Updated: 2021/04/16 03:31:19 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void        alog_3_more(t_push_swap *push_swap)
{
    if ((ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1])) && (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[2])) && (ft_atoi(push_swap->a[1]) < ft_atoi(push_swap->a[2])))
    {
        rotate(push_swap->a, push_swap);
        puts("ra");
    }
    else if ((ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1])) && (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[2])) && (ft_atoi(push_swap->a[1]) > ft_atoi(push_swap->a[2])))
    {
        rot_rot(push_swap->a, push_swap);
        puts("rra");
        rot_rot(push_swap->a, push_swap);
        puts("rra");
        swap_a(push_swap->a, push_swap);
        puts("sa");
    }
}

void    algo_3_elem(t_push_swap *push_swap)
{
    if ((ft_atoi(push_swap->a[0]) < ft_atoi(push_swap->a[1])) && (ft_atoi(push_swap->a[0]) < ft_atoi(push_swap->a[2])) && (ft_atoi(push_swap->a[1]) > ft_atoi(push_swap->a[2])))
    {
        rot_rot(push_swap->a, push_swap);
        puts("rra");
        swap_a(push_swap->a, push_swap);
        puts("sa");
    }
    else if ((ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1])) && (ft_atoi(push_swap->a[0]) < ft_atoi(push_swap->a[2])) && (ft_atoi(push_swap->a[1]) < ft_atoi(push_swap->a[2])))
    {
        swap_a(push_swap->a, push_swap);
        puts("sa");
    }
    else if ((ft_atoi(push_swap->a[0]) < ft_atoi(push_swap->a[1])) && (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[2])) && (ft_atoi(push_swap->a[1]) > ft_atoi(push_swap->a[2])))
    {
        rot_rot(push_swap->a, push_swap);
        puts("rra");
    }
    else
        alog_3_more(push_swap);
}
