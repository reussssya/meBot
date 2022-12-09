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

void Cmebot::initWordDatabase()
{
    /*std::ofstream write("db.meb");
    if(write.is_open())
    {
        write << "opened123123123" << endl;
    }*/
    receive->open("db.meb");
}

void Cmebot::onMessageProcessing(std::string msg)
{
    
    std::regex reg("([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})");
    std::cmatch cm;

    std::string buffer;
    // parse from db.meb and put in std::string buffer;


    if(std::regex_match(buffer.c_str(), cm, reg))
    {
        // for loop for pieces of db.meb's strings;
    }
    if(msg.find("Hey") != std::string::npos) return Cmebot::onMessageSending("Hello!");
}

void Cmebot::onMessageSending(std::string msg)
{
    
    cout << msg << endl;
}