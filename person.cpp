#include <iostream> 
#include <string>
#include "person.hpp"

Person::Person (const std::string & name, int number_point) noexcept: _name (name), _number_point (number_point)
{
   
}

void Person::GiveYourName()  noexcept
{
     std::cout << "Veuiller entrer votre nom : ";   
    std::cin >> _name; 
}



