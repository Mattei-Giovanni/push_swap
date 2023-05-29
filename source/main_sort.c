/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <giovanni.mattei.job@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:44:40 by gmattei           #+#    #+#             */
/*   Updated: 2023/05/23 22:52:05 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void first_phase(t_ab *ab)
{
    //while(!is_sorted(ab))
    //{
        not_recursive_sort(ab);
        move_cost_calc(ab);
    //}
}

void not_recursive_sort(t_ab *ab)
{
    int i;

    i = 0;
    while(ab->a->size > 5)
    {
        if(i >= ab->a->fixed_size)
        {
            i = ab->a->fixed_size - ab->a->size;
            ab->multiplier += ab->sum;
        }
        if(ab->a->head->cost <= ab->multiplier)
        {
            print_move(ab, "pb");
            if(ab->b->head->cost <= (ab->multiplier - ab->sum / 2))
                print_move(ab, "rb");
        }
        else
            print_move(ab, "ra");
        i++;
    }
    get_new_min(ab);
    get_new_max(ab);
    sort_till_five(ab);
}

void move_cost_calc(t_ab *ab)
{
    ab->i = 0;
    ab->b->tmp = ab->b->head;
    while(ab->i < ab->b->size)
    {
        ab->mov_b[ab->i] = ab->i;
        if(ab->i >= ab->b->size / 2)
            ab->mov_b[ab->i] = ab->b->size - ab->i;
        printf("mov_b[%d] = %d\n", ab->i, ab->mov_b[ab->i]);
        ab->i++;
    }
    ab->i = 0;
    ab->j = 0;
    while(ab->b->head)
    {
        ab->a->tmp = ab->a->head;
        while(ab->a->head)
        {
            if(ab->a->head->data > ab->b->head->data)
                ab->mov_a[ab->i] = 0;
            else
            {
                while(ab->a->head->data < ab->b->head->data)
                    ab->j++;
                ab->mov_a[ab->i] = ab->j;
                printf("mov_a[%d] = %d\n", ab->i, ab->mov_a[ab->i]);
            }
            ab->a->head = ab->a->head->next;
        }
        ab->i++;
        ab->a->head = ab->a->tmp;
        ab->b->head = ab->b->head->next;
    }
    ab->b->head = ab->b->tmp;
}
