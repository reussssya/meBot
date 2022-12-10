#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <regex>
#include <conio.h>
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
    void regexHandle(std::string msg);
    int getDictionarySize();

    //([\\w\\s]+)(:)([\\w\\s]+)
    // "([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})" - works for regex
private:
    unsigned dictionary_size = 2;
    //std::string databaseName = "db.meb";
};



namespace mebot
{
    std::ifstream *receive = new std::ifstream("db.meb");
    std::string buf;
    void initWordDatabase()
    {
        cout << "Opening db.meb\n";
        if(mebot::receive->is_open())
        {
            cout << "Opened!\n";
        }
    }
    void onMessageProcessing(std::string msg = "got this")
    {
        std::regex reg("([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})");
        std::cmatch cm;
        cout << "check if open\n";
        mebot::receive->clear();
        if(mebot::receive->is_open())
        {
            cout << "is_open = true\n";
            if(std::regex_match(msg.c_str(), cm, reg)) // cm[1] = got this
            {
                cout << "Loop while !receive->eof()\n";

                while(!mebot::receive->eof()) // пока не дойдем до конца
                {//getline(msg, 1024)
                    cout << "here we go\n";
                    std::string sSearch;
                    //getline(*receive, sSearch);
                    if(sSearch.find(cm[1]) != std::string::npos)//!= std::string::npos) // got this
                    {
                        cout << "can we return?\n";
                        return Cmebot::onMessageSending("Hello!");
                    }
                }
            }
        }   
        else
        {
            cout << "Can't open the file\n";
        }
    }
    
};