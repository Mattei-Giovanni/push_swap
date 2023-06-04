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
    not_recursive_sort(ab);
    //while(ab->a->size != ab->a->fixed_size)
    //{
    for(int i = 0; i < 1; i++)
    {
        move_cost_calc(ab);
        ab->i = 1;
        ab->count = 0;
        while(ab->i < ab->b->size)
        {
            if(ab->mov_all[ab->i] <= ab->mov_all[ab->count])
                ab->count = ab->i;
            ab->i++;
        }
        while(ab->mov_b[ab->count] > 0)
        {
            if(ab->mov_b[ab->count] == 1 && ab->mov_a[ab->count + 1] < ab->mov_a[ab->count + 2])
                print_move(ab, "sb");
            else if(ab->count < ab->b->size / 2)
                print_move(ab, "rb");
            else
                print_move(ab, "rrb");
            ab->mov_b[ab->count]--;
        }
        print_move(ab, "pa");
    }
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
        if(ab->a->head->cost <= ab->multiplier && ab->a->head->cost < ab->a->max - 4)
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
    while(ab->i < ab->b->size)
    {
        ab->mov_b[ab->i] = ab->i;
        if(ab->i >= ab->b->size / 2)
            ab->mov_b[ab->i] = ab->b->size - ab->i;
        ab->i++;
    }
    ab->i = 0;
    ab->b->tmp = ab->b->head;
    while(ab->b->head)
    {
        ab->a->tmp = ab->a->head;
        ab->j = 0;
        while(ab->a->head)
        {
            if(ab->a->head->cost < ab->b->head->cost)
            {
                ab->j++;
                ab->a->head = ab->a->head->next;
            }
            else
                break;
        }
        if(ab->j >= ab->a->size / 2)
            ab->j = ab->a->size - ab->j;
        ab->mov_a[ab->i] = ab->j;
        ab->i++;
        ab->b->head = ab->b->head->next;
        ab->a->head = ab->a->tmp;
    }
    ab->b->head = ab->b->tmp;
    ab->i = 0;
    get_new_max_b(ab);
    while(ab->i < ab->b->size)
    {
        ab->b->tmp = ab->b->head;
        while(ab->b->head->cost != ab->b->max)
            ab->b->head = ab->b->head->next;
        ab->mov_c[ab->i] = ab->i;
        ab->mov_all[ab->i] = ab->mov_a[ab->i] + ab->mov_b[ab->i] + ab->mov_c[ab->i];
        ab->b->head = ab->b->tmp;
        ab->i++;
        printf("mov_a: %d mov_b: %d mov_c: %d mov_all: %d\n", ab->mov_a[ab->i], ab->mov_b[ab->i], ab->mov_c[ab->i], ab->mov_all[ab->i]);
        ab->b->max--;
    }
}

void get_new_max_b(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->b->head;
    ab->b->max = ab->a->max;
    while(1)
    {
        while(ab->b->head)
        {
            if(ab->b->head->data == ab->b->max)
            {
                ab->b->head = tmp;
                return;
            }
            ab->b->head = ab->b->head->next;
        }
        ab->b->max--;
        ab->b->head = tmp;
    }
    ab->b->head = tmp;
}
