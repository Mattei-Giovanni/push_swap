/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <giovanni.mattei.job@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:09:51 by gmattei           #+#    #+#             */
/*   Updated: 2023/05/23 22:51:20 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    print_move(t_ab *ab, int move)
{
    if(move == 1)
        write(1, "pb\n", 3);
    else if(move == 2)
        write(1, "pa\n", 3);
    else if(move == 3)
        write(1, "ra\n", 3);
    else if(move == 4)
        write(1, "rb\n", 3);
    else if(move == 5)
        write(1, "rr\n", 3);
    else if(move == 6)
        write(1, "rra\n", 4);
    else if(move == 7)
        write(1, "rrb\n", 4);
    else if(move == 8)
        write(1, "rrr\n", 4);
    else if(move == 9)
        write(1, "sa\n", 3);
    else if(move == 10)
        write(1, "sb\n", 3);
    else if(move == 11)
        write(1, "ss\n", 3);
    ab->prev_move = move;
}

void get_new_min(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->a->head;
    while(1)
    {
        while(ab->a->head)
        {
            if(ab->a->head->data == ab->a->min)
            {
                ab->a->head = tmp;
                return;
            }
            ab->a->head = ab->a->head->next;
        }
        ab->a->min++;
        ab->a->head = tmp;
    }
    ab->a->head = tmp;
}
void get_new_max(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->a->head;
    while(1)
    {
        while(ab->a->head)
        {
            if(ab->a->head->data == ab->a->max)
            {
                ab->a->head = tmp;
                return;
            }
            ab->a->head = ab->a->head->next;
        }
        ab->a->max--;
        ab->a->head = tmp;
    }
    ab->a->head = tmp;
}
bool is_sorted(t_ab *ab)
{

    ab->a->tmp = ab->a->head;
    while(ab->a->head->next)
    {
        if(ab->a->head->data > ab->a->head->next->data)
        {
            ab->a->head = ab->a->tmp;
            return (false);
        }
        ab->a->head = ab->a->head->next;
    }
    ab->a->head = ab->a->tmp;
    return (true);
}
