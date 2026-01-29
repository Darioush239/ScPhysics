#ifndef Questions
#define Questions
#include "../Utils/Utils.h"
#include <functional>
#include <iostream>
#include <map>
#include <string>

class Question
{
  public:
    enum class Return
    {
        RepeatVariant,
        RepeatQuestion,
        MainMenu
    };

    virtual ~Question () = default;
    virtual void Solve () = 0;
    virtual void Display () = 0;

    Return
    CallBack ()
    {
        std::cout
            << "Would you like to solve another question of this variant? or "
               "this type of Question?\n(0) Return to Menu\n(1) Another of "
               "this Variant.\n";
        std::getline (std::cin, Input);
        IntInput = GetInteger (Input);
        if (IntInput == 1)
            {
                return Return::RepeatVariant;
            }
        else
            {
                return Return::MainMenu;
            }
    }

  protected:
    long double IntInput;
    std::string Input;
    long double Sum;
    double electronCharge = 1.6e-19;
};

#endif // !Questions
