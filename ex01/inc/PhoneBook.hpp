/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:52:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/27 01:20:07 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP 
# include "Contact.hpp"

class PhoneBook
{
    public :

    PhoneBook(void);
    ~PhoneBook(void);

    void displaylogo(void);
    int getcmd();
    int execmd();
    

    private :

    std::string cmd;
    std::string info;
    
    int nb_contacts;
    Contact contact[8];

    void displaycmds(void);


    int checkcmd();    
    int getfield(std::string field);
    int checkfield();    

    void fillfield(std::string field);

    int add();
    void search();
    int exit(void);
};

#endif