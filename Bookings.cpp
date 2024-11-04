//
// Created by Mkala on 02/07/2023.
//

#include "Bookings.h"

Bookings::Bookings() {
    bookingId = 0;
    movieId = 0;
    numberOfTickets = 0;
    movieChoice = "";
    date = "";
    time = "";
    totalCost = 0.0;
}
int Bookings::getBookingId() {
    return bookingId;
}

int Bookings::getMovieId() {
    return movieId;
}

int Bookings::getNumberOfTickets() {
    return numberOfTickets;
}

string Bookings::getMovieChoice() {
    return movieChoice;
}

Bookings* Bookings::getBookings() {
    return theBookingM.data();
}

int Bookings::getBookingSize() {
    return theBookingM.size();
}

string Bookings::getDate() {
    return date;
}

string Bookings::getTime() {
    return time;
}

float Bookings::getTotalCost() {
    return totalCost;
}

void Bookings::setBookingId(int tempBookingId) {
    bookingId = tempBookingId;
}

void Bookings::setMovieId(int tempMovieId) {
    movieId = tempMovieId;
}

void Bookings::setNumberOfTickets(int tempNumberOfTickets) {
    numberOfTickets = tempNumberOfTickets;
}

void Bookings::setMovieChoice(string tempMovieChoice) {
    movieChoice = tempMovieChoice;
}

void Bookings::setDate(string tempDate) {
    date = tempDate;
}

void Bookings::setTime(string tempTime) {
    time = tempTime;
}

void Bookings::setTotalCost(float tempTotalCost) {
    totalCost = tempTotalCost;
}

void Bookings::createBooking(vector<Movies> theMovieCollection) {
    int tempBookingId;
    int tempMovieId;
    int tempNumberOfTickets;
    string tempDate;
    string tempTime;
    float tempTotalCost;

    cout << "Booking ID: " << endl;
    cin >> tempBookingId;
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Movie ID: "<< endl;
    cin >> tempMovieId;
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Number of Tickets: ";
    cin >> tempNumberOfTickets;
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Date (DD-MM-YYYY): ";
    getline(cin >> ws, tempDate);
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Time (HH:MM): ";
    cin >> tempTime;
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    float ticketPrice = 5;
    tempTotalCost = tempNumberOfTickets * ticketPrice;


    setBookingId(tempBookingId);
    setMovieId(tempMovieId);
    setNumberOfTickets(tempNumberOfTickets);
    setDate(tempDate);
    setTime(tempTime);
    setTotalCost(tempTotalCost);

}
void Bookings::displayBookingDetails() {
    Bookings* bookings = theBookingM.data();
    for(int i = 0; i < theBookingM.size(); i++) {
        cout << "Booking Details:" << endl;
        cout << "-----------------------" << endl;
        cout << "Booking ID: " << bookings->getBookingId() << endl;
        cout << "Movie ID: " << bookings->getMovieId() << endl;
        cout << "Number of Tickets: " << bookings->getNumberOfTickets() << endl;
        cout << "Movie Choice: " << bookings->getMovieChoice() << endl;
        cout << "Date: " << bookings->getDate() << endl;
        cout << "Time: " << bookings->getTime() << endl;
        cout << "Total Cost: £" << bookings->getTotalCost() << endl;
        cout << endl;
        bookings++;
    }
}
void Bookings::saveBookingToFile() {
    ofstream file("bookings.txt", ios::app);
    if (file.is_open()) {
        file << getBookingId() << "," << getMovieId() << "," << getNumberOfTickets() << ","
             << getMovieChoice() << "," << getDate() << "," << getTime() << "," << getTotalCost() << endl;
        file.close();
        cout << "Booking saved to file." << endl;
    } else {
        cout << "Unable to open file for saving the booking." << endl;
    }
}