/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:36:48 by amine             #+#    #+#             */
/*   Updated: 2021/04/16 15:57:01 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    rotate(char **a, t_push_swap *push_swap, char *msg)
{
    char *p;
    int  i = 0;
    int j = 1;
    
    if (!a)
    {
        push_swap->checker = 1;
        return ;
    }
    p = ft_strdup(a[0]);
    while (a[j])
    {
        free(a[i]);
        a[i] = ft_strdup(a[j]);
        i++;
        j++;
    }
    free(a[i]);
    a[i] = ft_strdup(p);
    ft_free_arr((void **)&p);
    ft_putendl_fd(msg , 1);
}

void        rot_rot(char **a, t_push_swap *push_swap, char *msg)
{
    char *p;
    int i = 0;
    int j = 1;
    char **new_a;
    int len = count_line(a);
    if (!a)
    {
        push_swap->checker = 1;
        return ;
    }
    new_a = malloc(sizeof(char *) * (len + 1));
    new_a[0] = ft_strdup(a[len - 1]);
    while (i < len - 1)
    {
        new_a[j] = ft_strdup(a[i]);
        j++;
        i++;
    }
    new_a[j] = NULL;
    j = 0;
    while (new_a[j])
    {
        free(a[j]);
        a[j] = ft_strdup(new_a[j]);
        j++;
    }
    if (new_a)
        ft_free_2dem_arr((void ***)&new_a);
    ft_putendl_fd(msg , 1);
}
