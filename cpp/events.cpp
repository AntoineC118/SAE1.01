#include <iostream>
#include <vector>
#include <random>
#include <cstring>
#include "../hpp/events.hpp"

std::string getUID(std::size_t len){
    std::vector<char> x = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a','b', 'c', 'd', 'e', 'f'};
    std::string uid(len, '\0');
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution < > dis(0, x.size()-1);
    for (char& c: uid) {
        c = x[dis(gen)];
    }
    return uid;
}

void setid(event &tomodify){
    tomodify.id = getUID(8);
}

std::string askdescription(std::string what){
    std::string result = "";
    std::cout<<"Entrer le nouveau "<<what<<" de l'événement."<<std::endl;
    if(what != "titre"){
    do{
    std::cin>>result;
    }while (result != ".");}
    else std::cin>>result;
    return result;
}

void changetitle(std::string title, event &tomodify){
    tomodify.title = title;
}

void modifytitle(event &tomodify){
    changetitle(askdescription("titre"), tomodify);
}

void changedescription(std::string description , event &tomodify){
    tomodify.description = description;
}

void modifydescription(event &tomodify){
    changedescription(askdescription("description"), tomodify);
}

std::string askdate(std::string what){
    std::string result = "";
    std::cout<<"Entrer la date de "<<what<<" de l'événement."<<std::endl<<"Merci de respecter le format jj/mm/aaaa hh:mm"<<std::endl;
    std::cin>>result;
    return result;
}

date pushdate(std::string sdate){
    date newdate;
    return newdate;
}
