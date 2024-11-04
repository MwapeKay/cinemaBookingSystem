//
// Created by Mkala on 02/07/2023.
//

#ifndef UNTITLED13_SCHEDULE_H
#define UNTITLED13_SCHEDULE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Screen.h"
#include "Movies.h"

class Schedule {
private:
    struct ScheduleEntry {
        int screenId;
        int movieId;
        string startTime;
        string endTime;
    };

    vector<ScheduleEntry> weeklySchedule;

public:
    void addScheduleEntry(int screenId, int movieId, string& startTime, string& endTime);
    void displayWeeklySchedule();
    void readScheduleFile();
    void writeScheduleFile();
};


#endif //UNTITLED13_SCHEDULE_H
