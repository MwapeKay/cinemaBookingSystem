#include <iostream>
#include "Movies.h"
#include "Bookings.h"

using namespace std;

int main() {
    vector<Movies> theMovieCollection;
    int choice = 0;

    while (choice != 5) {
        cout << "------------------------" << endl;
        cout << "| Cinema Booking System|" << endl;
        cout << "------------------------" << endl;
        cout << "1. Display Movies" << endl;
        cout << "2. Add Movies" << endl;
        cout << "3. Booking" << endl;
        cout << "4. Display Bookings" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (choice) {
            case 1: {
                Movies movie;
                movie.readMovieFile();
                movie.displayMovieDetails();
                break;
            }
            case 2: {
                Movies movie;
                movie.addMovies();
                movie.writeMovieFile();
                movie.displayMovieDetails();
                break;
            }
            case 3: {
                Bookings booking;
                booking.createBooking(theMovieCollection);
                booking.displayBookingDetails();
                booking.saveBookingToFile();
                break;
            }
            case 4: {
                Bookings bookings;
                bookings.displayBookingDetails();
                break;
            }
            case 5: {
                cout << "Exiting the program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
