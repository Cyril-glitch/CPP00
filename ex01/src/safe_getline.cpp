/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_getline.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:29:54 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/29 02:01:52 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mapb.hpp"

static int closedstream(void)
{
    if (std::cin.eof())
    {
        std::cout << BL_RED "input have been closed\n" RESET;
        return 1;
    }
    return 0;
}

static int errinput(void)
{
    if(std::cin.fail())
    {
        std::cout << BL_RED "An error occurred while reading your input. Please try again.\n" RESET;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
    return 0;
}

int safe_getline(std::string &input)
{
    while(true)
    {
        std::getline(std::cin, input);
        if (closedstream()) return -1; 
        if (!errinput()) break;
    } 
    return 1;
}