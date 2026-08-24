#include <iostream>
#include "../inc/mapb.hpp"

PhoneBook::PhoneBook(void)
{
    return ;
}

void PhoneBook::displaycmds(void)
{
    std::cout << ICE_BLUE;
    std::cout << "▖  ▖    ▄▖                ▄▖▌         ▄     ▌ \n"
              << "▛▖▞▌▌▌  ▌▌▌▌▌█▌▛▘▛▌▛▛▌█▌  ▙▌▛▌▛▌▛▌█▌  ▙▘▛▌▛▌▙▘\n"
              << "▌▝ ▌▙▌  ▛▌▚▚▘▙▖▄▌▙▌▌▌▌▙▖  ▌ ▌▌▙▌▌▌▙▖  ▙▘▙▌▙▌▛▖\n"
              << "    ▄▌                                        \n\n"; 
    std::cout << RESET;

    std::cout << MINT "PLEASE ENTER ONES OF FOLLOWING COMMANDS :\n\n" RESET;
    std::cout << SALMON "ADD" RESET << "\n";
    std::cout << SALMON "SEARCH" RESET << "\n";
    std::cout << SALMON "EXIT\n" RESET << "\n";
}


void PhoneBook::getcmds(std::string& refcmds)
{
    std::cin >> refcmds; 
    std::cout << "\n"; 
    std::cout << MINT "You choose: " SALMON << refcmds << RESET << "\n";
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

