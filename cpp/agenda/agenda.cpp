#include <iostream>
#include <filesystem>
#include "../../hpp/agenda.hpp"

namespace fs = std::filesystem;

std::string askdesc(std::string what){
    std::string result = "";
    std::cout<<"Entrer le nouveau "<<what<<" de l'agenda."<<std::endl;
    if(what != "titre"){
    do{
    std::cin>>result;
    }while (result != ".");}
    else std::cin>>result;
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

void displayagenda(agenda agd){
    std::cout<<"Nom de l'agenda: "<<agd.title<<std::endl;
    std::cout<<"Description de l'agenda: "<<agd.description<<std::endl;
    std::cout<<"----------------"<<std::endl;
    std::cout<<"Liste des événements:"<<std::endl;
    for (event e:agd.events){
        std::cout<<"ID de l'événement: "<<e.id<<std::endl;
        std::cout<<"Titre: "<<e.title<<std::endl;
        std::cout<<"Description: "<<e.description<<std::endl;
        std::cout<<"Début: "<<e.startdate.day<<"/"<<e.startdate.month<<"/"<<e.startdate.year<<" "<<e.startdate.hour<<":"<<e.startdate.min<<std::endl;
        std::cout<<"Fin: "<<e.enddate.day<<"/"<<e.enddate.month<<"/"<<e.enddate.year<<" "<<e.enddate.hour<<":"<<e.enddate.min<<std::endl;
        std::cout<<"----------------"<<std::endl;
    }   
}