#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <regex>

#pragma warning(disable : 711)

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
    void regexHandle();
    //([\\w\\s]+)(:)([\\w\\s]+)
    // "([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})" - works for regex
private:
    std::string db = "db.meb";
    std::ifstream *receive;
};