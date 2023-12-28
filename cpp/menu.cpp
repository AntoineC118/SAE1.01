#include <iostream>
#include <sstream>
#include <memory>
#include <cstring>

void showmenu(){
    std::cout<<"Choose options:"<<std::endl;
    std::cout<<"(F01) - Modifier le titre et la description de l'agenda"<<std::endl;
    std::cout<<"(F02) - Afficher le contenu de l'agenda"<<std::endl;
    std::cout<<"(F03) - Ajouter un événement"<<std::endl;
    std::cout<<"(F04) - Supprimer un événement"<<std::endl;
    std::cout<<"(F05) - Exporter l'agenda sous la forme d'une page HTML"<<std::endl;
    std::cout<<"(F06) - Enregistrer l'agenda"<<std::endl;
    std::cout<<"(F07) - Quitter l'application"<<std::endl;
}

bool isNumeric(const std::string& s) {
  size_t sz=0;
  try {
    std::stod(s, &sz);
  } catch (const std::invalid_argument& ia) {
  }
  return ((sz>0) && (s.size() == sz));
}

int getreply(){
    std::string result;
    std::cin>>result;
    std::string token;
    int toreturn;
    for(size_t i; i != result.size(); i++){
        if (std::stoi(std::to_string(result[i])) >= 49 || std::stoi(std::to_string(result[i])) <= 55){
          return std::stoi(std::to_string(result[i]));
    return 0;
        }
    }
}


