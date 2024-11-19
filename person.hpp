#ifndef __PERSON__    
    #define __PERSON__  
    #include <string>

    class Person 
    {
        public: 
            Person() = delete;
            Person (const std::string& name, int number_point) noexcept;
            void GiveYourName()  noexcept;
            static void AssignRoles(Person& player1, Person& player2) noexcept;
            static void PlayRound (Person& thinker, Person& guesser) noexcept;
            std::string GetName () noexcept {return _name;}; 
            int GetPoint () const noexcept{ return _number_point;}; 

        private: 
            std::string _name;
            int _number_point;

            static Person* thinker;  
            static Person* guesser; 
    };

#endif