/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:12:50 by amine             #+#    #+#             */
/*   Updated: 2021/04/15 16:08:15 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void            check_is_empty1(t_push_swap *push_swap, char **new_a, char **new_b)
{
    int i;
    int j;
    new_a = malloc(sizeof(char *) * 2);
    new_a[0] = ft_strdup(push_swap->b[0]);
    new_a[1] = NULL;
    if ((count_line(push_swap->b) - 1) <= 0)
    {
        if (push_swap->b)
            ft_free_2dem_arr((void ***)&push_swap->b);
    }
    else
    {
        new_b = malloc(sizeof(char *) * (count_line(push_swap->b)));
        i = 0;
        j = 1;
        while (push_swap->b[j])
        {
            new_b[i] = ft_strdup(push_swap->b[j]);
            free(push_swap->b[j]);
            i++;
            j++;
        }
        free(push_swap->b[j]);
        new_b[i] = NULL;
        i = 0;
        while (new_b[i])
        {
            push_swap->b[i] = ft_strdup(new_b[i]);
            i++;
        }
        push_swap->b[i] = NULL;
        if (new_b)
            ft_free_2dem_arr((void ***)&new_b);
    }
    push_swap->a = ft_strdup_2d(new_a);
    if (new_a)
        ft_free_2dem_arr((void ***)&new_a);
}

void        get_new_b(t_push_swap *push_swap, char **new_b)
{
    int i;
    int j;

    i = 0;
    j = 1;
    new_b = malloc(sizeof(char *) * (count_line(push_swap->b)));
    while (push_swap->b[j])
    {
        new_b[i] = ft_strdup(push_swap->b[j]);
        free(push_swap->b[j]);
        i++;
        j++;
    }
    free(push_swap->b[j]);
    new_b[i] = NULL;
    i = 0;
    while (new_b[i])
    {
        push_swap->b[i] = ft_strdup(new_b[i]);
        i++;
    }
    push_swap->b[i] = NULL;
    if (new_b)
        ft_free_2dem_arr((void ***)&new_b);
}

void        push_is_not_empt(t_push_swap *push_swap, char **new_a, char **new_b)
{
    int i = 0;
    int j = 1;

    new_a = NULL;
    new_b = NULL;
    new_a = malloc(sizeof(char *) * (count_line(push_swap->a) + 2));
    new_a[0] = ft_strdup(push_swap->b[0]);
    while (push_swap->a[i])
    {
        new_a[j] = ft_strdup(push_swap->a[i]);
        i++;
        j++;
    }
    // free(push_swap->a);
    new_a[j] = NULL;
    if (push_swap->a)
        ft_free_2dem_arr((void ***)&push_swap->a);
    if ((count_line(push_swap->b) - 1) <= 0)
    {
        if (push_swap->b)
            ft_free_2dem_arr((void ***)&push_swap->b);
    }
    else
        get_new_b(push_swap, new_b);
    push_swap->a = ft_strdup_2d(new_a);
    if (new_a)
        ft_free_2dem_arr((void ***)&new_a);
    if (new_b)
        ft_free_2dem_arr((void ***)&new_b);
}

void            push_a(t_push_swap *push_swap)
{
    char **new_a;
    char **new_b;
    int len_a;

    if (push_swap->b == NULL)
    {
        push_swap->checker = 1;
        return ;
    }
    if (!push_swap->a)
        check_is_empty1(push_swap, new_a, new_b);
    else
        push_is_not_empt(push_swap, new_a, new_b);
}
