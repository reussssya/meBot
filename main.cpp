#include "integrations/meBot.h"


int main()
{
    setlocale(LC_ALL, ".1251");
    bool bLoop = true;
    Cmebot bot;
    std::string answer;

    std::ifstream *receiver = new std::ifstream("db.meb");
    
    if(bLoop)
    {
        while(answer != "terminate")
        {
            answer.clear();
            std::getline(std::cin, answer);
            if(answer.size() != 0)
            {
                bot.onMessageProcessing(answer,*receiver);
            }
        }
    }
    else
    {
        std::getline(std::cin, answer);
        if(answer == "terminate") return 1;
        else
        {
            if(answer.size() != 0)
            {
                bot.onMessageProcessing(answer, *receiver);
                answer = "";
            }
        }
    }
    


    return 0;
}