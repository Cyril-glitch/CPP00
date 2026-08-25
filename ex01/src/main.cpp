/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:59:09 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/25 01:57:51 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mapb.hpp"

int main (int ac , char **av)
{
    (void)ac;
    (void)av;

    PhoneBook book;

    book.displaylogo();
    book.displaycmds();
    if (!book.getcmd(book.cmds))
        return -1;
    book.execmd(book.cmds);
}
