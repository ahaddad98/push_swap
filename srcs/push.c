/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:12:50 by amine             #+#    #+#             */
/*   Updated: 2021/03/28 14:36:25 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char        **push_a(t_push_swap *push_swap)
{
    char **new_a;
    char **new_b;
    int len_a;
    int i = 0;
    int j = 1;
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
        new_b = malloc(sizeof(char *) * (count_line(push_swap->b) - 1));
        i = 0;
        j = 1;
        while (push_swap->b[j])
        {
            new_b[i] = ft_strdup(push_swap->b[j]);
            i++;
            j++;
        }
        new_b[i] = NULL;
        push_swap->b = ft_strdup_2d(new_b);
    }
    return (new_a);
}

char        **push_b(t_push_swap *push_swap)
{
    char **new_a;
    char **new_b;
    int len_a;
    int i = 0;
    int j = 1;
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
        push_swap->a = NULL;
    else
    {
        new_a = malloc(sizeof(char *) * (count_line(push_swap->a) - 1));
        i = 0;
        j = 1;
        while (push_swap->a[j])
        {
            new_a[i] = ft_strdup(push_swap->a[j]);
            i++;
            j++;
        }
        new_a[i] = NULL;
        push_swap->a = ft_strdup_2d(new_a);
    }
    return (new_b);
}