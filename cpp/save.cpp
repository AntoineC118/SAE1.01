#include <iostream>
#include <fstream>
#include <filesystem>
#include "../hpp/agenda.hpp"

void saveagenda(agenda tosave){
    std::filesystem::path path;
    path = "./" + tosave.title + ".agd";
    std::ofstream monfichier(path);
    monfichier<<tosave.title<<std::endl
    <<tosave.description<<std::endl;
    for(event e:tosave.events){
        monfichier<<"ID de l'événement: "<<e.id<<std::endl
        <<e.title<<std::endl
        <<e.description<<std::endl
        <<e.startdate.day<<"/"<<e.startdate.month<<"/"<<e.startdate.year<<" "<<e.startdate.hour<<":"<<e.startdate.min<<std::endl
        <<e.enddate.day<<"/"<<e.enddate.month<<"/"<<e.enddate.year<<" "<<e.enddate.hour<<":"<<e.enddate.min<<std::endl;
    }
}