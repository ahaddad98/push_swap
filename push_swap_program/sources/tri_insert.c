/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:42:25 by amine             #+#    #+#             */
/*   Updated: 2021/04/16 14:50:46 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void tri_insert(t_push_swap *push_swap, int len)
{
    int i;
    int j;
    char *tmp;
    char **tmp1;

    i = 0;
    tmp1 = ft_strdup_2d(push_swap->a);
    i = 0;
    tmp = NULL;
    while (tmp1[i])
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
    push_swap->med = NULL;
    if (len <= 5)
    {
        push_swap->med = malloc(sizeof(char *) * 2);
        i = len / 2;
        int k = 0;
        push_swap->med[k] = ft_strdup(tmp1[i]);
        k++;
        push_swap->med[k] = NULL;
    }
    else if (len > 5  && len <= 20)
    {
        push_swap->med = malloc(sizeof(char *) * 2);
        i = len / 2;
        int k = 0;
        push_swap->med[k] = ft_strdup(tmp1[i]);
        push_swap->med[k + 1] = NULL;
    }
    else if (len > 20 && len <= 100)
    {
        push_swap->med = malloc(sizeof(char *) * ((len / 7)));
        i = len / 7;
        int k = 0;
        while (i < len)
        {
            push_swap->med[k] = ft_strdup(tmp1[i]);
            k++;
            i = i + (len / 7);
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
    ft_free_2dem_arr((void ***)&tmp1);
}

void get_mediane(t_push_swap *push_swap, int len)
{
    tri_insert(push_swap, len);
}
