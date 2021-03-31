/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/31 14:21:09 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				count_line(char **env)
{
	int i;

	i = 0;
	if (!env)
		return (0);
	while (env[i])
		i++;
	return (i);
}


void         convert_tab(t_push_swap *push_swap)
{
    int len;
    len = count_line(push_swap->a);
    push_swap->cast_a = malloc(sizeof(int) * len);
    int i = 0;
    int k = 0;
    while (push_swap->a[i])
    {
        push_swap->cast_a[k] = ft_atoi(push_swap->a[i]);
        k++;
        i++;
    }
}

void        tri_insert(t_push_swap *push_swap, int len)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < len)
    {
        j = i;
        while (j < len)
        {
            if (push_swap->cast_a[i] > push_swap->cast_a[j])
            {
                tmp = push_swap->cast_a[j];
                push_swap->cast_a[j] = push_swap->cast_a[i];
                push_swap->cast_a[i] = tmp;
            }
            j++;
        }
        i++;
    }
}

void        get_mediane(t_push_swap *push_swap, int len)
{
    convert_tab(push_swap);
    int i = 0;
    tri_insert(push_swap, len);
    push_swap->mediane = 9223372036854775807;
    if ((len % 2) != 0)
        push_swap->mediane = push_swap->cast_a[(len)/2];
    else
        push_swap->mediane = push_swap->cast_a[(len-1)/2];
    printf("{%lld}\n", push_swap->mediane);
    while (i < len)
    {
        printf("%d\n", push_swap->cast_a[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    t_push_swap push_swap;
    int         i = 1;
    int         k = 0;
    char    *line;
    int        ret_read;
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
    if (len >= 2)
    {
        get_mediane(&push_swap, len);
    }
    return (0);
}