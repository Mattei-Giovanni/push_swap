/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:17:24 by gmattei           #+#    #+#             */
/*   Updated: 2023/04/19 16:17:24 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void    error_msg(int error)
{
    //write(1, "\033[1;31mError, no arguments given", 31);
    if (error == -1)
        write(1, "Error, no arguments given\n", 26);
    else if (error == -2)
        write(1, "Error, wrong input, digits needed\n", 34);
    else if (error == -3)
        write(1, "", 0);
    else if (error == -4)
        write(1, "", 0);
    else if (error == -5)
        write(1, "", 0);
}
