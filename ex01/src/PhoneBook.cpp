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

int PhoneBook::checkcmd(std::string& refcmd)
{
    return (refcmd == "ADD" || refcmd == "SEARCH" || refcmd == "EXIT");
}

int PhoneBook::getcmd(std::string& refcmd)
{        
    if (!safe_getline(refcmd))
        return 0;
    if (!checkcmd(refcmd))
    {
        displaycmds();
        getcmd(refcmd);
    }
    std::cout << MINT "You choose: " SALMON << refcmd << RESET << "\n"; 
    return 1;
}

int PhoneBook::execmd(std::string cmd)
{
    (void)cmd;
    return 1;
}

void PhoneBook::add(Contact contacts[8])
{
    (void)contacts;
}

void PhoneBook::search(Contact contacts[8])
{
    (void)contacts;
}

void PhoneBook::exit(void)
{
    (void)contacts;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

