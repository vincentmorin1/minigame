/*
 * Logger.h
 * 
 * @author Chocorean
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <time.h>

#include "CastUtils.h"

using namespace std;

enum LogState {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Logger 
{
  public:
    Logger() {}
    Logger(LogState st)
    {
        state = st;
        /* Getting time */
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);

        string day   = intToStr(aTime->tm_mday);
        string month = intToStr(aTime->tm_mon + 1); // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
        string year  = intToStr(aTime->tm_year + 1900); // Year is # years since 1900
        string hour  = intToStr(aTime->tm_hour);
        string min   = intToStr(aTime->tm_min);
        string sec   = intToStr(aTime->tm_sec);
        /* Printing */
        operator << ("["+getLabel(state)+"]["+year+"-"+day+"-"+month+"@"+hour+":"+min+":"+sec+"] ");
    }
    ~Logger() {
        if(isOpened)
        {
            cout << endl;
        }
        isOpened = false;
    }
    //
    template<class T>
    Logger &operator<<(const T &msg)
    {
        if(state >= configLevel)
        {
            cout << msg;
            isOpened = true;
        }
        return *this;
    }
  private:
    /* attributes */
    bool isOpened = false;
    LogState state = DEBUG;
    LogState configLevel = DEBUG; // will have to be dynamicly set
    /* methods */
    inline string getLabel(LogState type) {
        string label;
        switch(type) {
            case DEBUG: label = "DEBUG"; break;
            case INFO:  label = "INFO "; break;
            case WARN:  label = "WARN "; break;
            case ERROR: label = "ERROR"; break;
        }
        return label;
    }
};
#endif