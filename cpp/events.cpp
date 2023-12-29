#include <iostream>
#include <vector>
#include <random>
#include <cstring>
#include <string>
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
    std::string result;
    std::cout<<"Entrer la date de "<<what<<" de l'événement."<<std::endl<<"Merci de respecter le format jj/mm/aaaa_hh:mm"<<std::endl;
    std::cin>>result;
    return result;
}

date pushdate(std::string sdate){
    date newdate;
    newdate.day = stoi(std::to_string(sdate.at(0)))*10 + stoi(std::to_string(sdate.at(1)));
    newdate.month = stoi(std::to_string(sdate.at(3)))*10 + stoi(std::to_string(sdate.at(4)));
    newdate.year = stoi(std::to_string(sdate.at(6)))*1000 + stoi(std::to_string(sdate.at(7)))*100 + stoi(std::to_string(sdate.at(8)))*10 + stoi(std::to_string(sdate.at(9)));
    newdate.hour = stoi(std::to_string(sdate.at(11)))*10 + stoi(std::to_string(sdate.at(12)));
    newdate.min = stoi(std::to_string(sdate.at(14)))*10 + stoi(std::to_string(sdate.at(15)));
    return newdate;
}

bool verifydate(date toverify){
    return
    (toverify.month <= 12) || 
    (((toverify.month % 2 != 0) || (toverify.month <= 7)) && ((toverify.month % 2 == 0) || (toverify.month <= 8))) ||
    (((toverify.year % 4) == 0 || (toverify.year % 100) != 0 || (toverify.month == 2)) ? toverify.day <= 29 : toverify.day <= 28) ||
    (toverify.hour < 24) ||
    (toverify.min < 60);
}

void setstartdate(event &tosetdate){
    date toset;
    toset = pushdate(askdate("début"));
    if(verifydate(toset)){
        tosetdate.startdate = toset;
    }
    else{
        std::cout<<"Date invalide"<<std::endl;
    }
}

void setenddate(event &tosetdate){
    date toset;
    toset = pushdate(askdate("fin"));
    if(verifydate(toset)){
        tosetdate.enddate = toset;
    }
    else{
        std::cout<<"Date invalide"<<std::endl;
    }
}