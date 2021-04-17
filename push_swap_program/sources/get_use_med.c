/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_use_med.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:29:59 by amine             #+#    #+#             */
/*   Updated: 2021/04/17 13:29:40 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_inst(t_push_swap *push_swap, int len_b, int max)
{
	while (push_swap->b && push_swap->b[0])
	{
		max = get_max(push_swap);
		{
			len_b = count_line(push_swap->b) / 2;
			while (push_swap->b && ft_atoi(push_swap->b[0]) != max)
			{
				if (len_b >= get_index1(push_swap, (max)))
				{
					rotate(push_swap->b, push_swap, "rb");
				}
				else if (len_b < get_index1(push_swap, (max)))
				{
					rot_rot(push_swap->b, push_swap, "rrb");
				}
			}
			if (ft_atoi(push_swap->b[0]) == max)
			{
				push_a(push_swap);
				max = get_max(push_swap);
			}
		}
	}
}

void	use_mediane(t_push_swap *push_swap, int len)
{
	int		len_b;
	int		max;

	len_b = 0;
	get_mediane(push_swap, len);
	push_swap->nbr_of_inst = 0;
	push_b_less_med(push_swap, len);
	while (push_swap->a && push_swap->a[0])
	{
		push_b(push_swap);
		push_swap->nbr_of_inst++;
	}
	len_b = 0;
	get_inst(push_swap, len_b, max);
}
