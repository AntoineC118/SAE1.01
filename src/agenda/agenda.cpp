#include <iostream>
#include <filesystem>
#include "../../include/agenda.hpp"
#include <string>

namespace fs = std::filesystem;

std::string askdesc(std::string what){
    std::string result = "";
    std::string line = "";
    std::cout<<"Entrez "<<what<<" de l'agenda."<<std::endl;
    if(what != "le nouveau titre"){
        do{
            std::getline(std::cin,line);
            line = line + "\n";
            result = result + line;
        }while (line != ".\n");
    result.erase(result.size()-3, 3);}
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
    changetitle(askdesc("le nouveau titre"), agd);
}

void changedescription(std::string description , agenda &agd){
    agd.description = description;
}

void modifydescription(agenda &agd){
    changedescription(askdesc("la nouvelle description"), agd);
}

void displayagenda(agenda agd){
    std::cout<<"Nom de l'agenda: "<<agd.title<<std::endl;
    std::cout<<"Description de l'agenda: "<<std::endl<<agd.description;
    std::cout<<std::endl<<"----------------"<<std::endl;
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

std::vector<int> searchevent(const std::vector<event> &tosearch, std::string title){
    std::vector<int> toreturn;
    for (size_t i = 0; i <= tosearch.size(); i++){
        if (tosearch[i].title == title){
            toreturn.push_back(i);  
        }
    }
    return toreturn;
}

void deleteevent(agenda &agd, std::string title){
    std::vector<int> posliste;
    std::vector<event> todeleteevent;
    todeleteevent = agd.events;
    posliste = searchevent(todeleteevent, title);
    int pos;
    if (posliste.size() == 1){
        pos = posliste[0];
        todeleteevent.erase(todeleteevent.begin()+posliste[0]);
        agd.events = todeleteevent;
        std::cout<<todeleteevent.size()<<std::endl;
    }
    else if (posliste.size() == 0){
        std::cout<<"Cet event n'existe pas."<<std::endl;
        return;
    }
    else if (posliste.size() > 1){
        std::cout<<"Ces events possèdent le même nom, le quel souhaitez-vous supprimer ?"<<std::endl;
        int counter = 1;
        std::string reply;
        for(int i : posliste){
            std::cout<<counter<<" Evénement du: "<<todeleteevent[i].startdate.day<<"/"<<todeleteevent[i].startdate.month<<"/"<<todeleteevent[i].startdate.year<<" "<<todeleteevent[i].startdate.hour<<":"<<todeleteevent[i].startdate.min<<std::endl;
            counter++;
        }
        std::cin>>reply;
        for (int i = 0; i <= counter; i++){
            std::string tosearch = std::to_string(i);
            if (reply.find(tosearch) > 0){
                todeleteevent.erase(todeleteevent.begin() + posliste[i]);
                agd.events = todeleteevent;
                return;
            }
        }
    }
}