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
    while(ab->a->size > 5)
    {
        if(ab->a->head->cost <= ab->sum)
        {
            pb(ab);
            if(ab->b->head->cost > 0 && ab->b->head->cost <= ab->sum / 2)
                rb(ab);
        }
        else
            ra(ab);
        if(i == 100)
            i = 0;
        i++;
    }
}
