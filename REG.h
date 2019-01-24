//
//  REG.h
//  REG
//
//  Created by Nkechi Iregbulem on 1/23/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#ifndef REG_h
#define REG_h
#include <iostream>
#include <string>
#include <vector>


class TvShows {
private:
    std::string name;
    std::string show;
    std::string episode[10] = {"Season1:Episode1", "Season2:Episode2", "Season 3:Episode3", "Season 4:Episode4", "Season5:Episode 2", "Season1: Episode 3", "Season 2:Episode 12", "Season 3:Episode 8", "Season 4: Episode 10", "Season 5: Episode 15"};
    int randomIndex = 0;
    
public:
    TvShows();
    TvShows(std::string ShowName);
    std::vector<std::string> shows;   //show will = shows
    void setShow(std::string tvShow);   //tvShow will = show
    void setEpisodes(std::string episodes);     // name will = episodes
    std::string getShow();
    std::string getEpisodes();
    void printInfo();
};

#endif /* REG_h */
