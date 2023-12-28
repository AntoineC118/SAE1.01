#include <iostream>
#include "hpp/menu.hpp"
#include "./hpp/agenda.hpp"

int main(){
    agenda newagenda;
    loadagenda(newagenda);
    showmenu();
    int pressed = getreply();
    std::cout<<pressed<<std::endl;
    switch (pressed)
    {
    case 49:
        modifytitle(newagenda);
        modifydescription(newagenda);
        break;
    case 50:

        break;
    case 51:

        break;
    case 52:

        break;
    case 53:

        break;
    case 54:

        break;
    case 55:

        break;
    default:
        std::cout<<"cancel"<<std::endl;
        break;
    }
    return 0;
}