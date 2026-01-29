#ifndef MENU
#define MENU

#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

class Menu
{
  public:
    Menu ();
    std::map<std::pair<int, int>, std::function<void ()>> QuestionMap;
    std::map<int, std::set<int>> AvailableOptions;

    void Initialize ();
    void Run ();
    int GetType ();
    int GetVariant (int T);

  private:
    std::string StringInput;
    long double IntInput;
    int Type = -1;
    int Variant = -1;

    std::string GetQuestionName (int id);
    std::string GetVariants (int id);
};

#endif // !MENU
