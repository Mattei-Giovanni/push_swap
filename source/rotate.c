/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:46:22 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/18 17:46:23 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void ra(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->a->head;
    ab->a->head = ab->a->head->next;
    tmp->next = NULL;
    ab->a->tail->next = tmp;
    ab->a->tail = tmp;
}

void rb(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->b->head;
    ab->b->head = ab->b->head->next;
    tmp->next = NULL;
    ab->b->tail->next = tmp;
    ab->b->tail = tmp;
}

void rr(t_ab *ab)
{
    ra(ab);
    rb(ab);
}