#include "integrations/meBot.h"


int main()
{
    setlocale(LC_ALL, ".1251");



    mebot::initWordDatabase();


    std::string buffer;
    cin >> buffer;

    mebot::onMessageProcessing(buffer);



    /*while(true)
    {
        cin >> buffer;

        if(buffer.size() != 0)
        {
            mebot.onMessageProcessing(buffer);
        }
    }*/


    return 0;
}