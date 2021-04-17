/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:53:45 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/17 15:19:09 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)s;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
