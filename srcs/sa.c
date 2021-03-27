/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:22:41 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/27 17:25:28 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if ((!s1 || !s2))
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0')))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

// void        sa(t_push_swap *push_swap)
void        swap(int *tab)
{
    int a;

    a  = tab[0];
    tab[0] = tab[1];
    tab[1] = a;
}
