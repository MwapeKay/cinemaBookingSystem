//
// Created by Mkala on 02/07/2023.
//

#ifndef UNTITLED13_TICKET_H
#define UNTITLED13_TICKET_H

#include <iostream>
using namespace std;

class ticket {
    int ticketNumber;
    string movieTitle;
    string seatType;
    int numberOfTickets;

public:
    ticket();
    ticket(int number,  string& title, string& seat, int numTickets);

    // Get methods
    int getTicketNumber();
    string getMovieTitle();
    string getSeatType();
    int getNumberOfTickets();

    // Set methods
    void setTicketNumber(int number);
    void setMovieTitle(string& title);
    void setSeatType(string& seat);
    void setNumberOfTickets(int numTickets);

    // Display ticket details
    void displayTicket();
};


#endif //UNTITLED13_TICKET_H
