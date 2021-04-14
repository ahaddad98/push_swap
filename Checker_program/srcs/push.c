/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:12:50 by amine             #+#    #+#             */
/*   Updated: 2021/04/14 14:51:20 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void            push_a(t_push_swap *push_swap)
{
    char **new_a;
    char **new_b;
    int len_a;
    int i = 0;
    int j = 1;

    if (push_swap->b == NULL)
    {
        push_swap->checker = 1;
        return ;
    }
    if (!push_swap->a)
    {
        new_a = malloc(sizeof(char *) * 2);
        new_a[0] = ft_strdup(push_swap->b[0]);
        new_a[1] = NULL;
        if ((count_line(push_swap->b) - 1) <= 0)
            push_swap->b = NULL;
        else
        {
            new_b = malloc(sizeof(char *) * (count_line(push_swap->b)));
            i = 0;
            j = 1;
            while (push_swap->b[j])
            {
                new_b[i] = ft_strdup(push_swap->b[j]);
                i++;
                j++;
            }
            new_b[i] = NULL;
            i = 0;
            while (new_b[i])
            {
                push_swap->b[i] = ft_strdup(new_b[i]);
                i++;
            }
            push_swap->b[i] = NULL;
        }
    }
    else
    {
        i = 0;
        j = 1;
        new_a = NULL;
        new_a = malloc(sizeof(char *) * (count_line(push_swap->a) + 2));
        new_a[0] = ft_strdup(push_swap->b[0]);
        while (push_swap->a[i])
        {
            new_a[j] = ft_strdup(push_swap->a[i]);
            i++;
            j++;
        }
        new_a[j] = NULL;
        if ((count_line(push_swap->b) - 1) <= 0)
            push_swap->b = NULL;
        else
        {
            new_b = malloc(sizeof(char *) * (count_line(push_swap->b)));
            i = 0;
            j = 1;
            while (push_swap->b[j])
            {
                new_b[i] = ft_strdup(push_swap->b[j]);
                i++;
                j++;
            }
            new_b[i] = NULL;
            i = 0;
            while (new_b[i])
            {
                push_swap->b[i] = ft_strdup(new_b[i]);
                i++;
            }
            push_swap->b[i] = NULL;
        }
    }
    // ft_free_2dem_arr((void ***)&push_swap->a);
    push_swap->a = new_a;
}

void            push_b(t_push_swap *push_swap)
{
    char **new_a;
    char **new_b;
    int len_a;
    int i = 0;
    int j = 1;
    char *tmp;
    // new_a = NULL;
    // new_b = NULL;
    if (push_swap->a == NULL)
    {
        push_swap->checker = 1;
        return ;
    }
    if (!push_swap->b)
    {
        new_b = malloc(sizeof(char *) * 2);
        new_b[0] = ft_strdup(push_swap->a[0]);
        new_b[1] = NULL;
        if ((count_line(push_swap->a) - 1) <= 0)
        {
            if (push_swap->a)
                ft_free_2dem_arr((void ***)&push_swap->a);
            // push_swap->a = NULL;
        }
        else
        {
            new_a = malloc(sizeof(char *) * (count_line(push_swap->a) + 1));
            i = 0;
            j = 1;
            while (push_swap->a[j])
            {
                new_a[i] = ft_strdup(push_swap->a[j]);
                free(push_swap->a[j]);
                i++;
                j++;
            }
            new_a[i] = NULL;
            i = 0;
            free(push_swap->a[0]);

            while (new_a[i])
            {
                push_swap->a[i] = ft_strdup(new_a[i]);
                i++;
            }
            push_swap->a[i] = NULL;
        }
        push_swap->b = ft_strdup_2d(new_b);
        if (new_a)
            ft_free_2dem_arr((void ***)&new_a);
        if (new_b)
            ft_free_2dem_arr((void ***)&new_b);
    }
    else
    {
        i = 0;
        j = 1;
        new_b = NULL;
        new_b = malloc(sizeof(char *) * (count_line(push_swap->b) + 2));
        new_b[0] = ft_strdup(push_swap->a[0]);
        while (push_swap->b[i])
        {
            new_b[j] = ft_strdup(push_swap->b[i]);
            i++;
            j++;
        }
        new_b[j] = NULL;
        if ((count_line(push_swap->a) - 1) <= 0)
        {
            if (push_swap->a)
                ft_free_2dem_arr((void ***)&push_swap->a);
            // push_swap->a = NULL;
        }
        else
        {
            new_a = malloc(sizeof(char *) * (count_line(push_swap->a) + 1));
            i = 0;
            j = 1;
            while (push_swap->a[j])
            {
                new_a[i] = ft_strdup(push_swap->a[j]);
                i++;
                j++;
            }
            new_a[i] = NULL;
            i = 0;
            while (new_a[i])
            {
                free(push_swap->a[i]);
                push_swap->a[i] = ft_strdup(new_a[i]);
                i++;
            }
            push_swap->a[i] = NULL;
        }
        push_swap->b = ft_strdup_2d(new_b);
        // ft_free_2dem_arr((void ***)&new_b);
        if (new_a)
            ft_free_2dem_arr((void ***)&new_a);
        if (new_b)
            ft_free_2dem_arr((void ***)&new_b);
    }
}
