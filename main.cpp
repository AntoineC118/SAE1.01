#include <iostream>
#include "include/menu.hpp"
#include "./include/agenda.hpp"
#include "./include/save.hpp"

int main(){
    agenda newagenda;
    event newevent;
    std::filesystem::path path = "";
    choosefolder();
    path = getpathreply();
    loadagenda(newagenda,path);
    std::cout<<newagenda.title<<std::endl;
    while (true){
        showmenu();
        int pressed = getreply();
        switch (pressed)
        {
        case 1:
            modifytitle(newagenda);
            modifydescription(newagenda);
            break;
        case 2:
            std::cout<<newagenda.title<<std::endl;
            displayagenda(newagenda);
            break;
        case 3:
            setid(newevent);
            modifytitle(newevent);
            modifydescription(newevent);
            setstartdate(newevent);
            setenddate(newevent);
            newagenda.events.push_back(newevent);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            saveagenda(newagenda,path);
            break;
        case 7:
            return 0;
            break;
        default:
            std::cout<<"cancel"<<std::endl;
            break;
        }
    }
return 0;
}