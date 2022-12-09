#include "meBot.h"


Cmebot::Cmebot()
{
    //initWordDatabase();
}

Cmebot::~Cmebot()
{
    //mebot::receive->close();
}


void Cmebot::writeWordDatabase(std::string word)
{
    // ...
}

void Cmebot::initWordDatabase()
{
    cout << "Opening db.meb\n";
    if(mebot::receive->is_open())
    {
        cout << "Opened!\n";
    }
        
}

int Cmebot::getDictionarySize() 
{
    return dictionary_size;
}

void Cmebot::onMessageProcessing(std::string msg = "got this")
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

void Cmebot::onMessageSending(std::string msg)
{
    cout << msg << endl;
}