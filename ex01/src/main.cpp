/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:59:09 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/25 23:50:04 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mapb.hpp"

int main (int ac , char **av)
{
    (void)ac;
    (void)av;

    PhoneBook book;

    book.displaylogo();
    while (true)
    {
        if (!book.getcmd())
            return -1;
        if (!book.execmd())
            return 0;
    }
}
