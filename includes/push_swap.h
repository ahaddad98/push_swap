/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:10:12 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/31 14:07:36 by amine            ###   ########.fr       */
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
    int         *cast_a;
    int         checker;
    long long int         mediane;
}           t_push_swap;

void        swap_a(char **ab, t_push_swap *push_swap);
void        push_a(t_push_swap *push_swap);
void        push_b(t_push_swap *push_swap);
char		**ft_strdup_2d(char **str);
int			count_line(char **env);
void        rotate(char **a, t_push_swap *push_swap);
void        rot_rot(char **a, t_push_swap *push_swap);
int         ft_strcmp(const char *s1, const char *s2);
void        swap_b(char **tab, t_push_swap *push_swap);
void		ft_free_2dem_arr(void ***arr);
void		ft_free_arr(void **array);
void        push_b_2(t_push_swap *push_swap);
// void        convert_tab(t_push_swap *push_swapm, int len);

#endif