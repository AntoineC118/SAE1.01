#ifndef AGENDA_HPP
#define AGENDA_HPP
#include <iostream>

struct agenda{
    std::string title;
    std::string description;
};

bool verifyagenda();
void modifytitle(agenda&);
void loadagenda(agenda&);
void modifydescription(agenda&);

#endif