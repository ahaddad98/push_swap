/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:49:29 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/19 12:45:49 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	s;
	char			*p;

	s = count * size;
	p = malloc(s);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, s);
	return (p);
}
