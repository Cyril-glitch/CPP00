/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:39:28 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/28 02:24:58 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Contact_HPP
# define Contact_HPP
# include <iostream>
# include <string>
#include <sstream>

class Contact
{
    public:

        Contact(void);
        ~Contact(void);

        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecret;

        void setfirstname(std::string input);
        void setlastname(std::string input);
        void setnickname(std::string input);
        void setnumber(std::string input);
        void setsecret(std::string input);

        std::string getfirstname(void) const;
        std::string getlastname(void) const;
        std::string getnickname(void) const;
        std::string getnumber(void) const;
        std::string getsecret(void) const;

        void display_all_fields(void);
};

#endif