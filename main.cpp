#include <iostream>
#include "include/menu.hpp"
#include "agenda.hpp"
#include "save.hpp"

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
    int counter = 0;
    std::string title;
    while (true){
        showmenu();
        int pressed = getreply();
        switch (pressed)
        {
        case 1:
            modifytitle(newagenda);
            modifydescription(newagenda);
            counter++;
            std::cout << "[200~\x1b[2J\x1b[H";
            break;
        case 2:
            std::cout << "[200~\x1b[2J\x1b[H";
            displayagenda(newagenda);
            std::cin.ignore();
            std::cin.get();
            break;
        case 3:
            setid(newevent);
            modifytitle(newevent);
            modifydescription(newevent);
            setstartdate(newevent);
            setenddate(newevent);
            newagenda.events.push_back(newevent);
            counter++;
            std::cout << "[200~\x1b[2J\x1b[H";
            break;
        case 4:
            std::cout<<"Entrer le nom de l'événement a supprimé:"<<std::endl;
            title = getstringreply();
            deleteevent(newagenda,title);
            counter++;
            std::cout << "[200~\x1b[2J\x1b[H";
            break;
        case 5:
            savehmtl(newagenda);
            std::cout << "[200~\x1b[2J\x1b[H";
            break;
        case 6:
            saveagenda(newagenda,path);
            std::cout << "[200~\x1b[2J\x1b[H";
            std::cout<< "fichier sauvegardé.";
            std::cin.ignore();
            std::cin.get();
            std::cout << "[200~\x1b[2J\x1b[H";
            counter = 0;
            break;
        case 7:
            if (counter != 0){
                std::string reply;
                std::cout<<"Vous avez effectué des modifications sans sauvegardé, souhaitez vous sauvegardé ? O/N"<<std::endl;
                std::cin >> reply;
                if(reply == "O") saveagenda(newagenda,path);
            }
            return 0;
            break;
        default:
            std::cout<<"cancel"<<std::endl;
            break;
        }
    }
return 0;
}