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

int PhoneBook::checkline(void)
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
        if (checkline())
            return 1;
    }
}

void PhoneBook::add(void)
{
    (void)contacts;
    std::cout << ICE_BLUE "***ADD A NEW CONTACT***" RESET << std::endl;
    
}

void PhoneBook::search(void)
{
    (void)contacts;
    std::cout << ICE_BLUE "***SEARCHING FOR A CONTACT***" RESET << std::endl;

}

int PhoneBook::exit(void)
{
    std::cout << MINT "GOOD BYE !" RESET << std::endl;
    return 0;
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

PhoneBook::~PhoneBook(void)
{
    return ;
}
