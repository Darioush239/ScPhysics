#include "Questions.h"
#include <iostream>
#include <string>
#include <unistd.h>
////////////////////////////////////////////////////////////////////////
class CoulombValue : public Question
{
  public:
    void
    Solve () override
    {
        std::cout << "Insert the number of Electrons: ";
        std::getline (std::cin, Input);
        IntInput = GetInteger (Input);
        Sum = IntInput * electronCharge;
        Display ();
    }

    void
    Display () override
    {
        std::cout << IntInput << " Amount of electrons are equal to " << Sum
                  << " Coulombs\n\n\n";
    }
};

class ElectronCharge : public Question
{
  public:
    void
    Solve () override
    {
        std::cout << "Insert the value of Coulombs: ";
        std::getline (std::cin, Input);
        IntInput = GetInteger (Input);
        Sum = IntInput / electronCharge;
        Display ();
    }

    void
    Display () override
    {
        std::cout << IntInput << " Value of Coulombs is equal to " << Sum
                  << " Electrons\n\n\n";
    }
};
////////////////////////////////////////////////////////////////////////
