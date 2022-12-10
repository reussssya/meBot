#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

class Cmebot
{
public:
    Cmebot();
    ~Cmebot();

    void onMessageProcessing(std::string msg);
    void onMessageSending(std::string msg);
    void initWordDatabase();
    void writeWordDatabase(std::string word);
    void regexHandle(std::string msg);
    int getDictionarySize();

    //([\\w\\s]+)(:)([\\w\\s]+)
    // "([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})" - works for regex
private:
    unsigned dictionary_size = 2;
    //std::string databaseName = "db.meb";
};
