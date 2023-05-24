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
}

void not_recursive_sort(t_ab *ab)
{
    int i;

    i = 0;
    while(ab->a->size > 5)
    {
        if(ab->b->size < ab->a->fixed_size - ab->sum)
            ab->multiplier = (i / ab->a->fixed_size + 1); // exemple a->size == 100, multiplier == i / 100 + 1 so  1 per 100 i's + 1
        else   
            ab->multiplier = (i / (ab->a->fixed_size - ab->sum) + 1);
        if(ab->a->head->cost <= ab->sum * ab->multiplier) // exmple a->size == 100, sum == 33
        {
            print_move(ab, 1);
            if(ab->b->head->cost <= (ab->sum * ab->multiplier - ab->sum / 2 ) && ab->a->head->next->cost > ab->sum * ab->multiplier)
                print_move(ab, 5);
            else if(ab->b->head->cost <= (ab->sum * ab->multiplier - ab->sum / 2))
                print_move(ab, 4);
        }
        else
        {
            print_move(ab, 3);
        }
        i++;
    }
    get_new_min(ab);
    get_new_max(ab);
    sort_till_five(ab);
}

