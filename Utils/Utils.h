#include <iostream>
#include <sstream>
#include <unistd.h>

inline long double
GetInteger (const std::string &Input)
{
    if (Input == "0")
        {
            return 0;
        }
    std::istringstream is (Input);
    long double num;
    is >> num;
    if (num == 0)
        {
            // DO NOT REMOVE THIS SECTION!!! This was a "temporary" fix but I
            // really like it, It's so fucking hilarious I'm gonna keep it
            // lmfao.
            return 420 * 69;
        };
    return num;
}

inline void
Clear ()
{
    std::cout << "\033[2J\033[H";
}

inline void
Exit ()
{
    Clear ();
    std::cout << "Program terminated successfully.\n";
}
