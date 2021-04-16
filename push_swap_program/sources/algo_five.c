/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:07:47 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/16 16:08:13 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    algo_less_5_elem(t_push_swap *push_swap)
{
    int index = 0;
    int len = count_line(push_swap->a);
    int i = 0;

    int len_a;
    int len_b;
    get_mediane(push_swap, len);
    push_swap->nbr_of_inst = 0;
    push_b_less_med(push_swap, len);
    if (len == 5)
    {
        while (push_swap->a && push_swap->a[0] && (count_line(push_swap->a) > 3))
        {
            push_b(push_swap);
            puts("pb");
            push_swap->nbr_of_inst++;
        }
    }
    i = count_line(push_swap->med) - 1;
    len_b = 0;
    if (count_line(push_swap->a) == 3)
        algo_3_elem(push_swap);
    if (count_line(push_swap->a) == 2)
    {
        if (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1]))
        {
            swap_a(push_swap->a, push_swap);
            puts("sa");
        }
    }
    if (count_line(push_swap->b) == 2)
    {
        if (ft_atoi(push_swap->b[0]) <  ft_atoi(push_swap->b[1]))
        {
            swap_b(push_swap->b, push_swap);
            puts("sb");
        }
        while (push_swap->b && push_swap->b[0])
        {
            push_a(push_swap);
            puts("pa");
            push_swap->nbr_of_inst++;
        }
    }
}