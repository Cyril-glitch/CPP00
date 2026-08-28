/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:46:01 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/28 02:32:44 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mapb.hpp"
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

void    Contact::display_all_fields(void)
{
    std::cout << L_GREEN "first name:" RESET << getfirstname() << std::endl
              << L_GREEN "last name:" RESET << getlastname() << std::endl 
              << L_GREEN "nick name:" RESET << getnickname() << std::endl 
              << L_GREEN "phone number:" RESET << getnumber() << std::endl 
              << L_PURPLE "darkest secret:" RESET << getsecret() << std::endl
              << std::endl;
}

Contact::~Contact(void)
{
    return ;
}