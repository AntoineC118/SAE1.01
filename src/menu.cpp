#include <iostream>
#include <sstream>
#include <memory>
#include <cstring>
#include <vector>
#include <filesystem>

const std::vector<std::string> options = {
  "(F01) - Modifier le titre et la description de l'agenda",
  "(F02) - Afficher le contenu de l'agenda",
  "(F03) - Ajouter un événement",
  "(F04) - Supprimer un événement",
  "(F05) - Exporter l'agenda sous la forme d'une page HTML",
  "(F06) - Enregistrer l'agenda",
  "(F07) - Quitter l'application"
};

void showmenu(){
  std::cout<<"Choose options:"<<std::endl;
  for (std::string show : options)
  std::cout<<show<<std::endl;
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
  for(size_t i = 1; i <= options.size()+1; i++){
    size_t pos = result.find(std::to_string(i));
    if (pos != -1){
      return atoi(&result.at(pos));
    }
  }
  return -1;
}

std::filesystem::path getpathreply(){
  std::filesystem::path toreturn;
  std::string result;
  result = std::cin.get();
  if(result.find_first_of("/")!=result.find_last_of("/")){
    toreturn = result;
    return toreturn;
  }
  toreturn = "./agendas/" + result;
  return toreturn;
}

void choosefolder(){
  std::cout<<"Entrer le nom ou le chemin d'accès de votre fichier:"<<std::endl;
}