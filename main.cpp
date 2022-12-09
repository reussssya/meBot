#include "integrations/meBot.h"


int main()
{
    setlocale(LC_ALL, ".1251");
    std::string buffer = "hello : world";
    Cmebot mebot();

    std::regex reg("([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})");
    std::cmatch cm;

    // parse from db.meb and put in std::string buffer;

    if(std::regex_match(buffer.c_str(), cm, reg))
    {
        cout << cm[1];
    }
    /*std::ifstream receive("db.meb");


    if(receive.is_open())
    {
        cout << "opened";
        receive >> buffer;
        cout << buffer;
    }*/
    

    /*while(true)
    {
        cin >> buffer;

        if(buffer.size() != 0)
        {
            mebot.onMessageProcessing(buffer.c_str());
        }
    }*/


    return 0;
}