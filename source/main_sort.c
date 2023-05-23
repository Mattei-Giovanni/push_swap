/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:44:40 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/20 13:44:41 by gmattei          ###   ########.fr       */
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
    printf("min: %d\n", ab->a->min);
    printf("max: %d\n", ab->a->max);
    printf("size: %d\n", ab->a->size);
    printf("count: %d\n", ab->count);
    printf("sum: %d\n", ab->sum);
    while(ab->a->size > 5)
    {
        if(ab->a->head->cost <= ab->sum * (i / ab->a->size + 1))
        {
            pb(ab);
            printf("pb\n");
            if(ab->b->head->cost > 0 && ab->b->head->cost <= ab->sum / 2)
                rb(ab);
        }
        else
            ra(ab);
        i++;
    }
    get_new_min(ab);
    get_new_max(ab);
    sort_till_five(ab);
}
