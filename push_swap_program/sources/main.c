/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/12 15:11:44 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char **ft_strdup_2d(char **str)
{
    int len;
    char **ret;
    int i;

    i = 0;
    len = count_line(str);
    ret = malloc(sizeof(char *) * (len + 1));
    i = 0;
    while (str[i])
    {
        ret[i] = ft_strdup(str[i]);
        i++;
    }
    ret[i] = NULL;
    return (ret);
}

void ft_free_arr(void **array)
{
    if (*array)
        free(*array);
    *array = NULL;
}

void ft_free_2dem_arr(void ***arr)
{
    int i;

    i = 0;
    while ((*arr)[i])
    {
        free((*arr)[i]);
        (*arr)[i] = NULL;
        i++;
    }
    free(*arr);
    *arr = NULL;
}

int count_line(char **env)
{
    int i;

    i = 0;
    if (!env)
        return (0);
    while (env[i])
        i++;
    return (i);
}

void tri_insert(t_push_swap *push_swap, int len)
{
    int i;
    int j;
    char *tmp;
    char **tmp1;

    i = 0;
    tmp1 = ft_strdup_2d(push_swap->a);
    i = 0;
    while (i < len)
    {
        j = i;
        tmp = NULL;
        while (j < len)
        {
            if (ft_atoi(tmp1[i]) > ft_atoi(tmp1[j]))
            {
                tmp = tmp1[j];
                tmp1[j] = tmp1[i];
                tmp1[i] = tmp;
            }
            j++;
        }
        i++;
    }
    push_swap->mediane = 9223372036854775807;
    if (len <= 10)
    {
        push_swap->med = malloc(sizeof(char *) * 2);
        i = len / 2;
        int k = 0;
        push_swap->med[k] = ft_strdup(tmp1[i]);
        k++;
        push_swap->med[k] = NULL;
    }
    else if (len <= 100)
    {
        push_swap->med = malloc(sizeof(char *) * ((len / 5)));
        i = len / 5;
        int k = 0;
        while (i < len)
        {
            push_swap->med[k] = ft_strdup(tmp1[i]);
            k++;
            i = i + (len / 5);
        }
        push_swap->med[k] = NULL;
    }
    else if (len > 100)
    {
        push_swap->med = malloc(sizeof(char *) * ((len / 12)));
        i = len / 12;
        int k = 0;
        while (i < len)
        {
            push_swap->med[k] = ft_strdup(tmp1[i]);
            k++;
            i = i + (len / 12);
        }
        push_swap->med[k] = NULL;
    }
}

void get_mediane(t_push_swap *push_swap, int len)
{
    tri_insert(push_swap, len);
}

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
void    algo_3_elem(t_push_swap *push_swap);
void use_mediane(t_push_swap *push_swap, int len)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len_b = 0;
    int len_a = 0;
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
    i = 0;
    if (len <= 12)
    {
        while (push_swap->a && push_swap->a[0] && (count_line(push_swap->a) > 3))
        {
            push_b(push_swap);
            puts("pb");
            push_swap->nbr_of_inst++;
        }
        i = count_line(push_swap->med) - 1;
        j = 0;
        k = 0;
        len_b = 0;
        if (count_line(push_swap->a) == 3)
        {
            algo_3_elem(push_swap);
        }
        if (count_line(push_swap->b) == 0)
        {
            if (ft_atoi(push_swap->b[0]) <  ft_atoi(push_swap->b[1]))
            {
                swap_b(push_swap->b, push_swap);
                puts("sa");
            }
            while (push_swap->b && push_swap->b[0])
            {
                push_a(push_swap);
                puts("pa");
                push_swap->nbr_of_inst++;
            }
        }
    }
    else if (len > 12)
    {
        while (push_swap->a && push_swap->a[0])
        {
            push_b(push_swap);
            puts("pb");
            push_swap->nbr_of_inst++;
        }
        i = count_line(push_swap->med) - 1;
        j = 0;
        k = 0;
        len_b = 0;
        while (push_swap->b && push_swap->b[0])
        {
            int max = get_max(push_swap);
            {
                len_b = count_line(push_swap->b) / 2;
                while (push_swap->b && ft_atoi(push_swap->b[0]) != max)
                {
                    if (len_b >= get_index1(push_swap, (max)))
                    {
                        rotate(push_swap->b, push_swap);
                        puts("rb");
                        push_swap->nbr_of_inst++;
                    }
                    else if (len_b < get_index1(push_swap, (max)))
                    {
                        rot_rot(push_swap->b, push_swap);
                        puts("rrb");
                        push_swap->nbr_of_inst++;
                    }
                }
                if (ft_atoi(push_swap->b[0]) == max)
                {
                    push_a(push_swap);
                    puts("pa");
                    push_swap->nbr_of_inst++;
                    max = get_max(push_swap);
                }
            }
        }
    }
    ft_free_arr((void **)&push_swap->med);
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
    else if ((ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1])) && (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[2])) && (ft_atoi(push_swap->a[1]) < ft_atoi(push_swap->a[2])))
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