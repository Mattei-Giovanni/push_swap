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

void    rotate_calc(t_ab *ab, char *move)
{
    if(ab->rot_buff == 0 || (ab->rot_buff > 0 && ft_strcmp(ab->pmove, move) == 0))
            ab->rot_buff++;
        else if(ft_strcmp(ab->pmove, move) > 15 || ft_strcmp(ab->pmove, move) < -15)
        {
            ft_printf("%s\n", ab->pmove);
            while(ab->rot_buff > 0)
            {
                ft_printf("%s\n", ab->pmove);
                ab->rot_buff--;
            }
            ab->rot_buff = 1;
        }
        else
        {
            while(ab->rot_buff > 0)
            {
                if(ft_strlen(move) == 2)
                    ft_printf("rr\n");
                else if(ft_strlen(move) == 3)
                    ft_printf("rra\n");
                ab->rot_buff--;
            }
        }
}

void    actually_print_move(t_ab *ab, char *move)
{
    if(!(move[0] == 'r' && move[ft_strlen(move) - 1] != 'r'))
    {
        while(ab->rot_buff > 0)
        {
            ft_printf("%s\n", ab->pmove);
            ab->rot_buff--;
        }
        ft_printf("%s\n", move);
    }
    else
    {
        rotate_calc(ab, move);
    }
    ab->pmove = move;
}

void    print_move(t_ab *ab, char *move)
{
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