/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 23:51:28 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/27 00:16:22 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mapb.hpp"

int strisspace(const std::string str)
{
    size_t i;
    for(i = 0 ; i < str.size() && !std::isspace(str.at(i)); i++);
    return ( i == str.size());
}