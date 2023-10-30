#include <iostream>

int showmenu(){
    int result;
    std::cout<<"Choose options:"<<std::endl;
    std::cout<<"(F01) - Modifier le titre et la description de l'agenda"<<std::endl;
    std::cout<<"(F02) - Afficher le contenu de l'agenda"<<std::endl;
    std::cout<<"(F03) - Ajouter un événement"<<std::endl;
    std::cout<<"(F04) - Supprimer un événement"<<std::endl;
    std::cout<<"(F05) - Exporter l'agenda sous la forme d'une page HTML"<<std::endl;
    std::cout<<"(F06) - Enregistrer l'agenda"<<std::endl;
    std::cout<<"(F07) - Quitter l'application"<<std::endl;
    std::cin>> result;
    return result;
}

void call(int id){
    
}