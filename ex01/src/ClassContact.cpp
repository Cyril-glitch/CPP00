/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:46:01 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/22 22:03:20 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClassContact.hpp"

ClassContact::ClassContact(void)
{
    std::cout << "constructor called." << std::endl;
    return ;
}

ClassContact::~ClassContact(void)
{
    std::cout << "destructor called." << std::endl;
    return ;
}