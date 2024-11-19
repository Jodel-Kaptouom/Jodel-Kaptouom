#include <iostream> 
#include <string>
#include <cstdlib>  // Pour rand()
#include <ctime>    // Pour seed de rand()
#include "person.hpp"


// Définir les pointeurs statiques
Person* Person::thinker = nullptr;
Person* Person::guesser = nullptr;

Person::Person(const std::string & name, int number_point) noexcept: _name (name), _number_point (number_point)
{
   
}

void Person::GiveYourName()  noexcept
{
    std::cout << "Veuiller entrer votre nom : ";   
    std::cin >> _name; 
}

// Funktion zur zufälligen Rollenzuweisung
void Person::AssignRoles(Person& player1, Person& player2) noexcept 
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

    std::cout << "Roles assignes"<< std::endl;
    std::cout << "Thinker: "<< thinker ->GetName() << std::endl;
    std::cout << "Guesser: "<< guesser ->GetName() << std::endl;
}

void Person::PlayRound (Person& thinker, Person& guesser) noexcept
{
    std::string secretword;
    std::string guessedletter; 
    const int maxAttempts = 10;
    int attempt = 0; 

    std:: cout << thinker.GetName() << "Entrer le mot a deviner(ne le montrer pas a " << guesser.GetName()<< ")."<< std::endl;
    std:: cin >> secretword; 


// “Clear” the screen so that the guesser cannot see the word
    std::cout << std::string(100, '\n');
// Fortschritt initialisieren (alle Buchstaben verdeckt)
    std::string progress(secretword.size(), '_');

    std::cout << guesser.GetName()<< "vous avez" << maxAttempts << "pour deviner le mot secret" << std::endl; 
    while (attempt < maxAttempts) 
    {
        std:: cout << "Essai" << attempt+1 <<"/" << maxAttempts<< ":" << std::endl; 
        std:: cin >> guessedletter; 

        if (guessedletter.size() == 1 )
        {
            char guessedchar = guessedletter [0];
            bool found = false; 

              // Aktualisiere den Fortschritt, wenn der Buchstabe korrekt ist
            for (size_t i = 0; i < secretword.size(); ++i)
            {
                if (secretword[i] == guessedchar && progress[i] == '_')
                {
                    progress[i] = guessedchar; // Zeige den Buchstaben an
                    found = true;
                }
            if (found)
            {
                std::cout << "Correct! La lettre '" << guessedchar << "' est dans le mot.\n";
            }
            else
            {
                std::cout << "Faux! La lettre '" << guessedchar << "' n'est pas dans le mot.\n";
            }
            }
        }
        attempt++; 
    }
    std::cout << "Désolé, vous avez épuisé vos essais. Le mot était: " << secretword << "\n";
}


