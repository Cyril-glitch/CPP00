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
              << "    ▄▌                                        \n" 
              << std::endl;
    std::cout << RESET;

    std::cout << MINT "PLEASE ENTRE ONES OF FOLLOWING COMMANDS :\n\n" RESET;
    std::cout << SALMON "ADD" RESET << std::endl;
    std::cout << SALMON "SEARCH" RESET << std::endl;
    std::cout << SALMON "EXIT" RESET << std::endl;
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

