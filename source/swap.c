/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:30:55 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/18 16:30:56 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void sa(t_ab *ab)
{
    int tmp;
    int tmp2;
    tmp = ab->a->head->data;
    tmp2 = ab->a->head->cost;
    ab->a->head->data = ab->a->head->next->data;
    ab->a->head->cost = ab->a->head->next->cost;
    ab->a->head->next->data = tmp;
    ab->a->head->next->cost = tmp2;
}

void sb(t_ab *ab)
{
    int tmp;
    int tmp2;
    tmp = ab->b->head->data;
    tmp2 = ab->b->head->cost;
    ab->b->head->data = ab->b->head->next->data;
    ab->b->head->cost = ab->b->head->next->cost;
    ab->b->head->next->data = tmp;
    ab->b->head->next->cost = tmp2;
}

void ss(t_ab *ab)
{
    sa(ab);
    sb(ab);
}