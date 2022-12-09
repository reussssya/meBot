#include "meBot.h"


Cmebot::Cmebot()
{
    initWordDatabase();
}
Cmebot::~Cmebot()
{
    receive->close();
}


void Cmebot::writeWordDatabase(std::string word)
{
    // ...
}
void Cmebot::regexHandle()
{
    cout << "RegexHandle\n";
    std::regex reg("([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})");
    std::cmatch cm;

    std::string buffer = "hello : world";
    // parse from db.meb and put in std::string buffer;

    cout << "started\n";
    if(std::regex_match(buffer.c_str(), cm, reg))
    {
        cout << "in";
        cout << cm[1];
    }
    // ... CONTINUE FAST
}

void Cmebot::initWordDatabase()
{
    /*std::ofstream write("db.meb");
    if(write.is_open())
    {
        write << "opened123123123" << endl;
    }*/
    receive->open("db.meb");

    /*#ifdef DEBUG_MODE
    std::string logbuffer;
    if(receive->is_open()) *receive >> logbuffer;
    else logbuffer += "Can't open database!";
    cout << logbuffer << endl;
    #endif DEBUG_MODE*/
}


void Cmebot::onMessageProcessing(std::string msg)
{
    
    if(msg.find("Hey") != std::string::npos) return Cmebot::onMessageSending("Hello!");
}

void Cmebot::onMessageSending(std::string msg)
{
    cout << msg << endl;
}