#include <iostream>
#include <ctime>

struct date{
    unsigned short int day;
    unsigned short int month;
    unsigned short int year;
    unsigned short int hour;
    unsigned short int min;
};

struct event{
    std::string id;
    std::string title;
    std::string description;
    date startdate;
    date enddate;
};


void modifytitle(event &);
void modifydescription(event &);
void setid(event &);

