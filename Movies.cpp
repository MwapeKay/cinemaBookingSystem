//
// Created by Mkala on 02/07/2023.
//

#include "Movies.h"
Movies::Movies(){
    movieId = 0;
    title = "";
    description = "";
    genre = "";
    runningTime = 0;
    mainStar = "";
    filmDistributor = "";
    releaseDate = "";
}

Movies::Movies(int tempMovieId, string tempTitle, string tempDescription, string tempGenre, int tempRunningTime, string tempMainStar, string tempFilmDistributor, string tempReleaseDate) {
    movieId = tempMovieId;
    title = tempTitle;
    description = tempDescription;
    genre = tempGenre;
    runningTime = tempRunningTime;
    mainStar = tempMainStar;
    filmDistributor = tempFilmDistributor;
    releaseDate = tempReleaseDate;
}

Movies* Movies::getMovies() {
    return theMovieCollection.data();
}


int Movies::getMovieSize() {
    return theMovieCollection.size();
}

int Movies::getMovieId() {
    return movieId;
}

string Movies::getTitle() {
    return title;
}

string Movies::getDescription()  {
    return description;
}

string Movies::getGenre() {
    return genre;
}

int Movies::getRunningTime() {
    return runningTime;
}

string Movies:: getMainStar() {
    return mainStar;

}
string Movies::getFilmDistributor() {
    return filmDistributor;

}
string Movies::getReleaseDate() {
    return releaseDate;
}

void Movies::setMovieId(int tempMovieId) {
    movieId = tempMovieId;
}
void Movies::setTitle(string tempTitle) {
    title = tempTitle;
}

void Movies::setDescription(string tempDescription) {
    description = tempDescription;
}

void Movies::setGenre(string tempGenre) {
    genre = tempGenre;
}

void Movies::setRunningTime(int tempRunningTime) {
    runningTime = tempRunningTime;
}

void Movies::setMainStar(string tempMainStar) {
    mainStar = tempMainStar;
}

void Movies::setFilmDistributor(string tempFilmDistributor) {
    filmDistributor = tempFilmDistributor;
}

void Movies::setReleaseDate(string tempReleaseDate) {
    releaseDate = tempReleaseDate;
}

void Movies::setMovieCard(Movies tempMovies) {
    theMovieCollection.push_back(tempMovies);
}

void Movies::displayMovieDetails() {
    Movies* movies = theMovieCollection.data();
    for(int i = 0; i < theMovieCollection.size(); i++) {
        cout << "Movie Details:" << endl;
        cout << "-----------------------------" << endl;
        cout << "Movie ID: " << movies->getMovieId() << endl;
        cout << "Title: " << movies->getTitle() << endl;
        cout << "Description: " << movies->getDescription() << endl;
        cout << "Genre: " << movies->getGenre() << endl;
        cout << "Running Time: " << movies->getRunningTime() << " minutes" << endl;
        cout << "Main Star: " << movies->getMainStar() << endl;
        cout << "Film Distributor: " << movies->getFilmDistributor() << endl;
        cout << "Release Date: " << movies->getReleaseDate() << endl;
        movies ++;

    }
}

void Movies::readMovieFile(){
    string tempLine, tempWord, parseTitle, parseDescription, parseGenre, parseMainStar, parseDistributor, parseReleaseDate;
    int parseMovieId;
    int parseRunningTime;

    fstream fsRead;

    fsRead.open("movie.txt");
    if (fsRead.is_open()){
        cout << "File is ready to be read! " << endl;
        while (getline(fsRead, tempLine)) {
            stringstream ss(tempLine);
            int counter = 0;

            while(getline(ss >> ws, tempWord, ',')) {
                if (counter == 0) {
                    parseMovieId = stoi(tempWord);
                }
                if (counter == 1) {
                    parseTitle = tempWord;
                }
                if (counter == 2) {
                    parseDescription = tempWord;
                }
                if (counter == 3) {
                    parseGenre = tempWord;
                }
                if (counter == 4) {
                    parseRunningTime = stoi(tempWord);
                }
                if (counter == 5) {
                    parseMainStar = tempWord;
                }
                if (counter == 6) {
                    parseDistributor = tempWord;
                }
                if (counter == 7) {
                    parseReleaseDate = tempWord;
                }
                counter++;
            }
            Movies* superInstance = new Movies(parseMovieId,parseTitle, parseDescription, parseGenre, parseRunningTime, parseMainStar, parseDistributor, parseReleaseDate);
            setMovieCard(*superInstance);
        }
        fsRead.close();
    }
    else{
        cout <<"Cannot read file"<< endl;
    }

}
void Movies::addMovies() {
    int additions;
    bool validRunningTime = false;
    string tempTitle, tempDescription, tempGenre, tempMainStar, tempFilmDistributor, tempReleaseDate;
    int tempMovieId;
    int tempRunningTime;

    cout << "How many movies do you want to add? " << endl;
    while (!(cin >> additions)) {
        cout << "Incorrect, please type a valid integer" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining newline character after reading 'additions'

    for (int i = 0; i < additions; i++) {
        cout << "Movie ID: " << endl;
        cin >> tempMovieId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining newline character after reading 'tempMovieId'

        cout << "Name of Title: " << endl;
        getline(cin >> ws, tempTitle);
        cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Description of the Movie: " << endl;
        getline(cin >> ws, tempDescription);
        cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Genre of the Movie: " << endl;
        getline(cin >> ws, tempGenre);

        validRunningTime = false;
        while (!validRunningTime) {
            cout << "How long is the running time? " << endl;
            if (cin >> tempRunningTime) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                validRunningTime = true;
            } else {
                cout << "Invalid input. Please enter a valid integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Who is the Main Star? " << endl;
        getline(cin >> ws, tempMainStar);
        cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Which studio distributes the movie? " << endl;
        getline(cin >> ws, tempFilmDistributor);
        cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "When is the release date? " << endl;
        getline(cin >> ws, tempReleaseDate);
        cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Movies* tempMovies = new Movies(tempMovieId, tempTitle, tempDescription, tempGenre, tempRunningTime, tempMainStar, tempFilmDistributor, tempReleaseDate);
        setMovieCard(*tempMovies);
    }
}

void Movies::writeMovieFile() {
    fstream writeFile;
    writeFile.open("movie.txt",ios::app);
    if(writeFile.is_open()){
        cout << "File is ready to be written too!" << endl;
        int counter = getMovieSize();
        Movies* tempMovie = getMovies();
        for (int i = 0; i < counter; i++){
            writeFile << tempMovie->getMovieId() << "," << tempMovie->getTitle() << "," << tempMovie->getDescription() << "," << tempMovie->getGenre() << "," << tempMovie->getRunningTime() << "," << tempMovie->getMainStar() << "," << tempMovie->getFilmDistributor() << "," << tempMovie->getReleaseDate() << endl;
            tempMovie ++;
        }
        writeFile.close();
    }

}