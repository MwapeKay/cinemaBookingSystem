//
// Created by Mkala on 02/07/2023.
//

#ifndef UNTITLED13_SCREEN_H
#define UNTITLED13_SCREEN_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Movies.h"

using namespace std;

class Screen {

    int screenId;
    string movie;
    int maxCapacity;
    string facilities;
    vector <Screen> theScreening;
public:
    Screen();
    Screen(int, string, int, string);

    //get methods
    int getScreenId();
    string getMovie() ;
    int getMaxCapacity() ;
    string getFacilities();
    Screen* getScreen();
    int getScreenSize();


    //set methods
    void setScreenId(int );
    void setMovie(string);
    void setMaxCapacity(int );
    void setFacilities(string );
    void setMovieInScreen(Screen tempSscreen);


    void addToScreen();
    void displayScreen();
    void saveScreenToFile();
    void readScreenFile();

};




#endif //UNTITLED13_SCREEN_H
