/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <giovanni.mattei.job@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:09:51 by gmattei           #+#    #+#             */
/*   Updated: 2023/05/23 22:51:20 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int  ft_strcmp(char *s1, char *s2)
{
    int i;
    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

void    actually_print_moves(t_ab *ab)
{
    int i;

    i = 0;
    while (i < ab->i)
    {
        if(i > 0 && ((ft_strcmp(ab->arr[i], "ra") && ft_strcmp(ab->arr[i + 1], "rb")) || (ft_strcmp(ab->arr[i], "rb") && ft_strcmp(ab->arr[i + 1], "ra"))))
        {
            write(1, "rr\n", 3);
            i++;
        }
        else if(i > 0 && ((ft_strcmp(ab->arr[i], "rra") && ft_strcmp(ab->arr[i + 1], "rrb")) || (ft_strcmp(ab->arr[i], "rrb") && ft_strcmp(ab->arr[i + 1], "rra"))))
        {
            write(1, "rrr\n", 4);
            i++;
        }
        else if(i > 0 && ((ft_strcmp(ab->arr[i], "sa") && ft_strcmp(ab->arr[i + 1], "sb")) || (ft_strcmp(ab->arr[i], "sb") && ft_strcmp(ab->arr[i + 1], "sa"))))
        {
            write(1, "ss\n", 3);
            i++;
        }
        else
            write(1, ab->arr[i], ft_strlen(ab->arr[i]));
        i++;

    }
}

void get_new_min(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->a->head;
    while(1)
    {
        while(ab->a->head)
        {
            if(ab->a->head->data == ab->a->min)
            {
                ab->a->head = tmp;
                return;
            }
            ab->a->head = ab->a->head->next;
        }
        ab->a->min++;
        ab->a->head = tmp;
    }
    ab->a->head = tmp;
}
void get_new_max(t_ab *ab)
{
    t_dbl_list *tmp;

    tmp = ab->a->head;
    while(1)
    {
        while(ab->a->head)
        {
            if(ab->a->head->data == ab->a->max)
            {
                ab->a->head = tmp;
                return;
            }
            ab->a->head = ab->a->head->next;
        }
        ab->a->max--;
        ab->a->head = tmp;
    }
    ab->a->head = tmp;
}
bool is_sorted(t_ab *ab)
{

    ab->a->tmp = ab->a->head;
    while(ab->a->head->next)
    {
        if(ab->a->head->data > ab->a->head->next->data)
        {
            ab->a->head = ab->a->tmp;
            return (false);
        }
        ab->a->head = ab->a->head->next;
    }
    ab->a->head = ab->a->tmp;
    return (true);
}
