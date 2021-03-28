/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/29 01:26:46 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	ret = malloc(sizeof(char *) * (len + 1));
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

int main(int ac, char **av)
{
    int         i = 1;
    int         k = 0;
    t_push_swap push_swap;

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
    swap(push_swap.a, &push_swap);
    rot_rot(push_swap.a, &push_swap);
    push_swap.b = push_b(&push_swap);
    // rotate(push_swap.a);
    // push_swap.a = push_a(&push_swap);
    // if (push_swap.checker == 1)
    // {
    //     return (is_ko());
    // }
    // else
    // {
    //     return (is_ok());
    // }
    k = 0;
    //push_swap.b = malloc(sizeof(char *) * 1);
    // push_swap.b[0] = ft_strdup("22200");
    // rot_rot(push_swap.a);
    // swap(push_swap.a);
    if (push_swap.a == NULL)
    {
        puts("{raha NULL sir 3allah}");
    }
    puts("----------------------------this is a-----------------------------------");
    while (push_swap.a[k])
    {
        printf("%s\n", push_swap.a[k]);
        k++;
    }
    puts("----------------------------this is b-----------------------------------");
    k = 0;
    while (push_swap.b[k])
    {
        printf("%s\n", push_swap.b[k]);
        k++;
    }
    puts("----------------------------this is b after pp-----------------------------------");
    k = 0;
    while (push_swap.a[k])
    {
        printf("%s\n", push_swap.a[k]);
        k++;
    }
    return (0);
}