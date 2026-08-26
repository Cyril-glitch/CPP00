/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:09:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/27 01:31:44 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/mapb.hpp"

//Constructor
PhoneBook::PhoneBook(void)
{
    nb_contacts = 0;
    contact[nb_contacts].firstname = "coucou";
    return ;
}


//Affichage du Titre du programme.
void PhoneBook::displaylogo(void)
{
    std::cout << ICE_BLUE;
    std::cout << "▖  ▖    ▄▖                ▄▖▌         ▄     ▌ \n"
              << "▛▖▞▌▌▌  ▌▌▌▌▌█▌▛▘▛▌▛▛▌█▌  ▙▌▛▌▛▌▛▌█▌  ▙▘▛▌▛▌▙▘\n"
              << "▌▝ ▌▙▌  ▛▌▚▚▘▙▖▄▌▙▌▌▌▌▙▖  ▌ ▌▌▙▌▌▌▙▖  ▙▘▙▌▙▌▛▖\n"
              << "    ▄▌                                        \n\n"; 
    std::cout << RESET;
}


/*
GET_CMD
On boucle a l'infini tant qu'une commande valide n'est pas saisie.
*/


//On affiches les commandes disponibles et on recupere l'entree utilisateur.
void PhoneBook::displaycmds(void)
{
    std::cout << MINT "PLEASE ENTER ONES OF FOLLOWING COMMANDS :\n\n" RESET;
    std::cout << SALMON "ADD" RESET << "\n";
    std::cout << SALMON "SEARCH" RESET << "\n";
    std::cout << SALMON "EXIT\n" RESET << "\n";
}

//On verifie que la commande entree fait partie des commandes disponibles.
int PhoneBook::checkcmd(void)
{
    return (cmd == "ADD" || cmd == "SEARCH" || cmd == "EXIT");
}

//Les eventuels erreurs concernant le flux d'entree sont geree par safegetline.
int PhoneBook::getcmd(void)
{        
    while(true)
    {
        displaycmds();
        if (!safe_getline(cmd))
            return 0;
        if (checkcmd())
            return 1;
    }
}



/*
EXECMD
On boucle tant que la commande EXIT n'est pas saisie 
*/


int PhoneBook::execmd(void)
{   
        if(cmd == "ADD")
            add();
        if(cmd == "SEARCH") 
            search();
        if (cmd == "EXIT")
            return exit(); 
        return 1;
}

/*
ADD
On boucle tant que tout les champs du contact ne sont pas remplie
*/


//On recupere la saisie utilisateur dans la string "info" et on la verifie.
int PhoneBook::getfield(std::string field)
{            
        while(true)
        {
            std::cout << SALMON << field  << RESET ;  
            if (!safe_getline(info))
                return 0;
            if (checkfield())
                break;
        }
        fillfield(field);
        return 1;
}

void PhoneBook::fillfield(std::string field)
{
    if (field == "first name:")
        contact[nb_contacts].setfirstname(info);
    if (field == "last name:")
        contact[nb_contacts].setlastname(info);
    if (field == "nick name:")
        contact[nb_contacts].setnickname(info); 
    if (field == "phone number:")
        contact[nb_contacts].setnumber(info);
    if (field == "darkest secret:")
        contact[nb_contacts].setnumber(info); 
}

//On verifie qu'elle n'est pas vide ou compose d'ispace3
int PhoneBook::checkfield(void)
{
    return (info.empty() || strisspace(info));
}


//On reitere le procede sur toutes les informations demande a l'utilisateur
int PhoneBook::add(void)
{
    std::cout << ICE_BLUE "***\nADD A NEW CONTACT\n***" RESET << std::endl;

    if (!getfield("first name:")) return 0;
    if (!getfield("last name:")) return 0;
    if (!getfield("nickname:")) return 0;
    if (!getfield("phone number:")) return 0;
    if (!getfield("darkest secret:")) return 0;
    return 1;
}

void PhoneBook::search(void)
{
    (void)contact;
    std::cout << ICE_BLUE "***SEARCHING FOR A CONTACT***" RESET << std::endl;
}

int PhoneBook::exit(void)
{
    std::cout << MINT "GOOD BYE !" RESET << std::endl;
    return 0;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}
