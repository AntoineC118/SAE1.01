#include <iostream>
#include <ctime>

struct event{
    std::string id;
    std::string title;
    std::string description;
    std::tm startdate;
    std::tm enddate;
    
};


void modifytitle(event &);
void modifydescription(event &);
void setid(event &);

