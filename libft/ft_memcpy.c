/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:08:02 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/17 15:17:30 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;

	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	if (p1 == p2)
		return (p1);
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (p1);
}
