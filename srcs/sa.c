/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:22:41 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/26 16:46:57 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char        *sa(char *tab)
{
    char        *new;
    int         tmp;

    if (!(new = ft_strdup(tab)))
        return (NULL);
    tmp = new[0];
    new[0] = new[1];
    new[1] = tmp;
    return (new);
}