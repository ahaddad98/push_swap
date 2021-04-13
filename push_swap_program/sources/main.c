/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/13 02:27:13 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    algo_less_5_elem(t_push_swap *push_swap)
{
    int index = 0;
    int len = count_line(push_swap->a);
    int i = 0;
    int j = 0;
    int k = 0;
    int len_a;
    int len_b;
    get_mediane(push_swap, len);
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
                    puts("pb");
                    push_swap->nbr_of_inst++;
                    j++;
                }
                else if (len_a >= get_index(push_swap, ft_atoi(push_swap->med[i])))
                {
                    rotate(push_swap->a, push_swap);
                    puts("ra");
                    push_swap->nbr_of_inst++;
                }
                else if (len_a < get_index(push_swap, ft_atoi(push_swap->med[i])))
                {
                    rot_rot(push_swap->a, push_swap);
                    puts("rra");
                    push_swap->nbr_of_inst++;
                }
            }
            i++;
        }
    }
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
    j = 0;
    k = 0;
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
    // else
    // {
    //     index = 1;
    //     while (push_swap->b && push_swap->b[0])
    //     {
    //         int max = get_max(push_swap);
    //         {
    //             len_b = count_line(push_swap->b) / 2;
    //             while (push_swap->b && ft_atoi(push_swap->b[0]) != max)
    //             {
    //                 if (len_b >= get_index1(push_swap, (max)))
    //                 {
    //                     rotate(push_swap->b, push_swap);
    //                     puts("rb");
    //                     push_swap->nbr_of_inst++;
    //                 }
    //                 else if (len_b < get_index1(push_swap, (max)))
    //                 {
    //                     rot_rot(push_swap->b, push_swap);
    //                     puts("rrb");
    //                     push_swap->nbr_of_inst++;
    //                 }
    //             }
    //             if (ft_atoi(push_swap->b[0]) == max)
    //             {
    //                 push_a(push_swap);
    //                 puts("pa");
    //                 push_swap->nbr_of_inst++;
    //                 max = get_max(push_swap);
    //             }
    //         }
    //     }
    // }
}

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
    else if (len <= 5)
        algo_less_5_elem(&push_swap);
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