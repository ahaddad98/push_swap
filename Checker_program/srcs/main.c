/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/19 17:52:42 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_args(char **av, int ac, t_push_swap *push_swap)
{
	int		k;
	char	**tab;

	check_flg(push_swap, av, ac);
	while (av[push_swap->j])
	{
		k = 0;
		tab = ft_split(av[push_swap->j], ' ');
		if (!tab[k])
			return (free_ret(tab));
		while (tab && tab[k])
		{
			if (ft_atoi_loong(tab[k]) > 2147483647)
				return (free_ret(tab));
			else if (ft_atoi_loong(tab[k]) < -2147483648)
				return (free_ret(tab));
			else if (is_num(tab[k]) == 1)
				return (free_ret(tab));
			k++;
			push_swap->len_of_stack++;
		}
		ft_free_2dem_arr((void ***)&tab);
		push_swap->j++;
	}
	return (0);
}

void	check_if_ok(t_push_swap *push_swap)
{
	if (!check_if_sort(push_swap) && !count_line(push_swap->b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

void	get_algo_now(t_push_swap *push_swap)
{
	char	*line;

	if (check_if_duplic(push_swap))
		ft_putendl_fd("Error", 1);
	else
	{
		push_swap->b = NULL;
		while (get_next_line(0, &line))
		{
			get_instruc(push_swap, line);
			if (push_swap->check_instruc == 1)
			{
				ft_putendl_fd("Error", 1);
				break ;
			}
			if (push_swap->check_flags == 1)
				print_a_b(push_swap);
			ft_free_arr((void **)&line);
		}
		ft_free_arr((void **)&line);
		if (push_swap->check_instruc != 1)
			check_if_ok(push_swap);
	}
}

int	main(int ac, char **av)
{
	t_push_swap		push_swap;

	if (ac > 1 && !check_args(av, ac, &push_swap))
	{
		push_swap.checker = 0;
		get_a_from_arg(&push_swap, av);
		get_algo_now(&push_swap);
		if (push_swap.a)
			ft_free_2dem_arr((void ***)&push_swap.a);
	}
	else if (ac > 1)
		ft_putendl_fd("Error", 1);
	return (0);
}
