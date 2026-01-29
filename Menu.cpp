#include "Menu.h"
#include "Questions/Question.hpp"
#include "Questions/Questions.h"
#include <curses.h>
#include <iostream>
#include <string>
#include <unistd.h>

Menu::Menu ()
    : StringInput (), IntInput (), Type (-1), Variant (-1), AvailableOptions ()
{
}

void
Menu::Run ()
{
    bool running = true;
    while (running)
        {
            Type = GetType ();

            if (Type == 0)
                {
                    running = false;
                    continue;
                }
            Variant = GetVariant (Type);
            QuestionMap.at ({ Type, Variant }) ();
        }
    Exit ();
}

int
Menu::GetType ()
{
    while (true)
        {
            std::cout << "Choose question type: \n";
            for (const auto &[type, variant] : AvailableOptions)
                {
                    std::cout << type << ") " << GetQuestionName (type)
                              << std::endl;
                }

            std::getline (std::cin, StringInput);
            Type = GetInteger (StringInput);

            if (AvailableOptions.count (Type))
                {
                    break;
                }

            Clear ();
            std::cout << "Invalid type. Try again.\n";
        }
    return Type;
}

int
Menu::GetVariant (int T)
{
    while (true)
        {
            std::cout << "Choose variant for Type " << Type << std::endl;
            std::cout << GetVariants (T) << std::endl;
            std::getline (std::cin, StringInput);
            Variant = GetInteger (StringInput);
            if (AvailableOptions[T].count (Variant))
                {
                    break;
                }
            Clear ();
            std::cout << "Invalid Input. Try again.\n";
        }
    return Variant;
}

std::string
Menu::GetQuestionName (int id)
{
    switch (id)
        {
        case 0:
            return "Exit";
        case 1:
            return "Electric Charge";
        default:
            return "Unknown";
        }
}

void
Menu::Initialize ()
{
    QuestionMap[{ 1, 1 }] = [this] ()
        {
            std::cout << "Chosen question: Type(1), Variant(1)\n";
            bool LoopVariant = true;
            CoulombValue solve;

            while (LoopVariant)
                {
                    Clear ();
                    solve.Solve ();

                    Question::Return action = solve.CallBack ();
                    if (action == Question::Return::MainMenu)
                        {
                            Clear ();
                            LoopVariant = false;
                        }
                }
        };
    QuestionMap[{ 1, 2 }] = [this] ()
        {
            std::cout << "Chosen question: Type(1), Variant(2)\n";
            bool LoopVariant = true;
            ElectronCharge solve;

            while (LoopVariant)
                {
                    Clear ();
                    solve.Solve ();

                    Question::Return action = solve.CallBack ();
                    if (action == Question::Return::MainMenu)
                        {
                            Clear ();
                            LoopVariant = false;
                        }
                }
        };

    for (const auto &[key, func] : QuestionMap)
        {
            Type = key.first;
            Variant = key.second;
            AvailableOptions[Type].insert (Variant);
        }
}

std::string
Menu::GetVariants (int id)
{
    switch (id)
        {
        case 1:
            return "1) Electron -> Coulomb\n2) Coulomb -> Electron";
        default:
            return "Unknown Variant";
        }
}
