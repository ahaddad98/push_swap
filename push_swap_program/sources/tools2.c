/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:09:01 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/16 16:09:20 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    push_b_less_med(t_push_swap *push_swap , int len)
{
    int len_a = 0;
    int i = 0;
    int k = 0;
    int j  = 0;
    
    push_swap->nbr_of_inst = 0;
    if (len >= 2)
    {
        while (push_swap->med[i])
        {
            k = 0;
            j = 0;
            while (push_swap->a && push_swap->a[0] && check_under_pivot(push_swap->a, ft_atoi(push_swap->med[i])))
            {
                len_a = count_line(push_swap->a) / 2;
                if (ft_atoi(push_swap->a[k]) < ft_atoi(push_swap->med[i]))
                {
                    push_b(push_swap);
                    push_swap->nbr_of_inst++;
                    j++;
                }
                else if (len_a >= get_index(push_swap, ft_atoi(push_swap->med[i])))
                {
                    rotate(push_swap->a, push_swap, "ra");
                    push_swap->nbr_of_inst++;
                }
                else if (len_a < get_index(push_swap, ft_atoi(push_swap->med[i])))
                {
                    rot_rot(push_swap->a, push_swap, "rra");
                    push_swap->nbr_of_inst++;
                }
            }
            i++;
        }
    }
    ft_free_2dem_arr((void ***)&push_swap->med);
}