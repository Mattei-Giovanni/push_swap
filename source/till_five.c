/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   till_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:56:10 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/17 16:56:11 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void sort_two(t_ab *ab)
{
    if(ab->a->head->data == ab->a->max)
        print_move(ab, "sa");
}

void sort_three(t_ab *ab)
{
    printf("ab->a->head->data = %d\n", ab->a->head->data);
    printf("ab->a->tail->data = %d\n", ab->a->tail->data);
    printf("min = %d\n", ab->a->min);
    printf("max = %d\n", ab->a->max);
    if(ab->a->head->data == ab->a->min)
    {
        print_move(ab, "sa");
        print_move(ab, "ra");
    }
    else if(ab->a->head->data == ab->a->max)
    {
        if(ab->a->tail->data == ab->a->min)
        {
            print_move(ab, "sa");
            print_move(ab, "rra");
        }
        else
            print_move(ab, "ra");
    }
    else
    {
        if(ab->a->tail->data == ab->a->max)
            print_move(ab, "sa");
        else
            print_move(ab, "rra");
    }
}

void sort_four(t_ab *ab)
{
    ab->a->tmp = ab->a->head;
    if(ab->a->head->next->data == ab->a->min)
        print_move(ab, "sa");
    else if(ab->a->tail->data == ab->a->min)
        print_move(ab, "rra");
    while(ab->a->head->data != ab->a->min)
        print_move(ab, "ra");
    if(is_sorted(ab) == false)
    {
        printf("ab->a->head->data = %d\n", ab->a->head->data);
        printf("ab->a->tail->data = %d\n", ab->a->tail->data);
        printf("min = %d\n", ab->a->min);
        printf("max = %d\n", ab->a->max);
        print_move(ab, "pb");
        get_new_min(ab);
        sort_three(ab);
        print_move(ab, "pa");
    }
    ab->a->head = ab->a->tmp;
}

void sort_five(t_ab *ab)
{
    if(ab->a->head->next->data == ab->a->min)
        print_move(ab, "sa");
    else if(ab->a->tail->data == ab->a->min)
        print_move(ab, "rra");
    else
    {
        while(ab->a->head->data != ab->a->min)
            print_move(ab, "ra");
        print_move(ab, "pb");
    }
    if(ab->a->head->next->data == ab->a->max)
        print_move(ab, "sa");
    else if(ab->a->tail->data == ab->a->max)
        print_move(ab, "rra");
    else
    {
        while(ab->a->head->data != ab->a->max)
            print_move(ab, "ra");
        print_move(ab, "pb");
        print_move(ab, "ra");
    }
    get_new_min(ab);
    get_new_max(ab);
    sort_three(ab);
    print_move(ab, "pa");
}

void sort_till_five(t_ab *ab)
{
    printf("sort_till_five\n");
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