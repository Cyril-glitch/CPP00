/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:09:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/28 02:29:57 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/mapb.hpp"

PhoneBook::PhoneBook(void)
{
    _index = 0;
    _nb_contacts = 0;
    return ;
}

void PhoneBook::displaylogo(void)
{
    std::cout << ICE_BLUE;
    std::cout << "▖  ▖    ▄▖                ▄▖▌         ▄     ▌ \n"
              << "▛▖▞▌▌▌  ▌▌▌▌▌█▌▛▘▛▌▛▛▌█▌  ▙▌▛▌▛▌▛▌█▌  ▙▘▛▌▛▌▙▘\n"
              << "▌▝ ▌▙▌  ▛▌▚▚▘▙▖▄▌▙▌▌▌▌▙▖  ▌ ▌▌▙▌▌▌▙▖  ▙▘▙▌▙▌▛▖\n"
              << "    ▄▌                                        \n"; 
    std::cout << RESET;
}

void PhoneBook::_displaycmds(void)
{
    std::cout << MINT "\n\nPLEASE ENTER ONES OF FOLLOWING COMMANDS :\n\n" RESET;
    std::cout << LAVENDER "ADD" RESET << "\n";
    std::cout << LAVENDER "SEARCH" RESET << "\n";
    std::cout << LAVENDER "EXIT\n" RESET << "\n";
}

int PhoneBook::_checkcmd(void)
{
    return (_cmd == "ADD" || _cmd == "SEARCH" || _cmd == "EXIT");
}

int PhoneBook::getcmd(void)
{        
    while(true)
    {
        _displaycmds();
        if (!safe_getline(_cmd))
            return 0;
        if (_checkcmd())
            return 1;
    }
}

int PhoneBook::execmd(void)
{   
        if(_cmd == "ADD")
            _add();
        if(_cmd == "SEARCH") 
            _search();
        if (_cmd == "EXIT")
            return _exit(); 
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
            if (!safe_getline(_info))
                return 0;
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
        std::cout << BL_RED "Contact can't have empty fields.\nPlease Retry." << std::endl; 
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
        _contact[_index].setnumber(_info); 
}

int PhoneBook::_add(void)
{
    _update_index();
    std::printf(ICE_BLUE "\n#ADD CONTACT [%d]\n\n" RESET, _index);
    if (!_getfield("first name:")) return 0;
    if (!_getfield("last name:")) return 0;
    if (!_getfield("nick name:")) return 0;
    if (!_getfield("phone number:")) return 0;
    if (!_getfield("darkest secret:")) return 0;
    std::cout << GOLD "\nNEW CONTACT : \"" << _contact[_index].firstname << "\" ADDED WITH SUCCESS !" RESET << std::endl;
    _nb_contacts++;
    return 1;
}

int PhoneBook::_emptybook(void)
{
    if (_nb_contacts == 0)
    {
        std::cout << "YOU HAVEN'T SAVED CONTACT YET..." << std::endl;
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
    for(int i = 0; i < _nb_contacts; i++)
    {
        std::cout << std::right
              << std::setw(10)<< i << "|"
              << std::setw(10)<< formatfield(_contact[i].getfirstname()) << "|"
              << std::setw(10)<< formatfield(_contact[i].getlastname()) << "|"
              << std::setw(10)<< formatfield(_contact[i].getnickname()) << "|"
              << std::endl;
    }
}

int PhoneBook::out_range(void)
{
    if (_target.size() > 1) return 1;
    if (!_target.find_first_not_of("01234567")) return 1;
    if ((_target.at(0) - 48) > (_nb_contacts - 1)) return 1; 
    return 0;
}

int PhoneBook::checkindex(void)
{
    if (out_range())
    {
        std::cout << BL_RED "\ninvalid index...please select index of an existing contact" RESET << std::endl;
        return 0;
    }
    return 1;
}

int PhoneBook::gettarget(void)
{
    while (true)
    {
        displaycolumn();
        displaycontact();
        if (!safe_getline(_target))
            return -1;
        if (checkindex())
            break;
    }
    return _target.at(0) - 48;
}

void PhoneBook::_search(void)
{ 
    int index;

    index = 0;
    if (_emptybook()) return;
    index = gettarget();
    if (index == -1) return ;
    _contact[index].display_all_fields(); 
}

int PhoneBook::_exit(void)
{
    std::cout << MINT "GOOD BYE !" RESET << std::endl;
    return 0;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}