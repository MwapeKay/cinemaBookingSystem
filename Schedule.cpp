//
// Created by Mkala on 02/07/2023.
//

#include "Schedule.h"
void Schedule::addScheduleEntry(int screenId, int movieId,  string& startTime, string& endTime) {
    ScheduleEntry entry;
    entry.screenId = screenId;
    entry.movieId = movieId;
    entry.startTime = startTime;
    entry.endTime = endTime;

    weeklySchedule.push_back(entry);


    string scheduleEntry = "Screen ID: " + to_string(screenId) + "\n";
    scheduleEntry += "Movie ID: " + to_string(movieId) + "\n";
    scheduleEntry += "Start Time: " + startTime + "\n";
    scheduleEntry += "End Time: " + endTime + "\n";
    scheduleEntry += "---------------------\n";

    cout << scheduleEntry;
}

void Schedule::displayWeeklySchedule() {
    cout << "Weekly Schedule:" << endl;
    cout << "-----------------------------" << endl;

    for (const ScheduleEntry& entry : weeklySchedule) {
        cout << "Screen ID: " << entry.screenId << endl;
        cout << "Movie ID: " << entry.movieId << endl;
        cout << "Start Time: " << entry.startTime << endl;
        cout << "End Time: " << entry.endTime << endl;
        cout << "-----------------------------" << endl;
    }
}

void Schedule::readScheduleFile() {
    string tempLine, tempWord, parseStartTime, parseEndTime;
    int parseScreenId, parseMovieId;

    fstream fsRead;

    fsRead.open("schedules.txt");
    if (fsRead.is_open()) {
        cout << "File is ready to be read!" << endl;
        while (getline(fsRead, tempLine)) {
            stringstream ss(tempLine);
            int counter = 0;

            while (getline(ss >> ws, tempWord, ',')) {
                if (counter == 0) {
                    parseScreenId = stoi(tempWord);
                }if (counter == 1) {
                    parseMovieId = stoi(tempWord);
                }if (counter == 2) {
                    parseStartTime = tempWord;
                } if (counter == 3) {
                    parseEndTime = tempWord;
                }

                counter++;
            }

            addScheduleEntry(parseScreenId, parseMovieId, parseStartTime, parseEndTime);
        }
        fsRead.close();
    } else {
        cout << "Cannot read file" << endl;
    }
}

void Schedule::writeScheduleFile() {
    fstream writeFile;
    writeFile.open("schedules.txt", ios::app);
    if (writeFile.is_open()) {
        cout << "File is ready to be written to!" << endl;
        for (const ScheduleEntry& entry : weeklySchedule) {
            writeFile << entry.screenId << "," << entry.movieId << "," << entry.startTime << "," << entry.endTime << endl;
        }
        writeFile.close();
    }
}
