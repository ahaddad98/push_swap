/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:10:07 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/18 16:35:44 by ahaddad          ###   ########.fr       */
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
		j = i + 1;
		while (push_swap->a[j])
		{
			if (ft_atoi(push_swap->a[i]) > ft_atoi(push_swap->a[j]))
				return (1);
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
	if (push_swap->check_flags)
		i = 2;
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i], ' ');
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
}
