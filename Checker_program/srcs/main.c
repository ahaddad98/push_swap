/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/07 11:45:36 by ahaddad          ###   ########.fr       */
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

void print(t_push_swap *push_swap)
{
    int k = 0;
    int i = 0;
    printf("|            a            |            b            |\n");
    printf("|---------------------------------------------------|\n");
    // puts("laloli");
    // ft_putnbr_fd(count_line(push_swap->a), 1);
    // puts("--------------------------");
    // ft_putnbr_fd(count_line(push_swap->b), 1);
    while (push_swap->a[k] || count_line(push_swap->b) > 0)
    {
        if (push_swap->a[k] && (push_swap->b && push_swap->b[i]))
            printf("|            %s            |            %s            |\n", push_swap->a[k], push_swap->b[i]);
        else if (!push_swap->a[k] && (push_swap->b && push_swap->b[i]))
            printf("|                         |            %s            |\n", push_swap->b[i]);
        else if (push_swap->a[k] && !push_swap->b)
            printf("|            %s            |                         |\n", push_swap->a[k]);
        if (push_swap->a[k])
            k++;
        if (push_swap->b && push_swap->b[i])
            i++;
    }
}

int main(int ac, char **av)
{
    int         i = 1;
    int         k = 0;
    t_push_swap push_swap;
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
    while (1)
    {
        line =  malloc(sizeof(char) * 1000);
        ft_bzero(line, sizeof(char) * 1000);
        ret_read = read(0, line, 1000);
        if (!ft_strcmp(line, "\n"))
            continue ;
        if (!ft_strcmp(line, "sa\n"))
            swap_a(push_swap.a, &push_swap);
        if (!ft_strcmp(line, "sb\n"))
            swap_b(push_swap.b, &push_swap);
        if (!ft_strcmp(line, "ss\n"))
        {
            swap_a(push_swap.b, &push_swap);
            swap_b(push_swap.a, &push_swap);
        }
        if (!ft_strcmp(line, "pa\n"))
            push_a(&push_swap);
        if (!ft_strcmp(line, "pb\n"))
            push_b(&push_swap);
        if (!ft_strcmp(line, "ra\n"))
            rotate(push_swap.a, &push_swap);
        if (!ft_strcmp(line, "rb\n"))
            rotate(push_swap.b, &push_swap);
        if (!ft_strcmp(line, "rr\n"))
        {
            rotate(push_swap.a, &push_swap);
            rotate(push_swap.b, &push_swap);
        }
        if (!ft_strcmp(line, "rra\n"))
            rot_rot(push_swap.a, &push_swap);
        if (!ft_strcmp(line, "rrb\n"))
            rot_rot(push_swap.b, &push_swap);
        if (!ft_strcmp(line, "rrr\n"))
        {
            rot_rot(push_swap.a, &push_swap);
            rot_rot(push_swap.b, &push_swap);
        }
        if (count_line(push_swap.b) != 0)
            push_swap.checker = 1;
        if (ft_strlen(line) == 0)
            break ;
    }
    if (!push_swap.b)
        ft_putendl_fd("KO", 1);
    else if (push_swap.checker == 1)
        ft_putendl_fd("KO", 1);
    else
        ft_putendl_fd("OK", 1);
    k = 0;
    puts("--------------------------------------------------------------");
    while (push_swap.a && push_swap.a[k])
    {
        ft_putendl_fd(push_swap.a[k], 1);
        k++;
    }
    k = 0;
    puts("--------------------------------------------------------------");
    while (push_swap.b&&push_swap.b[k])
    {
        ft_putendl_fd(push_swap.b[k], 1);
        k++;
    }
    return (0);
}