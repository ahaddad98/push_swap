/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/16 16:17:07 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    which_algo(t_push_swap *push_swap, int len)
{
    if (len == 2)
    {
        if (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1]))
        {
            swap_a(push_swap->a, push_swap);
            puts("sa");
        }
    }
    else if (len == 3)
        algo_3_elem(push_swap);
    else if (len <= 5)
        algo_less_5_elem(push_swap);
    else
        use_mediane(push_swap, len);
}

int     main(int ac, char **av)
{
    t_push_swap     push_swap;
    int             i = 1;
    int             k = 0;
    int             ret_read;
    int             len = 0;

    push_swap.a = malloc(sizeof(char *) * (ac + 1));
    while (av[i])
    {
        push_swap.a[k] = ft_strdup(av[i]);
        i++;
        k++;
    }
    push_swap.a[k] = NULL;
    push_swap.b = NULL;
    push_swap.checker = 0;
    len = count_line(push_swap.a);
    which_algo(&push_swap, len);
    if (push_swap.a)
        ft_free_2dem_arr((void ***)&push_swap.a);
    if (push_swap.b)
        ft_free_2dem_arr((void ***)&push_swap.b);
    return (0);
}
