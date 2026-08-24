/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:59:09 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/24 22:55:10 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mapb.hpp"

int main (int ac , char **av)
{
    (void)ac;
    (void)av;

    PhoneBook book;
    book.displaycmds();
    book.getcmds(book.cmds);
}
