#include <iostream>
#include <filesystem>
#include "../../hpp/agenda.hpp"

namespace fs = std::filesystem;

std::string askdesc(std::string what){
    std::string result;
    std::cout<<"Entrer le nouveau "<<what<<" de l'agenda."<<std::endl;
    std::cin>>result;
    return result;
}

void changetitle(std::string title, agenda &tomodify){
    tomodify.title = title;
}

bool verifyagenda(){
    return fs::exists("./agenda.agd");
}

void modifytitle(agenda &agd){
    changetitle(askdesc("titre"), agd);
}

void changedescription(std::string description , agenda &agd){
    agd.description = description;
}

void modifydescription(agenda &agd){
    changedescription(askdesc("description"), agd);
}

void loadagenda(agenda &agd){

}