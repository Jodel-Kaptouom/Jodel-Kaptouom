#include <iostream> 
#include "person.hpp"


// Funktion zur zufälligen Rollenzuweisung
void AssignRoles(Person& player1, Person& player2, Person*& thinker, Person*& guesser)
{
    // Randomisiere die Rolle
    if (rand() % 2 == 0)
    {
        thinker = &player1;
        guesser = &player2;
    }
    else
    {
        thinker = &player2;
        guesser = &player1;
    }
}

int main ()
{
   Person player1 ("", 0);
   Person player2 ("", 0);

   player1.GiveYourName(); 
   player2.GiveYourName();

   std::cout << "Bienvenue joueur1 :" << player1.GetName()<<std::endl; 
   std::cout <<  "nombre de points : " << player1.GetPoint() <<std::endl; 
   std::cout << "Bienvenue joueur 2 :" << player2.GetName()<< "nombre de points" << player2.GetPoint() <<std::endl;
   return 0;   
}               