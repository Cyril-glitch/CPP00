#include <iostream>
#include "../inc/ClassPhoneBook.hpp"

ClassPhoneBook::ClassPhoneBook(void)
{
    std::cout << "constructor called." << std::endl;
    return ;
}

void ClassPhoneBook::add(ClassContact contacts[8])
{

}

ClassPhoneBook::~ClassPhoneBook(void)
{
    std::cout << "destructor called." << std::endl;
    return ;
}

