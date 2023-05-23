/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:50:03 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/18 17:50:04 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void pa(t_ab *ab)
{
    t_dbl_list *tmp;
    tmp = ab->b->head;
    ab->b->head = ab->b->head->next;
    tmp->next = ab->a->head;
    ab->a->head = tmp;
    ab->a->size++;
    ab->b->size--;
}

void pb(t_ab *ab)
{
    t_dbl_list *tmp;
    tmp = ab->a->head;
    if(ab->b->head == NULL)
        ab->b->tail = tmp;
    ab->a->head = ab->a->head->next;
    tmp->next = ab->b->head;
    ab->b->head = tmp;
    ab->b->size++;
    ab->a->size--;
}