/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:37:41 by amine             #+#    #+#             */
/*   Updated: 2021/04/17 14:54:28 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**ft_strdup_2d(char **str)
{
	int		len;
	char	**ret;
	int		i;

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

void	ft_free_arr(void **array)
{
	if (*array)
		free(*array);
	*array = NULL;
}

void	ft_free_2dem_arr(void ***arr)
{
	int		i;

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

int	count_line(char **env)
{
	int		i;

	i = 0;
	if (!env)
		return (0);
	while (env[i])
		i++;
	return (i);
}
