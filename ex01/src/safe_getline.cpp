/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_getline.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:29:54 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/25 02:01:31 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mapb.hpp"

int safe_getline(std::string &input)
{
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << BL_RED "input have been closed\n" RESET;
        return 0;
    }
    else if(std::cin.fail())
    {
        std::cout << BL_RED "An error occurred while reading your input. Please try again.\n" RESET;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        safe_getline(input);
    }
    return 1;
}