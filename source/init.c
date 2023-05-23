/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:43:14 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/18 16:43:15 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void add_node(t_ab *ab, int data)
{
    t_dbl_list *new;
    new = malloc(sizeof(t_dbl_list));
    new->data = data;
    new->next = NULL;
    if (ab->a->head == NULL)
    {
        ab->a->head = new;
        ab->a->tail = new;
    }
    else
    {
        ab->a->tail->next = new;
        ab->a->tail = new;
    }
    ab->a->size++;
}

void    init(t_ab *ab)
{
    ab->a = malloc(sizeof(t_st));
    ab->b = malloc(sizeof(t_st));
    ab->a->head = NULL;
    ab->a->tail = NULL;
    ab->b->head = NULL;
    ab->b->tail = NULL;
    ab->a->size = 0;
    ab->b->size = 0;
    ab->a->max = 0;
    ab->a->min = 0;
    ab->b->max = 0;
    ab->b->min = 0;
    ab->sorted = true;
}

void    init_ab(t_ab *ab)
{
    ab->a->tmp = ab->a->head;
    ab->a->max = 0;
    ab->a->min = ab->a->head->data;
    while (ab->a->head != ab->a->tail)
    {
        if(ab->a->head->data > ab->a->max)
            ab->a->max = ab->a->head->data;
        ab->a->head = ab->a->head->next;
        if(ab->a->head->data > ab->a->max)
            ab->a->max = ab->a->head->data;
    }
    ab->a->head = ab->a->tmp;
    while (ab->a->head != ab->a->tail)
    {
        if(ab->a->head->data < ab->a->min)
            ab->a->min = ab->a->head->data;
        ab->a->head = ab->a->head->next;
        if(ab->a->head->data < ab->a->min)
            ab->a->min = ab->a->head->data;
    }
    ab->a->head = ab->a->tmp;
    ab->count = (5 + (ab->a->size / 100)) / 2;
    ab->sum = ab->a->size / ab->count;
    init_cost(ab);
}

void init_cost(t_ab *ab)
{
    int i;
    int tmp;

    i = 0;
    while(i < ab->a->size)
    {
        if(i > 1)
            ab->a->head = ab->a->tmp;
        ab->a->tmp = ab->a->head;
        tmp = ab->a->head->data;
        while(ab && ab->a && ab->a->head)
        {
            if(ab->a->head->data < tmp)
                tmp = ab->a->head->data;
            ab->a->head = ab->a->head->next;
        }
        ab->a->head = ab->a->tmp;
        while(ab && ab->a && ab->a->head)
        {
            if(ab->a->head->data == tmp)
            {
                ab->a->head->cost = i;
                break;
            }
            ab->a->head = ab->a->head->next;
        }
        ab->a->head = ab->a->tmp;
        i++;
    }
}

void init_argv(t_ab *ab, int argc, char **argv)
{
    int i;

    i = 0;
    while (i < argc)
    {
        if(argv[i + 1] != NULL && ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
            ab->sorted = false;
        if (ft_isdigit(*argv[i]))
            add_node(ab, ft_atoi(argv[i]));
        else
            error_msg(-2);
        i++;
    }
}
