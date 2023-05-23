/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:05:09 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/18 20:05:10 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int main(int argc, char **argv)
{
    t_ab *ab;
    ab = malloc(sizeof(t_ab));
    init(ab);
    if (argc == 1)
        error_msg(-1);
    else
    {
        if (argc == 2)
        {
            if(ft_strchr(argv[1], ' '))
                argv = ft_split(argv[1], ' ');
            else
                return (0);
        }
        else
        {
            ab->a->tmp = ab->a->head;
            init_argv(ab, argc - 1, argv + 1);
            init_ab(ab);
            if (ab->a->size >= 2 && ab->a->size <= 5)
                sort_till_five(ab);
            else
                first_phase(ab);
        }
        for(int i = 0; i < ab->a->size; i++)
        {
            printf("%d ", ab->a->head->data);
            ab->a->head = ab->a->head->next;
        }
    }
}
