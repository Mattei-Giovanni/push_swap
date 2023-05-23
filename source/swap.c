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
    tmp = ab->a->head->data;
    ab->a->head->data = ab->a->head->next->data;
    ab->a->head->next->data = tmp;
}

void sb(t_ab *ab)
{
    int tmp;
    tmp = ab->b->head->data;
    ab->b->head->data = ab->b->head->next->data;
    ab->b->head->next->data = tmp;
}

void ss(t_ab *ab)
{
    sa(ab);
    sb(ab);
}