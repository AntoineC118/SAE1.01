#ifndef MENU_HPP
#define MENU_HPP

#include <filesystem>

void showmenu();
int getreply();
void choosefolder();
std::filesystem::path getpathreply();

#endif