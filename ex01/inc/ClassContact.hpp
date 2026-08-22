/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 20:39:28 by cycolonn          #+#    #+#             */
/*   Updated: 2026/08/22 21:58:16 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ClassContact_HPP
# define ClassContact_HPP
# include <iostream>

class ClassContact
{
    public:

        ClassContact(void);
        ~ClassContact(void);

        std::string name;
        std::string number;
};

#endif