#include <iostream>
#include <fstream>
#include <filesystem>
#include "../include/agenda.hpp"

void saveagenda(agenda tosave, std::filesystem::path path){
    if(std::filesystem::is_directory(path)) path += tosave.title + ".agd";
    if (!std::filesystem::exists(path)){
        path = "./agendas/" + tosave.title + ".agd";}
    std::ofstream monfichier(path);
    monfichier<<tosave.title<<std::endl
    <<tosave.description<<std::endl
    <<".";
    for(event e:tosave.events){
        monfichier<<std::endl<<e.id<<std::endl
        <<e.title<<std::endl
        <<e.description<<std::endl
        <<"."<<std::endl
        <<e.startdate.day<<" "<<e.startdate.month<<" "<<e.startdate.year<<" "<<e.startdate.hour<<" "<<e.startdate.min<<std::endl
        <<e.enddate.day<<" "<<e.enddate.month<<" "<<e.enddate.year<<" "<<e.enddate.hour<<" "<<e.enddate.min;
    }
}

bool verifyfolder(std::filesystem::path path){
    std::string name;
    name = path.filename();
    return name[name.size()] == 'a' && name[name.size()-1] == 'g' && name[name.size()-2] == 'd';
}

void loadagenda(agenda &topushin, std::filesystem::path path){
    std::ofstream mytest("./agendas/test");
    std::ifstream myfolder(path);
    event topushout;
    std::string line = "";
    myfolder>>topushin.title;
    myfolder.ignore();
    while (line != "."){
    std::getline(myfolder,line);
    topushin.description = topushin.description + line;
    }
    std::string temp;
    while (!myfolder.eof()){
        myfolder >>topushout.id;
        myfolder >> topushout.title;
        topushout.description = "";
        line = "";
        while (line != "."){
            std::getline(myfolder,line);
            topushout.description = topushout.description + line;
            mytest<<line<<std::endl;
        }
        myfolder>>topushout.startdate.day;
        myfolder>>topushout.startdate.month;
        myfolder>>topushout.startdate.year;
        myfolder>>topushout.startdate.hour;
        myfolder>>topushout.startdate.min;
        myfolder>>topushout.enddate.day;
        myfolder>>topushout.enddate.month;
        myfolder>>topushout.enddate.year;
        myfolder>>topushout.enddate.hour;
        myfolder>>topushout.enddate.min;
        topushin.events.push_back(topushout);
        std::string emptyer;
        std::getline(myfolder, emptyer);
    }
}

void savehmtl(agenda agd){
    
}