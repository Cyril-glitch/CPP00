/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:09:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/29 02:07:40 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/mapb.hpp"

PhoneBook::PhoneBook(void)
{
    _index = 0;
    _badindex = 0;
    _nb_contacts = 0;
    return ;
}

void PhoneBook::_displaylogo(void)
{
    std::cout << ICE_BLUE;
    std::cout << "▖  ▖    ▄▖                ▄▖▌         ▄     ▌ \n"
              << "▛▖▞▌▌▌  ▌▌▌▌▌█▌▛▘▛▌▛▛▌█▌  ▙▌▛▌▛▌▛▌█▌  ▙▘▛▌▛▌▙▘\n"
              << "▌▝ ▌▙▌  ▛▌▚▚▘▙▖▄▌▙▌▌▌▌▙▖  ▌ ▌▌▙▌▌▌▙▖  ▙▘▙▌▙▌▛▖\n"
              << "    ▄▌                                        \n\n"; 
    std::cout << RESET;
}

int PhoneBook::run(void)
{
    _displaylogo();
    _displaycmds();
    while (true)
    {
        if (_getcmd() == -1)
            return -1;
        if (_execmd() == -1)
            return -1;
        else if (_cmd == "EXIT")
            return 0;
    }
}

void PhoneBook::_displaycmds(void)
{
    std::cout << MINT "Please enter one of the following commands :\n\n" RESET;
    std::cout << LAVENDER "ADD" RESET << "\n";
    std::cout << LAVENDER "SEARCH" RESET << "\n";
    std::cout << LAVENDER "EXIT\n" RESET << "\n";
}

int PhoneBook::_checkcmd(void)
{
    return (_cmd == "ADD" || _cmd == "SEARCH" || _cmd == "EXIT");
}

int PhoneBook::_getcmd(void)
{        
    while(true)
    { 
        displayprompt();
        if (safe_getline(_cmd) == -1)
            return -1;
        if (_checkcmd())
            return 1;
    }
}

int PhoneBook::_execmd(void)
{   
        if(_cmd == "ADD")
            if (_add() == -1) return -1;
        if(_cmd == "SEARCH") 
            if (_search() == -1) return -1;
        if (_cmd == "EXIT")
            _exit(); 
        return 1;
}

void PhoneBook::_update_index(void)
{
    _index = _nb_contacts % 8;
}

void PhoneBook::_displayfield(std::string field)
{
    std::cout << L_GREEN << field << RESET;
}

int PhoneBook::_getfield(std::string field)
{            
        while(true)
        {
            _displayfield(field);
            if (safe_getline(_info) == -1)
                return -1;
            if (_checkfield())
                break;
        }
        _fillfield(field);
        return 1;
}

int PhoneBook::_checkfield(void)
{
    if(_info.empty() || strisspace(_info))
    {
        std::cout << BL_RED "Contacts cannot have empty fields. Please try again." << std::endl; 
        return 0;
    }
    return 1;
}

void PhoneBook::_fillfield(std::string field)
{
    if (field == "first name:")
        _contact[_index].setfirstname(_info);
    if (field == "last name:")
        _contact[_index].setlastname(_info);
    if (field == "nick name:")
        _contact[_index].setnickname(_info); 
    if (field == "phone number:")
        _contact[_index].setnumber(_info);
    if (field == "darkest secret:")
        _contact[_index].setsecret(_info); 
}

int PhoneBook::_add(void)
{
    _update_index();
    std::cout << ICE_BLUE "\ncontact[" << _index << "]" RESET << std::endl;
    if (_getfield("first name:") == -1) return -1;
    if (_getfield("last name:") == -1) return -1;
    if (_getfield("nick name:")== -1) return -1;
    if (_getfield("phone number:")== -1) return -1;
    if (_getfield("darkest secret:")== -1) return -1;
    std::cout << GOLD "\nNew contact \"" << _contact[_index].firstname << "\" added successfully!\n" RESET << std::endl;
    _nb_contacts++;
    return 1;
}

int PhoneBook::_emptybook(void)
{
    if (_nb_contacts == 0)
    {
        std::cout << BL_RED "You don't have any contacts yet..." RESET << std::endl;
        return 1;
    }
    return 0;
}

std::string PhoneBook::formatfield(std::string field)
{
    if (field.size() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::displaycolumn()
{
    std::cout << std::right << std::endl
              << std::setw(10) << "index" << "|"
              << std::setw(10) << "firstname" << "|"
              << std::setw(10) << "lastname" << "|"
              << std::setw(10) << "nickname" << "|"
              << std::endl;
}

void PhoneBook::displaycontact()
{
    for(int i = 0; i < 8 && i < _nb_contacts; i++)
    {
        std::cout << std::right
              << std::setw(10)<< i << "|"
              << std::setw(10)<< formatfield(_contact[i].getfirstname()) << "|"
              << std::setw(10)<< formatfield(_contact[i].getlastname()) << "|"
              << std::setw(10)<< formatfield(_contact[i].getnickname()) << "|"
              << std::endl;
    }
    std::cout << MINT "\nEnter the index of the contact you are looking for" << std::endl;
}

int PhoneBook::out_range(void)
{
    if (_target.empty()) return 1;
    if (_target.size() > 1) return 1;
    if (!_target.find_first_not_of("01234567")) return 1;
    if ((_target.at(0) - 48) > (_nb_contacts - 1)) return 1; 
    return 0;
}

int PhoneBook::checkindex(void)
{
    if (out_range())
        return 0; 
    return 1;
}

void PhoneBook::display_bad_index(void)
{
    if (_badindex)
            std::cout << BL_RED "Error: please select the index of an existing contact" RESET << std::endl;
}

int PhoneBook::gettarget(void)
{
    while (true)
    {
        displaycolumn();
        displaycontact();
        display_bad_index();
        displayprompt();
        if (safe_getline(_target) == -1)
            return -1;
        if (checkindex())
            break; 
        _badindex = 1;
    }
    _badindex = 0;
    return _target.at(0) - 48;
}

int PhoneBook::_search(void)
{ 
    int targeti;

    targeti = 0;
    if (_emptybook()) return 0;
    targeti = gettarget();
    if (targeti == -1) return -1;
    _contact[targeti].display_all_fields(targeti); 
    return 1;
}

void PhoneBook::_exit(void)
{
    std::cout << MINT "Goodbye !" RESET << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}