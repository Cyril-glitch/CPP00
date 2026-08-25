/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:46:01 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/26 00:52:36 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Contact.hpp"

Contact::Contact(void)
{
    return ;
}

void Contact::setfirstname(std::string input)
{
    firstname = input; 
}

void Contact::setlastname(std::string input)
{
    lastname = input; 
}

void Contact::setnickname(std::string input)
{
    nickname = input; 
}

void Contact::setnumber(std::string input)
{
    phonenumber = input; 
}

void Contact::setsecret(std::string input)
{
    darkestsecret = input; 
}

std::string Contact::getfirstname(void) const
{
    return firstname; 
}

std::string Contact::getlastname(void) const
{ 
    return lastname;
}

std::string Contact::getnickname(void) const
{ 
    return nickname;
}

std::string Contact::getnumber(void) const
{
    return phonenumber; 
}

std::string Contact::getsecret(void) const
{
    return darkestsecret; 
}

Contact::~Contact(void)
{
    return ;
}