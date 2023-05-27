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
        //move_cost_calc(ab);
        not_recursive_sort(ab);
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

