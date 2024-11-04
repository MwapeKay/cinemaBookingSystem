//
// Created by Mkala on 02/07/2023.
//

#ifndef UNTITLED13_BOOKINGS_H
#define UNTITLED13_BOOKINGS_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Movies.h"

using namespace std;

class Bookings {
    int bookingId;
    int movieId;
    int numberOfTickets;
    string movieChoice;
    string date;
    string time;
    float totalCost;
    vector <Bookings> theBookingM ;

public:
    Bookings();
    Bookings(int, int, int, string, string, string, float);

    // Get Methods
    int getBookingId();
    int getMovieId();
    int getNumberOfTickets();
    string getMovieChoice();
    string getDate();
    string getTime();
    float getTotalCost();
    Bookings* getBookings();
    int getBookingSize();


    //Set Methods
    void setBookingId(int);
    void setMovieId(int);
    void setNumberOfTickets(int);
    void setMovieChoice(string);
    void setDate(string);
    void setTime(string);
    void setTotalCost(float);

    //Methods
    void createBooking( vector <Movies> theMovieCollection);
    void displayBookingDetails();
    void saveBookingToFile();












};


#endif //UNTITLED13_BOOKINGS_H
