/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:55:17 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/17 16:55:18 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ctm/ctm_libs/ctm_libs.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h> 
# include <stdio.h>

typedef struct s_dbl_list
{
    int     data;
    int     cost;
    int     movecost;
    struct s_dbl_list   *next;
}   t_dbl_list;

typedef struct s_st
{
    t_dbl_list	*head;
    t_dbl_list  *tmp;
    t_dbl_list  *tail;
    int     min;
    int     max;
    int     fixed_size;
    int     size;
}   t_st;

typedef struct s_ab
{
    t_st	*a;
    t_st	*b;
    int     count;
    int     sum;
    int     multiplier;
    bool    sorted;
    char    *pmove;
    int     i;
}   t_ab;

/* sorting default */
void    sort_three(t_ab *ab);
void    sort_four(t_ab *ab);
void    sort_five(t_ab *ab);
void    sort_till_five(t_ab *ab);
void    get_new_min(t_ab *ab);
void    get_new_max(t_ab *ab);
bool    is_sorted(t_ab *ab);
bool    is_reverse_sorted(t_ab *ab);
/* sorting advanced */
void    first_phase(t_ab *ab);
void    not_recursive_sort(t_ab *ab);
/* list */
void    add_node(t_ab *ab, int data);
void    move_to_do(t_ab *ab, int move);
/* init */
void    init(t_ab *ab);
void    init_ab(t_ab *ab);
void    init_cost(t_ab *ab);
void    init_argv(t_ab *ab, int argc, char **argv);
/* error message*/
void    error_msg(int error);
/* operations */
void    sa(t_ab *ab);
void    sb(t_ab *ab);
void    ss(t_ab *ab);
void    pa(t_ab *ab);
void    pb(t_ab *ab);
void    ra(t_ab *ab);
void    rb(t_ab *ab);
void    rr(t_ab *ab);
void    rra(t_ab *ab);
void    rrb(t_ab *ab);
void    rrr(t_ab *ab);
/* print */
void    print_move(t_ab *ab, char *move);

#endif