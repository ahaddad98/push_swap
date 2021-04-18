/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/18 12:49:56 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_if_sort(t_push_swap *push_swap)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (push_swap->a && push_swap->a[i])
	{
		j = i;
		while (push_swap->a[j])
		{
			if (push_swap->a[i] > push_swap->a[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	print_a_b(t_push_swap *push_swap)
{
	int		i;
	int		k;

	system("clear");
	k = 0;
	puts("----------------------HERE IS A-----------------------");
	while (push_swap->a && push_swap->a[k])
	{
		ft_putendl_fd(push_swap->a[k], 1);
		k++;
	}
	i = 0;
	puts("-----------------------HERE IS B=====================");
	while (push_swap->b && push_swap->b[i])
	{
		ft_putendl_fd(push_swap->b[i], 1);
		i++;
	}
	sleep(1);
}

void	get_instruc_com(t_push_swap *push_swap, char *line)
{
	if (!ft_strcmp(line, "ra"))
		rotate(push_swap->a, push_swap, NULL);
	if (!ft_strcmp(line, "rb"))
		rotate(push_swap->b, push_swap, NULL);
	if (!ft_strcmp(line, "rr"))
	{
		rotate(push_swap->a, push_swap, NULL);
		rotate(push_swap->b, push_swap, NULL);
	}
	if (!ft_strcmp(line, "rra"))
		rot_rot(push_swap->a, push_swap, NULL);
	if (!ft_strcmp(line, "rrb"))
		rot_rot(push_swap->b, push_swap, NULL);
	if (!ft_strcmp(line, "rrr"))
	{
		rot_rot(push_swap->a, push_swap, NULL);
		rot_rot(push_swap->b, push_swap, NULL);
	}
	if (count_line(push_swap->b) != 0)
		push_swap->checker = 1;
}

void	get_instruc(t_push_swap *push_swap, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap_a(push_swap->a, push_swap);
	if (!ft_strcmp(line, "sb"))
		swap_b(push_swap->b, push_swap);
	if (!ft_strcmp(line, "ss"))
	{
		swap_a(push_swap->b, push_swap);
		swap_b(push_swap->a, push_swap);
	}
	if (!ft_strcmp(line, "pa"))
		push_a(push_swap);
	if (!ft_strcmp(line, "pb"))
		push_b(push_swap);
	get_instruc_com(push_swap, line);
}

void	get_a_from_arg(t_push_swap *push_swap, char **av, int ac)
{
	int		k;
	int		i;
	int		j;
	char	**tab;

	j = 0;
	k = 0;
	i = 1;
	push_swap->a = malloc(sizeof(char *) * (push_swap->len_of_stack + 1));
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i] , ' ');
		while (tab[j])
		{
			push_swap->a[k] = ft_strdup(tab[j]);
			j++;
			k++;
		}
		ft_free_2dem_arr((void ***)&tab);
		i++;
	}
	push_swap->a[k] = NULL;
	push_swap->b = NULL;
	push_swap->checker = 0;
}

int	is_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **av, int ac, t_push_swap *push_swap)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	
	k = 0;
	i = 0;
	j = 1;
	push_swap->len_of_stack = 0;
	while (av[j])
	{
		k = 0;
		tab = ft_split(av[j], ' ');
		while (tab[k])
		{
			if (ft_atoi_loong(tab[k]) > 2147483647)
				return (1);
			else if (ft_atoi_loong(tab[k]) < -2147483648)
				return (1);
			else if (is_num(tab[k]) == 1)
				return (1);
			k++;
			push_swap->len_of_stack++;
		}
		ft_free_2dem_arr((void ***)&tab);
		j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap		push_swap;
	char			*line;
	int				ret_read;

	if (ac > 1 && !check_args(av, ac, &push_swap))
	{
		get_a_from_arg(&push_swap, av, ac);
		// ret_read = -1;
		while (get_next_line(0, &line))
		{
			get_instruc(&push_swap, line);
			print_a_b(&push_swap);
			ft_free_arr((void **)&line);
		}
		ft_free_arr((void **)&line);
		if ((check_if_sort(&push_swap) == 0) && !count_line(push_swap.b))
			puts("OK");
		else
			puts("KO");
		if (push_swap.a)
			ft_free_2dem_arr((void ***)&push_swap.a);
		if (push_swap.b)
			ft_free_2dem_arr((void ***)&push_swap.b);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}
