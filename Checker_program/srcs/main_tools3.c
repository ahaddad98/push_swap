/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:27:38 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/19 17:30:01 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_num(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 1)
		if (ft_isdigit(str[i]) == 0)
			return (1);
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] == '-')
			{
				i++;
				continue ;
			}
		}
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	check_flg(t_push_swap *push_swap, char **av, int ac)
{
	push_swap->j = 1;
	push_swap->check_flags = 0;
	push_swap->len_of_stack = 0;
	if (ac > 2)
	{
		if (!ft_strcmp(av[1], "-v"))
		{
			push_swap->j = 2;
			push_swap->check_flags = 1;
		}
	}
}

int	free_ret(char **tab)
{
	ft_free_2dem_arr((void ***)&tab);
	return (1);
}
