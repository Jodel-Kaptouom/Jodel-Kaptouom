#include <iostream> 
#include "person.hpp"


int main ()
{
   Person player1 ("", 0);
   Person player2 ("", 0);

   player1.GiveYourName(); 
   player2.GiveYourName();

   std::cout << "Bienvenue joueur1 :" << player1.GetName()<< "Points :" << player1.GetPoint()<<std::endl; 
   std::cout << "Bienvenue joueur2 :" << player2.GetName()<< "Points :" << player2.GetPoint() <<std::endl; 

   Person::AssignRoles (player1,player2);
   Person::PlayRound (player1,player2);
   return 0;   
}               

