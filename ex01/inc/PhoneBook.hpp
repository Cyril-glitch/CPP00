/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:52:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/27 22:05:31 by cycolonn         ###   ########.fr       */
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

    std::string _cmd;
    std::string _info;
    
    int _index;
    int _nb_contacts;
    Contact _contact[8];

    void _displaycmds(void);
    int _checkcmd();    


    void _displayfield(std::string field);
    int _getfield(std::string field);
    int _checkfield();    
    void _fillfield(std::string field);
    void _update_index(void);

    int _add();
    void _search();
    int _exit(void);
};

#endif