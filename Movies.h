//
// Created by Mkala on 02/07/2023.
//

#ifndef UNTITLED13_MOVIES_H
#define UNTITLED13_MOVIES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

class Movies {
    //Naturally Private
    int movieId;
    string title;
    string description;
    string genre;
    int runningTime;
    string mainStar;
    string filmDistributor;
    string releaseDate;
    vector <Movies> theMovieCollection;
    vector<string> schedule;


public:
    //Constructors
    Movies();
    Movies(int, string, string, string, int, string, string, string);

    //Get methods
    int getMovieId();
    string getTitle();
    string getDescription();
    string getGenre();
    int getRunningTime();
    string getMainStar() ;
    string getFilmDistributor();
    string getReleaseDate();
    Movies* getMovies();
    int getMovieSize();


    //Set methods
    void setMovieId(int);
    void setTitle(string);
    void setDescription(string);
    void setGenre(string);
    void setRunningTime(int);
    void setMainStar(string) ;
    void setFilmDistributor(string);
    void setReleaseDate(string);
    void displayMovieDetails();
    void setMovieCard(Movies tempMovies);

    //Methods
    void readMovieFile();
    void writeMovieFile();
    void addMovies();


};


#endif //UNTITLED13_MOVIES_H
