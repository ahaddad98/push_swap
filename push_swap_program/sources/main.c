/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/13 01:31:09 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int ac, char **av)
{
    t_push_swap push_swap;
    int i = 1;
    int k = 0;
    char *line;
    int ret_read;
    push_swap.checker = 0;
    push_swap.a = malloc(sizeof(char *) * ac);
    while (i < ac)
    {
        push_swap.a[k] = ft_strdup(av[i]);
        i++;
        k++;
    }
    push_swap.a[k] = NULL;
    push_swap.b = NULL;
    push_swap.checker = 0;
    int len = 0;
    len = count_line(push_swap.a);
    if (len == 2)
    {
        if (ft_atoi(push_swap.a[0]) > ft_atoi(push_swap.a[1]))
        {
            swap_a(push_swap.a, &push_swap);
            puts("sa");
        }
    }
    else if (len == 3)
        algo_3_elem(&push_swap);
    else
        use_mediane(&push_swap, len);
    k = 0;
    // puts("-----------------HERE IS : A--------------------------");
    // while (push_swap.a && push_swap.a[k])
    // {
    //     ft_putendl_fd(push_swap.a[k], 1);
    //     k++;
    // }
    i = 0;
    // puts("-----------------HERE IS : B--------------------------");
    // while (push_swap.b && push_swap.b[i])
    // {
    //     ft_putendl_fd(push_swap.b[i], 1);
    //     i++;
    // }
    // printf("{|%d|}", push_swap.nbr_of_inst);
    if (k)
        ft_free_2dem_arr((void ***)&push_swap.a);
    if (i)
        ft_free_2dem_arr((void ***)&push_swap.b);
    return (0);
}
//python3 pyviz.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`