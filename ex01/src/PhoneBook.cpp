#include <iostream>
#include "../inc/mapb.hpp"

PhoneBook::PhoneBook(void)
{
    return ;
}

void PhoneBook::displaylogo(void)
{
    std::cout << ICE_BLUE;
    std::cout << "▖  ▖    ▄▖                ▄▖▌         ▄     ▌ \n"
              << "▛▖▞▌▌▌  ▌▌▌▌▌█▌▛▘▛▌▛▛▌█▌  ▙▌▛▌▛▌▛▌█▌  ▙▘▛▌▛▌▙▘\n"
              << "▌▝ ▌▙▌  ▛▌▚▚▘▙▖▄▌▙▌▌▌▌▙▖  ▌ ▌▌▙▌▌▌▙▖  ▙▘▙▌▙▌▛▖\n"
              << "    ▄▌                                        \n\n"; 
    std::cout << RESET;
}

void PhoneBook::displaycmds(void)
{
    std::cout << MINT "PLEASE ENTER ONES OF FOLLOWING COMMANDS :\n\n" RESET;
    std::cout << SALMON "ADD" RESET << "\n";
    std::cout << SALMON "SEARCH" RESET << "\n";
    std::cout << SALMON "EXIT\n" RESET << "\n";
}

int PhoneBook::checkcmd(void)
{
    return (cmd == "ADD" || cmd == "SEARCH" || cmd == "EXIT");
}

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

int PhoneBook::checkinfo(void)
{
    return (info.empty());
}

int PhoneBook::getinfo(void)
{        
    while(true)
    {
        displaycmds();
        if (!safe_getline(info))
            return 0;
        if (checkinfo())
            return 1;
    }
}

void PhoneBook::add(void)
{
    std::cout << ICE_BLUE "***ADD A NEW CONTACT***" RESET << std::endl;
    std::cout << MINT "***please enter the information of the new contact one field at a time" RESET << std::endl;    

    std::cout << CORAL "First name:" RESET;
        getinfo();
        contact[nb_contacts].setfirstname(info);
    std::cout << CORAL "Last name:" RESET;
        getinfo();
        contact[nb_contacts].setlastname(info);
    std::cout << CORAL "Nick name:" RESET;
        getinfo();
        contact[nb_contacts].setnickname(info);
    std::cout << CORAL "Phone number:" RESET;
        getinfo();
        contact[nb_contacts].setnumber(info);
    std::cout << PURPLE "Darkest secret:" RESET;
        getinfo();
        contact[nb_contacts].setsecret(info);
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
