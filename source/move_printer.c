/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:09:51 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/20 12:09:52 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    print_move(t_ab *ab, char *move)
{
    if (move[0] == 'p' && move[1] == 'a')
        pa(ab);
    else if (move[0] == 'p' && move[1] == 'b')
        pb(ab);
    else if (move[0] == 's' && move[1] == 'a')
        sa(ab);
    else if (move[0] == 's' && move[1] == 'b')
        sb(ab);
    else if (move[0] == 's' && move[1] == 's')
        ss(ab);
    else if (move[0] == 'r' && move[1] == 'a')
        ra(ab);
    else if (move[0] == 'r' && move[1] == 'b')
        rb(ab);
    else if (move[0] == 'r' && move[1] == 'r' && ft_strlen(move) == 2)
        rr(ab);
    else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'a')
        rra(ab);
    else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'b')
        rrb(ab);
    else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'r')
        rrr(ab);
    write(1, move, ft_strlen(move));
    write(1, "\n", 1);
}

void get_new_min(t_ab *ab)
{
    t_dbl_list *tmp;

    printf("data = %d\n", ab->a->head->data);
    tmp = ab->a->head;
    while(1)
    {
        ab->a->min++;
        printf("data = %d\n", ab->a->head->data);
        while(ab->a->head)
        {
            if(ab->a->head->data == ab->a->min)
                return;
            ab->a->head = ab->a->head->next;
        }
        ab->a->head = tmp;
    }
    printf("data = %d\n", ab->a->head->data);
    ab->a->head = tmp;
    printf("data = %d\n", ab->a->head->data);
}
void get_new_max(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->a->head;
    while(1)
    {
        ab->a->max--;
        while(ab->a->head)
        {
            if(ab->a->head->data == ab->a->max)
                return;
            ab->a->head = ab->a->head->next;
        }
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
    return (true);
}
