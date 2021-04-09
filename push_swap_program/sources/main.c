/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/09 18:04:20 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void  ft_free_arr(void **array)
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
        tmp1[i] = ft_atoi(push_swap->a[i]);
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
    push_swap->med = malloc(sizeof(int) * ((len / 2)) - 1);
    i = 2;
    int k = 0;
    while ( i  < len - 1)
    {
        push_swap->med[k] = tmp1[i];
        k++;
        i = i + 2;
    }
    i = 0;
    // puts("====================================================");
    // while (i < (len / 2))
    // {
    //     printf("|%d|\n", push_swap->med[i]);
    //     i++;
    // }
    // puts("====================================================");
}

void        get_mediane(t_push_swap *push_swap, int len)
{
    int i = 0;
    // convert_tab(push_swap);
    tri_insert(push_swap, len);
}

int check_under_pivot(char **ag,int pivot)
{
    int i;
    i = 0;
    while (ag[i])
    {
        if(ft_atoi(ag[i])< pivot)
            return (1);
        i++;
    }
    return (0);
}

int         get_index(t_push_swap *push_swap, int med)
{
    int i = 0;

    while (push_swap->a[i])
    {
        if (ft_atoi(push_swap->a[i]) <  med)
        {
            return (i);
        }
        i++;
    }
    return (-1);
}

void        use_mediane(t_push_swap *push_swap, int len)
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
        while (i < (len / 2))
        {
            k = 0;
            j = 0;
            while (push_swap->a && push_swap->a[0] && check_under_pivot(push_swap->a, push_swap->med[i]))
            {
                if (ft_atoi(push_swap->a[k]) <  push_swap->med[i])
                {
                    push_b(push_swap);
                    puts("pb");
                    push_swap->nbr_of_inst++;
                    j++;
                }
                len_a = count_line(push_swap->a) / 2;
                if (len_a >= get_index(push_swap, push_swap->med[i]))
                {
                    rotate(push_swap->a, push_swap);
                    puts("ra");
                    push_swap->nbr_of_inst++;
                }       
                if (len_a < get_index(push_swap, push_swap->med[i]))
                {
                    rot_rot(push_swap->a, push_swap);
                    puts("rra");
                    push_swap->nbr_of_inst++;
                }
                // else if (push_swap->a[1] && (ft_atoi(push_swap->a[1]) < push_swap->med[i]))
                // {
                //     puts("amine");
                //     // if (ft_atoi(push_swap->a[len- 1]) < push_swap->med[i])
                //     // {
                //         rotate(push_swap->a, push_swap);
                //         push_swap->nbr_of_inst++;
                //     // }
                // }
                // else /*if (ft_atoi(push_swap->a[k]) >= push_swap->med[i])*/
                // {
                //     rotate(push_swap->a, push_swap);
                //     puts("ra");
                //     push_swap->nbr_of_inst++;
                // }
            }
            if (j == 2)
            {
                if (ft_atoi(push_swap->b[0]) < ft_atoi(push_swap->b[1]))
                {
                    swap_b(push_swap->b, push_swap);
                    puts("sb");
                    push_swap->nbr_of_inst++;
                }
            }
            else if (j == 3)
            {
                // if ((push_swap->b[0] < push_swap->b[1]) && (push_swap->b[0] < push_swap->b[2]) && (push_swap->b[1] > push_swap->b[2]))
                // {
                //     rotate(push_swap->b, push_swap);
                //     puts("rb");
                // }
                // if ((push_swap->b[0] > push_swap->b[1]) && (push_swap->b[0] < push_swap->b[2]) && (push_swap->b[1] < push_swap->b[2]))
                // {
                //     rot_rot(push_swap->b, push_swap);
                //     puts("rrb");
                // }
                // if ((push_swap->b[0] < push_swap->b[1]) && (push_swap->b[0] > push_swap->b[2]) && (push_swap->b[1] > push_swap->b[2]))
                // {
                //     swap_b(push_swap->b, push_swap);
                //     puts("sb");
                // }
                // if ((push_swap->b[0] > push_swap->b[1]) && (push_swap->b[0] > push_swap->b[2]) && (push_swap->b[1] < push_swap->b[2]))
                // {
                //     rot_rot(push_swap->b, push_swap);
                //     puts("rrb");
                //     swap_b(push_swap->b, push_swap);
                //     puts("sa");
                    
                // }
                // if ((push_swap->b[0] < push_swap->b[1]) && (push_swap->b[0] < push_swap->b[2]) && (push_swap->b[1] < push_swap->b[2]))
                // {
                //     rot_rot(push_swap->b, push_swap);
                //     puts("rrb");
                //     rot_rot(push_swap->b, push_swap);
                //     puts("rrb");
                //     swap_b(push_swap->b, push_swap);
                //     puts("sa");
                // }
                puts("HERE IS 3");
            }
            else
            {
            }
            i++;
        }
    }
    ft_free_arr((void **)&push_swap->med);
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
    push_swap.nbr_of_med = -1;
    push_swap.nbr_of_med = len / 2;
    // printf("{{%d}}}\n", 10 / 3);
    use_mediane(&push_swap, len);
    // k = 0;
    // puts("-----------------HERE IS : A--------------------------");
    // while (push_swap.a && push_swap.a[k])
    // {
    //     ft_putendl_fd(push_swap.a[k], 1);
    //     k++;
    // }
    // i = 0;
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

//97 24 31 84 3 4 90 96 52 13 46 89 71 64 22 76 28 55 28 19 50 63 81 14 87 100 38 88 89 50 6 29 17 47 32 91 17 56 64 67 74 58 49 35 28 60 9 87 20 22 90 95 79 86 95 93 12 75 32 14 72 34 38 87 73 18 52 3 10 17 9 96 92 14 80 71 15 46 70 78 2 31 97 79 11 7 35 24 29 57 5 20 89 14 60 75 96 7 69 29