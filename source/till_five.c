/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   till_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <giovanni.mattei.job@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:56:10 by gmattei           #+#    #+#             */
/*   Updated: 2023/05/23 22:46:09 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void sort_two(t_ab *ab)
{
    if(ab->a->head->data == ab->a->max)
        print_move(ab, 9);
}

void sort_three(t_ab *ab)
{
    if(is_sorted(ab))
        return ;
    if(ab->a->head->data == ab->a->min)
    {
        print_move(ab, 9);
        print_move(ab, 3);
    }
    else if(ab->a->head->data == ab->a->max)
    {
        if(ab->a->tail->data == ab->a->min)
        {
            print_move(ab, 9);
            print_move(ab, 6);
        }
        else
            print_move(ab, 3);
    }
    else
    {
        if(ab->a->tail->data == ab->a->max)
            print_move(ab, 9);
        else
            print_move(ab, 6);
    }
}

void sort_four(t_ab *ab)
{
    ab->a->tmp = ab->a->head;
    if(ab->a->head->next->data == ab->a->min)
        print_move(ab, 9);
    else if(ab->a->tail->data == ab->a->min)
        print_move(ab, 6);
    while(ab->a->head->data != ab->a->min)
        print_move(ab, 3);
    if(ab->sorted == false)
    {
        print_move(ab, 1);
        get_new_min(ab);
        sort_three(ab);
        print_move(ab, 2);
    }
    ab->a->head = ab->a->tmp;
}

void sort_five(t_ab *ab)
{
    if(ab->a->head->next->data == ab->a->max)
        print_move(ab, 9);
    else if(ab->a->tail->data == ab->a->max)
        print_move(ab, 6);
    while(ab->a->head->data != ab->a->max)
        print_move(ab, 3);
    print_move(ab, 1);
    if(ab->a->head->next->data == ab->a->min)
        print_move(ab, 9);
    else if(ab->a->tail->data == ab->a->min)
        print_move(ab, 6);
    while(ab->a->head->data != ab->a->min)
        print_move(ab, 3);
    print_move(ab, 1);
    if(ab->sorted == false)
    {
        get_new_min(ab);
        get_new_max(ab);
        sort_three(ab);
        print_move(ab, 2);
        print_move(ab, 2);
        print_move(ab, 3);
    }
}

void sort_till_five(t_ab *ab)
{
    if(ab->sorted == true)
        return ;
    if (ab->a->size == 2)
        sort_two(ab);
    else if (ab->a->size == 3)
        sort_three(ab);
    else if (ab->a->size == 4)
        sort_four(ab);
    else if (ab->a->size == 5)
        sort_five(ab);
}