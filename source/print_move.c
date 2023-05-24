/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:08:02 by gmattei           #+#    #+#             */
/*   Updated: 2023/05/24 19:08:03 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    print_move_4(t_ab *ab, int move)
{
    if (move == 9)
    {
        ab->arr[ab->i][0] = 's';
        ab->arr[ab->i][1] = 'a';
        sa(ab);
    }
    else if (move == 10)
    {
        ab->arr[ab->i][0] = 's';
        ab->arr[ab->i][1] = 'b';
        sb(ab);
    }
    else if (move == 11)
    {
        ab->arr[ab->i][0] = 's';
        ab->arr[ab->i][1] = 's';
        ss(ab);
    }
    ab->i++;
}

void    print_move_3(t_ab *ab, int move)
{
    if (move == 6)
    {
        ab->arr[ab->i][0] = 'r';
        ab->arr[ab->i][1] = 'r';
        ab->arr[ab->i][2] = 'a';
        rra(ab);
    }
    else if (move == 7)
    {
        ab->arr[ab->i][0] = 'r';
        ab->arr[ab->i][1] = 'r';
        ab->arr[ab->i][2] = 'b';
        rrb(ab);
    }
    else if (move == 8)
    {
        ab->arr[ab->i][0] = 'r';
        ab->arr[ab->i][1] = 'r';
        ab->arr[ab->i][2] = 'r';
        rrr(ab);
    }
    print_move_4(ab, move);
}
void    print_move_2(t_ab *ab, int move)
{
    if (move == 3)
    {
        ab->arr[ab->i][0] = 'r';
        ab->arr[ab->i][1] = 'a';
        ra(ab);
    }
    else if (move == 4)
    {
        ab->arr[ab->i][0] = 'r';
        ab->arr[ab->i][1] = 'b';
        rb(ab);
    }
    else if (move == 5)
    {
        ab->arr[ab->i][0] = 'r';
        ab->arr[ab->i][1] = 'r';
        rr(ab);
    }
    print_move_3(ab, move);
}

void    print_move(t_ab *ab, int move)
{
    if (move == 1)
    {
        ab->arr[ab->i][1] = 'p';
        ab->arr[ab->i][1] = 'b';
        pb(ab);
    }
    else if (move == 2)
    {
        ab->arr[ab->i][0] = 'p';
        ab->arr[ab->i][1] = 'a';
        pa(ab);
    }
    print_move_2(ab, move);
}