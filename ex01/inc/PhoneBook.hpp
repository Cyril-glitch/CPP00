/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:52:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/28 23:45:04 by cycolonn         ###   ########.fr       */
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


    void _displaylogo(void);
    int run(void);
    int _getcmd(void);
    int _execmd(void);
    

    private :

    std::string _cmd;
    std::string _info;
    std::string _target;
    

    int _index;
    int _nb_contacts;
    Contact _contact[8];

    //execmd utils
    int _add();
    int _search();
    void _exit(void);

    //getcmd utils
    void _displaycmds(void);
    int _checkcmd();    


    //add utils
    void _displayfield(std::string field);
    int _getfield(std::string field);
    int _checkfield();    
    void _fillfield(std::string field);
    void _update_index(void);


    //search utils
    int _emptybook(void);
    void displaycontact(void);
    void displaycolumn(void);
    std::string formatfield(std::string field);
    int gettarget(void);
    int out_range(void);

    void displaybadindex(void);
    int checkindex(void);
};

#endif