/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:10:12 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/29 01:15:23 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_push_swap
{
    char        **a;
    char        **b;
    int         checker;
}   t_push_swap;

void        swap(char **ab, t_push_swap *push_swap);
char        **push_a(t_push_swap *push_swap);
char        **push_b(t_push_swap *push_swap);
char		**ft_strdup_2d(char **str);
int			count_line(char **env);
void        rotate(char **a, t_push_swap *push_swap);
void        rot_rot(char **a, t_push_swap *push_swap);

#endif