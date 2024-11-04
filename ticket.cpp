//
// Created by Mkala on 02/07/2023.
//

#include "Ticket.h"
#include <iostream>

using namespace std;


ticket::ticket() {
    ticketNumber = 0;
    numberOfTickets = 0;
}
ticket::ticket(int number, string& title,string& seat, int count) {
    ticketNumber = number;
    movieTitle = title;
    seatType = seat;
    numberOfTickets = count;
}

int ticket::getTicketNumber() {
    return ticketNumber;
}

string ticket::getMovieTitle() {
    return movieTitle;
}

string ticket::getSeatType() {
    return seatType;
}

int ticket::getNumberOfTickets() {
    return numberOfTickets;
}

void ticket::setTicketNumber(int number) {
    ticketNumber = number;
}

void ticket::setMovieTitle(string& title) {
    movieTitle = title;
}

void ticket::setSeatType( string& seat) {
    seatType = seat;
}

void ticket::setNumberOfTickets(int numTickets) {
    numberOfTickets = numTickets;
}

void ticket::displayTicket() {
    cout << "Ticket Number: " << ticketNumber << endl;
    cout << "Movie Title: " << movieTitle << endl;
    cout << "Seat Type: " << seatType << endl;
    cout << "Number of Tickets: " << numberOfTickets << endl;
}

