#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <conio.h>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;

class Cmebot
{
public:
    Cmebot();
    Cmebot(bool initDB);
    ~Cmebot();

    void onMessageProcessing(std::string msg, std::ifstream &db);
    void onMessageSending(std::string msg);
    void writeWordDatabase(std::string word);
    void regexHandle(std::string msg);
    int getDictionarySize();
    // "([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})" - works for regex
private:
    unsigned dictionary_size = 2;
    //std::string databaseName = "db.meb";
};
