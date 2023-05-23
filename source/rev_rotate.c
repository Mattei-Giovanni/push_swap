/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:46:28 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/18 17:46:29 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void rra(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->a->head;
    while (tmp->next != ab->a->tail)
        tmp = tmp->next;
    tmp->next = NULL;
    ab->a->tail->next = ab->a->head;
    ab->a->head = ab->a->tail;
    ab->a->tail = tmp;
}

void rrb(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->b->head;
    while (tmp->next != ab->b->tail)
        tmp = tmp->next;
    tmp->next = NULL;
    ab->b->tail->next = ab->b->head;
    ab->b->head = ab->b->tail;
    ab->b->tail = tmp;
}

void rrr(t_ab *ab)
{
    rra(ab);
    rrb(ab);
}