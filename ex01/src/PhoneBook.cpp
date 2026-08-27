/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:09:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/27 23:11:42 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/mapb.hpp"

//Constructor
PhoneBook::PhoneBook(void)
{
    _index = 0;
    _nb_contacts = 0;
    return ;
}


//Affichage du Titre du programme.
void PhoneBook::displaylogo(void)
{
    std::cout << ICE_BLUE;
    std::cout << "▖  ▖    ▄▖                ▄▖▌         ▄     ▌ \n"
              << "▛▖▞▌▌▌  ▌▌▌▌▌█▌▛▘▛▌▛▛▌█▌  ▙▌▛▌▛▌▛▌█▌  ▙▘▛▌▛▌▙▘\n"
              << "▌▝ ▌▙▌  ▛▌▚▚▘▙▖▄▌▙▌▌▌▌▙▖  ▌ ▌▌▙▌▌▌▙▖  ▙▘▙▌▙▌▛▖\n"
              << "    ▄▌                                        \n"; 
    std::cout << RESET;
}


/*
GET_CMD
Target : On boucle a l'infini tant qu'une commande valide n'est pas saisie.
*/


//On affiches les commandes disponibles
void PhoneBook::_displaycmds(void)
{
    std::cout << MINT "\n\nPLEASE ENTER ONES OF FOLLOWING COMMANDS :\n\n" RESET;
    std::cout << LAVENDER "ADD" RESET << "\n";
    std::cout << LAVENDER "SEARCH" RESET << "\n";
    std::cout << LAVENDER "EXIT\n" RESET << "\n";
}

//On verifie que la validite de la commande entree
int PhoneBook::_checkcmd(void)
{
    return (_cmd == "ADD" || _cmd == "SEARCH" || _cmd == "EXIT");
}

//Les eventuels erreurs concernant le flux d'entree sont geree par safegetline.
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



/*
EXECMD
target : On boucle tant que la commande EXIT n'est pas saisie 
*/


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

/*
ADD
Target: On boucle tant que tout les champs du contact ne sont pas remplie
*/

//On met a jour l'index du contact a remplir
void PhoneBook::_update_index(void)
{
    _index = _nb_contacts % 8;
}

void PhoneBook::_displayfield(std::string field)
{
    std::cout << L_GREEN << field << RESET;
}

//On recupere la saisie utilisateur dans la string "info" et on la verifie.
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

//On verifie qu'elle n'est pas vide ou compose d'ispace3
int PhoneBook::_checkfield(void)
{
    if(_info.empty() || strisspace(_info))
    {
        std::cout << BL_RED "Contact can't have empty fields.\nPlease Retry." << std::endl; 
        return 0;
    }
    return 1;
}

//On rafraichis le champ conrespondant dans le nouveau contact
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

//On reitere le procede sur toutes les informations demande a l'utilisateur
int PhoneBook::_add(void)
{
    _update_index();
    std::printf(ICE_BLUE "\n#ADD CONTACT [%d]\n\n" RESET, _index);
    if (!_getfield("first name:")) return 0;
    if (!_getfield("last name:")) return 0;
    if (!_getfield("nickname:")) return 0;
    if (!_getfield("phone number:")) return 0;
    if (!_getfield("darkest secret:")) return 0;
    std::cout << GOLD "\nNEW CONTACT : \"" << _contact[_index].firstname << "\" ADDED WITH SUCCESS !" RESET << std::endl;
    _nb_contacts++;
    return 1;
}

void PhoneBook::_search(void)
{
    (void)_contact;
    std::cout << ICE_BLUE "***SEARCHING FOR A CONTACT***" RESET << std::endl;
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