/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/07 15:35:54 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_free_arr(void **array)
{
	if (*array)
		free(*array);
	*array = NULL;
}

void		ft_free_2dem_arr(void ***arr)
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
    // puts("****************************************************");
    while (push_swap->a[i])
    {
        // printf("{%d}\n",ft_atoi(push_swap->a[i]));
        push_swap->cast_a[k] = ft_atoi(push_swap->a[i]);
        k++;
        i++;
    }
    // puts("****************************************************");
}

void        tri_insert(t_push_swap *push_swap, int len)
{
    int i;
    int j;
    int tmp;
    int *tmp1;

    i = 0;
    tmp1 = malloc(sizeof(int ) * len);
    while (i < len)
    {
        tmp1[i] = push_swap->cast_a[i];
        i++;
    }
    i = 0;
    while (i < len)
    {
        j = i;
        while (j < len)
        {
            if (tmp1[i] > tmp1[j])
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
    if ((len % 2) != 0)
        push_swap->mediane = tmp1[(len)/2];
    else
        push_swap->mediane = tmp1[(len-1)/2];
}

void        get_mediane(t_push_swap *push_swap, int len)
{
    int i = 0;
    convert_tab(push_swap);
    tri_insert(push_swap, len);
    // push_swap->mediane = 9223372036854775807;
    // if ((len % 2) != 0)
    //     push_swap->mediane = push_swap->cast_a[(len)/2];
    // else
    //     push_swap->mediane = push_swap->cast_a[(len-1)/2];
    // printf("{%lld}\n", push_swap->mediane);
    // while (i < len)
    // {
    //     printf("%d\n", push_swap->cast_a[i]);
    //     i++;
    // }
}

void        use_mediane(t_push_swap *push_swap, int len)
{
    int i = 0;
    int j = 0;
    int k = 0;

    get_mediane(push_swap, len);
    if (len >= 2)
    {
        while (i < len)
        {
            // if (i != len - 1)
            //     convert_tab(push_swap);
            if (push_swap->cast_a[i] >= push_swap->mediane)
            {
                // printf("|%d|\n", push_swap->cast_a[i]);
                push_b(push_swap);
                puts("pb");
                j++;
            }
            // else
            //     break ;
            // if (i != len - 1)
            //     free(push_swap->cast_a);
            else if (i != len - 1)
            {
                puts("ra");
                rotate(push_swap->a, push_swap);
            }
            i++;
        }
    }
    len = count_line(push_swap->a);
    if (len > 3)
    {
        use_mediane(push_swap, len);
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
    use_mediane(&push_swap, len);
        k = 0;
    puts("-----------------HERE IS : A--------------------------");
    if (count_line(push_swap.a) == 3)
        puts("HERE WE GO!");
    while (push_swap.a && push_swap.a[k])
    {
        ft_putendl_fd(push_swap.a[k], 1);
        k++;
    }
    k = 0;
    puts("-----------------HERE iS : B--------------------------");
    while (push_swap.b&&push_swap.b[k])
    {
        ft_putendl_fd(push_swap.b[k], 1);
        k++;
    }
    ft_free_2dem_arr((void ***)&push_swap.a);
    ft_free_2dem_arr((void ***)&push_swap.b);
    return (0);
}