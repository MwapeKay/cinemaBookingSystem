//
// Created by Mkala on 02/07/2023.
//
#include "Movies.h"
#include "Screen.h"
Screen::Screen() {
    screenId = 0;
    movie = "";
    maxCapacity = 0;
    facilities = "";

}

Screen::Screen(int tempId, string tempMovie, int tempCapacity, string tempFacilities) {
    screenId = tempId;
    movie = tempMovie;
    maxCapacity = tempCapacity;
    facilities = tempFacilities;
}

int Screen::getScreenId() {
    return screenId;
}

string Screen::getMovie() {
    return movie;
}

int Screen::getMaxCapacity() {
    return maxCapacity;
}

string Screen::getFacilities() {
    return facilities;
}

void Screen::setScreenId(int tempId) {
    screenId = tempId;
}

void Screen::setMovie(string tempMovie) {
    movie = tempMovie;
}

void Screen::setMaxCapacity(int tempCapacity) {
    maxCapacity = tempCapacity;
}

void Screen::setFacilities(string tempFacilities) {
    facilities = tempFacilities;
}

void Screen::setMovieInScreen(Screen tempSscreen) {
    theScreening.push_back(tempSscreen);
}

void Screen::displayScreen() {
    Screen *screen = theScreening.data();
    for (int i = 0; i < theScreening.size(); i++) {
        cout << "Movie Details:" << endl;
        cout << "-----------------------------" << endl;
        cout << "Screen ID: " << screen->getScreenId() << endl;
        cout << "Movie: " << screen->getMovie() << endl;
        cout << "Max Capacity: " << screen->maxCapacity << endl;
        cout << "Facilities: " << screen->facilities << endl;
        screen++;

    }


}
void Screen::readScreenFile(){
    string tempLine, tempWord, parseMovie, parseFacilities;
    int parseScreenId;
    int parseMaxCapacity;

    fstream fsRead;

    fsRead.open("screen.txt");
    if (fsRead.is_open()){
        cout << "File is ready to be read! " << endl;
        while (getline(fsRead, tempLine)) {
            stringstream ss(tempLine);
            int counter = 0;

            while(getline(ss >> ws, tempWord, ',')) {
                if (counter == 0) {
                    parseScreenId = stoi(tempWord);
                }
                if (counter == 1) {
                    parseMovie = tempWord;
                }
                if (counter == 2) {
                    parseFacilities = tempWord;
                }
                if (counter == 3) {
                    parseMaxCapacity = stoi(tempWord);
                }

                counter++;
            }
            Screen* superInstance = new Screen(parseScreenId, parseMovie, parseMaxCapacity, parseFacilities);
            setMovieInScreen(*superInstance);
        }
        fsRead.close();
    }
    else{
        cout <<"Cannot read file"<< endl;
    }

}
void Screen::addToScreen() {
    int additions;

    cout << "How many screens do you want to add? " << endl;
    while (!(cin >> additions)) {
        cout << "Incorrect input. Please enter a valid integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < additions; i++) {
        int tempScreenId;
        string tempMovie;
        int tempMaxCapacity;
        string tempFacilities;

        cout << "Screen ID: ";
        cin >> tempScreenId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Movie currently being shown: ";
        getline(cin >> ws, tempMovie);

        cout << "Maximum seating capacity: ";
        cin >> tempMaxCapacity;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Screen facilities: ";
        getline(cin >> ws, tempFacilities);

        Screen* tempScreen = new Screen(tempScreenId, tempMovie, tempMaxCapacity, tempFacilities);
        setMovieInScreen(*tempScreen);
    }
}
