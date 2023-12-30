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
    std::string line = "";
    std::cout<<"Entrer le nouveau "<<what<<" de l'événement."<<std::endl;
    if(what != "titre"){
    do{
    std::cin>>line;
    line = line + "\n";
    result = result + line;
    }while (line != ".\n");
    result.erase(result.size()-3, 3);}
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
    newdate.day = atoi(&sdate.at(0));
    newdate.month = atoi(&sdate.at(3));
    newdate.year = atoi(&sdate.at(6));
    newdate.hour = atoi(&sdate.at(11));
    newdate.min = atoi(&sdate.at(14));
    return newdate;
}

bool verifydate(date toverify){
    std::cout<<toverify.day<<"/"<<toverify.month<<"/"<<toverify.year<<" "<<toverify.hour<<":"<<toverify.min<<std::endl;
    return
    (toverify.month <= 12) && 
    (((toverify.month % 2 != 0) && (toverify.month <= 7)) || ((toverify.month % 2 == 0) && (toverify.month <= 8))) &&
    (((toverify.year % 4) == 0 && (toverify.year % 100) != 0 && (toverify.month == 2)) ? toverify.day <= 29 : toverify.day <= 28) &&
    (toverify.hour < 24) &&
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