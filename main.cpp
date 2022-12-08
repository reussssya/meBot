#include "integrations/meBot.h"


int main(int argc, char** argv)
{
    setlocale(LC_ALL, ".1251");
    std::string buffer;
    Cmebot mebot;

    std::ifstream receive("db.meb");
    if(receive.is_open())
    {
        cout << "opened";
        receive >> buffer;
        cout << buffer;
    }
    

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