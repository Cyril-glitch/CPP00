/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:52:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/22 22:02:51 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClassPhoneBook_HPP
# define ClassPhoneBook_HPP 
# include "ClassContact.hpp"

class ClassPhoneBook
{
    public :

    ClassPhoneBook(void);
    ~ClassPhoneBook(void);

    ClassContact contacts[8];
    void add(ClassContact contacts[8]);
};

#endif