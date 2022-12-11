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
        
}

int Cmebot::getDictionarySize() 
{
    return dictionary_size;
}
void Cmebot::onMessageProcessing(std::string msg)
{
    return Cmebot::onMessageSending("Hello!");
}

void Cmebot::onMessageSending(std::string msg)
{
    
    cout << msg << endl;
}

































































































































































