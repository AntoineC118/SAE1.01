#include <iostream>
#include "hpp/menu.hpp"
#include "./hpp/agenda.hpp"

int main(){
    agenda newagenda;
    event newevent;
    loadagenda(newagenda);
    showmenu();
    int pressed = getreply();
    switch (pressed)
    {
    case 49:
        modifytitle(newagenda);
        modifydescription(newagenda);
        break;
    case 50:
        displayagenda(newagenda);
        break;
    case 51:
        setid(newevent);
        modifytitle(newevent);
        modifydescription(newevent);
        setstartdate(newevent);
        setenddate(newevent);
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