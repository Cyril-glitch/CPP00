/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:39:28 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/24 21:37:46 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Contact_HPP
# define Contact_HPP
# include <iostream>

class Contact
{
    public:

        Contact(void);
        ~Contact(void);

        std::string name;
        std::string number;
};

#endif