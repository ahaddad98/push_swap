/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/26 18:05:42 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    char        *tab;
    int         i;

    if (ac == 1)
        ft_putstr_fd("one element\n", 1);
    else if (ac == 0)
        ft_putstr_fd("no element\n", 1);
    else
    {
        tab = malloc(sizeof(char) * (ac + 1));
        i = 0;
        while (i < ac)
        {
            tab[i] = av[i][0];
            i++;
        }
    }
    i = 0;
    while (tab[i])
    {
        ft_putstr_fd(&tab[i], 1);
        i++;
    }
    return (0);
}