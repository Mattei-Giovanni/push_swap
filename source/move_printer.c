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

void    actually_print_move(t_ab *ab, char *move)
{
    if(ft_strlen(move) == 2 && move [0] == 'r' && ab->pmove [0] == 'r' &&((move[1] == 'a' && ab->pmove[1] == 'b') || (move[1] == 'b' && ab->pmove[1] == 'a')))
    {
        move = "rr";
        ft_printf("rr\n");
    }
    else if(ft_strlen(move) == 3 && move [0] == 'r' && ab->pmove [0] == 'r' &&((move[2] == 'a' && ab->pmove[2] == 'b') || (move[2] == 'b' && ab->pmove[2] == 'a')))
    {
        move = "rrr";
        ft_printf("rrr\n");
    }
    else if((move[0] != 'r' || (move[0] == 'r' && move[ft_strlen(move)] == 'r')))
    {
        if(ab->pmove[0] == 'r' && ab->pmove[ft_strlen(ab->pmove) - 1] != 'r')
            ft_printf("%s\n", ab->pmove);
        ft_printf("%s\n", move);
    }
    else if((move[0] == 'r' && ab->pmove[0] == 'r' && ab->pmove[ft_strlen(ab->pmove) - 1] != 'r'))
        ft_printf("%s\n", move);
    if(move[0] == 'r' && move[1] == 'a' && ab->a->size == 5)
        ft_printf("ra\n");
    ab->pmove = move;
}

void    print_move(t_ab *ab, char *move)
{
    ab->i = 0;
    if(move[0] == 'p' && move[1] == 'b')
        pb(ab);
    else if(move[0] == 'p' && move[1] == 'a')
        pa(ab);
    else if(move[0] == 'r' && move[1] == 'a')
        ra(ab);
    else if(move[0] == 'r' && move[1] == 'b')
        rb(ab);
    else if(move[0] == 'r' && move[1] == 'r' && move[2] == 'a')
        rra(ab);
    else if(move[0] == 'r' && move[1] == 'r' && move[2] == 'b')
        rrb(ab);
    else if(move[0] == 'r' && move[1] == 'r' && move[2] == 'r')
        rrr(ab);
    else if(move[0] == 'r' && move[1] == 'r')
        rr(ab);
    else if(move[0] == 's' && move[1] == 'a')
        sa(ab);
    else if(move[0] == 's' && move[1] == 'b')
        sb(ab);
    else if(move[0] == 's' && move[1] == 's')
        ss(ab);
    actually_print_move(ab, move);
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