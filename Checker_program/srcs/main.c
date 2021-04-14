/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/14 14:01:57 by ahaddad          ###   ########.fr       */
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

char			**ft_strdup_2d(char **str)
{
	int			len;
	char		**ret;
	int			i;

	i = 0;
	len = count_line(str);
	ret = malloc(sizeof(char *) * (len + 2));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int     is_ok()
{
    ft_putstr_fd("OK\n", 1);
    return (0);
}

int     is_ko()
{
    ft_putstr_fd("KO\n", 1);
    return (0);
}

int     is_error()
{
    ft_putstr_fd("Error\n", 1);
    return (0);

}

int        check_if_sort(t_push_swap *push_swap)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (push_swap->a[i])
    {
        j  = i;
        while (push_swap->a[j])
        {
            if (push_swap->a[i] > push_swap->a[j])
            {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int         i = 1;
    int         k = 0;
    t_push_swap push_swap;
    char    *line;
    int        ret_read;
    char *str;
    push_swap.checker = 0;
    push_swap.a = NULL;
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
    char *tmp;
    ret_read= 1;
    while (1)
    {
        ret_read = get_next_line(0, &line);
        if (!ft_strcmp(line, "\n"))
            continue ;
        if (!ft_strcmp(line, "sa"))
            swap_a(push_swap.a, &push_swap);
        if (!ft_strcmp(line, "sb"))
            swap_b(push_swap.b, &push_swap);
        if (!ft_strcmp(line, "ss"))
        {
            swap_a(push_swap.b, &push_swap);
            swap_b(push_swap.a, &push_swap);
        }
        if (!ft_strcmp(line, "pa"))
            push_a(&push_swap);
        if (!ft_strcmp(line, "pb"))
            push_b(&push_swap);
        if (!ft_strcmp(line, "ra"))
            rotate(push_swap.a, &push_swap);
        if (!ft_strcmp(line, "rb"))
            rotate(push_swap.b, &push_swap);
        if (!ft_strcmp(line, "rr"))
        {
            rotate(push_swap.a, &push_swap);
            rotate(push_swap.b, &push_swap);
        }
        if (!ft_strcmp(line, "rra"))
            rot_rot(push_swap.a, &push_swap);
        if (!ft_strcmp(line, "rrb"))
            rot_rot(push_swap.b, &push_swap);
        if (!ft_strcmp(line, "rrr"))
        {
            rot_rot(push_swap.a, &push_swap);
            rot_rot(push_swap.b, &push_swap);
        }
        if (count_line(push_swap.b) != 0)
            push_swap.checker = 1;
        if (ft_strlen(line) == 0)
            break ;
        ft_free_arr((void **)&line);
    }
    ft_free_arr((void **)&line);
    if ((check_if_sort(&push_swap) == 0) && !count_line(push_swap.b))
        puts("OK");
    else
        puts("KO");
    k = 0;
    puts("--------------------------------------------------------------");
    while (push_swap.a && push_swap.a[k])
    {
        ft_putendl_fd(push_swap.a[k], 1);
        k++;
    }
    i = 0;
    puts("--------------------------------------------------------------");
    while (push_swap.b&&push_swap.b[i])
    {
        ft_putendl_fd(push_swap.b[i], 1);
        i++;
    }
    if (push_swap.a)
        ft_free_2dem_arr((void ***)&push_swap.a);
    if (push_swap.b)
        ft_free_2dem_arr((void ***)&push_swap.b);
    return (0);
}

//./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8