#include "meBot.h"


Cmebot::Cmebot()
{

}
Cmebot::~Cmebot()
{
    //mebot::receive->close();
}


void Cmebot::writeWordDatabase(std::string word)
{
    // need to make
}


int Cmebot::getDictionarySize() 
{
    return dictionary_size;
}

void Cmebot::onMessageProcessing(std::string msg,std::ifstream &db)
{
    std::regex reg("([\\w\\s:]{0,1024})" "(:)" "([\\w\\s:]{0,1024})");
    std::cmatch cm;
    std::string buffer;
    /*getline(db, buffer)*/
    while(std::getline(db, buffer))
    {
        if(std::regex_match(buffer.c_str(), cm, reg))
        {
            std::string thequestion = cm[1];
            std::string theanswer = cm[3];
            std::transform(msg.begin(), msg.end(),msg.begin(), ::toupper); // to UPPERCASE the answer

            if(thequestion.find(msg) != std::string::npos)
                return Cmebot::onMessageSending(theanswer);
        }
    }
}

void Cmebot::onMessageSending(std::string msg)
{
    
    cout << msg << endl;
}

































































































































































