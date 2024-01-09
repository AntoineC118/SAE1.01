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
    <<"."<<std::endl;
    for(event e:tosave.events){
        monfichier<<e.id<<std::endl
        <<e.title<<std::endl
        <<e.description<<std::endl
        <<"."<<std::endl
        <<e.startdate.day<<" "<<e.startdate.month<<" "<<e.startdate.year<<" "<<e.startdate.hour<<" "<<e.startdate.min<<std::endl
        <<e.enddate.day<<" "<<e.enddate.month<<" "<<e.enddate.year<<" "<<e.enddate.hour<<" "<<e.enddate.min<<std::endl;
    }
}

bool verifyfolder(std::filesystem::path path){
    std::string name;
    name = path.filename();
    return name[name.size()] == 'a' && name[name.size()-1] == 'g' && name[name.size()-2] == 'd';
}

void loadagenda(agenda &topushin, std::filesystem::path path){
    std::ifstream myfolder(path);
    std::string line = "";
    myfolder>>topushin.title;
    while (line != "."){
    std::getline(myfolder,line);
    topushin.description = topushin.description + line;
    }
    int counter = 0;
    while (!myfolder.eof()){
        myfolder>>topushin.events[counter].id;
        myfolder>>topushin.events[counter].title;
        myfolder.ignore();
        while (line != "."){
            std::getline(myfolder,line);
            topushin.events[counter].description = topushin.events[counter].description + line;
        }
        myfolder>>topushin.events[counter].startdate.day;
        myfolder>>topushin.events[counter].startdate.month;
        myfolder>>topushin.events[counter].startdate.year;
        myfolder>>topushin.events[counter].startdate.hour;
        myfolder>>topushin.events[counter].startdate.min;
        myfolder>>topushin.events[counter].enddate.day;
        myfolder>>topushin.events[counter].enddate.month;
        myfolder>>topushin.events[counter].enddate.year;
        myfolder>>topushin.events[counter].enddate.hour;
        myfolder>>topushin.events[counter].enddate.min;
        counter = counter + 1;
        std::cout<<topushin.title<<std::endl;
    }
}
