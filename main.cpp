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
    if (std::filesystem::exists(path))
        loadagenda(newagenda,path);
    else{
        std::cout<<"Cet agenda n'existe pas. Création d'un nouvelle agenda."<<std::endl;
        modifytitle(newagenda);
        modifydescription(newagenda);
    }
    std::string title;
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
            std::cout<<"Entrer le nom de l'événement a supprimé:"<<std::endl;
            title = getstringreply();
            deleteevent(newagenda,title);
            break;
        case 5:
            savehmtl(newagenda);
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