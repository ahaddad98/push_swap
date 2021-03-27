/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/27 17:51:26 by ahaddad          ###   ########.fr       */
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

 void         convert_tab(char **tab, int **a)
{
    int len;
    len = count_line(tab);
    *a = malloc(sizeof(int) * len);
    int i = 1;
    int k = 0;
    while (tab[i])
    {
        (*a)[k] = ft_atoi(tab[i]);
        k++;
        i++;
    }
}



int main(int ac, char **av)
{
    char        **tab;
    int         i = 0;

    int *a;
    int *b;
    a = NULL;
    b = NULL;
    if (ac == 1)
        ft_putstr_fd("one element\n", 1);
    else if (ac == 0)
        ft_putstr_fd("no element\n", 1);
    if (av[0])
        ft_putstr_fd("element1235\n", 1);
    tab = malloc(sizeof(char *) * ac);
    while (i < ac)
    {
        tab[i] = ft_strdup(av[i]);
        i++;
    }
    tab[i] = NULL;
    convert_tab(tab, &a);
    swap(a);
    i = 0;
    while (i < ac - 1)
    {
        printf("{%d}\n",a[i]);
        i++;
    }
    return (0);
}