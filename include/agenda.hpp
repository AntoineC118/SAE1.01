#ifndef AGENDA_HPP
#define AGENDA_HPP
#include <iostream>
#include <vector>
#include "events.hpp"

struct agenda{
    std::string title;
    std::string description;
    std::vector<event> events;
};

bool verifyagenda();
void modifytitle(agenda&);
void loadagenda(agenda&);
void modifydescription(agenda&);
void displayagenda(agenda);
void deleteevent(agenda&,std::string);

#endif