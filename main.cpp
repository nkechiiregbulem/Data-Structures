//
//  main.cpp
//  REG
//
//  Created by Nkechi Iregbulem on 1/23/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//
#include "REG.h"
#include <iostream>
#include <string>
#include <time.h>
#include <random>


TvShows::TvShows()
{
    std::string name;
    std::string show;
    std::string episode;
    int randomIndex = 0;
}
TvShows::TvShows(std::string ShowName)
{
    name = ShowName;
}
void TvShows::setShow(std::string tvShow)
{
    std::string ShowName = tvShow;
    name = tvShow;
}
void TvShows::setEpisodes(std::string episodes)
{
    std::string episode = episodes;
   
    
}
std::string TvShows::getShow()
{
    return name;
}
std::string TvShows::getEpisodes()
{
    int randomIndex = rand() % 10;
    std::string temp[10] = {"Season1:Episode1", "Season2:Episode2", "Season 3:Episode3", "Season 4:Episode4","Season5:Episode 2", "Season1: Episode 3", "Season 2:Episode 12", "Season 3:Episode 8", "Season 4: Episode 10", "Season 5: Episode 15"};
    for( int i = 0; i < 10; ++i )
        episode[i] = temp[i];
    return episode[randomIndex];
    return getEpisodes();
}
void TvShows::printInfo()
{
    int option = 0;
    //std::cout << name << std::endl;
    //std::cout << name << std::endl;
    //std::cout << name << std::endl;
    //std::cout << name << std::endl;
    while (option < 1 || option > 4) {
        std::cout << "Please Enter an Option" << std::endl;
        std::cin >> option;
    };
    
    srand( static_cast<unsigned int>(time(NULL)));
    if (option == 1) {
        std::cout << "You have chosen to watch " << name << std::endl << " Please wait a moment while we generate an episode" << std::endl;
        std::cout << "........................." << std::endl;
        std::cout << getEpisodes() << std::endl;
    }
    if (option == 2) {
        std::cout << "You have chosen to watch "<< name << std::endl << "Please wait a moment while we generate an episode" << std::endl;
        std::cout << ".........................." << std::endl;
        std::cout << getEpisodes() << std::endl;
    }
    if (option == 3) {
        std::cout << "You have chosen to watch " << name << std::endl <<"Please wait a moment while we generate an episode" << std::endl;
        std::cout << "......................" << std::endl;
        std::cout << getEpisodes() << std::endl;
    }
    if (option == 4) {
        std::cout << "You have chosen to watch " << name << std::endl <<"Please wait a moment while we generate an episode" << std::endl;
        std::cout << "......................" << std::endl;
        std::cout << getEpisodes() << std::endl;
    }
}

    int main() {
    srand( static_cast<unsigned int>(time(NULL)));
    
        
        std::cout << "1. Friends" << std::endl;
        std::cout << "2. The Office" << std::endl;
        std::cout << "3. Boy Meets World" << std::endl;
        std::cout << "4. Seinfeld" << std::endl;
        TvShows Netflix = TvShows();
        Netflix.setShow("Friends");
        Netflix.getEpisodes();
        Netflix.printInfo();
        Netflix.setShow("The Office");
        Netflix.getEpisodes();
        Netflix.printInfo();
        Netflix.setShow("Boy Meets World");
        Netflix.getEpisodes();
        Netflix.printInfo();
        Netflix.setShow("Seinfeld");
        Netflix.getEpisodes();
        Netflix.printInfo();
    
    return 0;
}
