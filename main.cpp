#include "integrations/meBot.h"


int main()
{
    setlocale(LC_ALL, ".1251");
<<<<<<< HEAD



    mebot::initWordDatabase();


    std::string buffer;
    cin >> buffer;

    mebot::onMessageProcessing(buffer);


=======
    std::string answer;
    //Cmebot mebot;
    cin >> answer;

    std::ifstream receive("db.meb");
    if(receive.is_open())
    {
        //cout << "opened\n";
        std::regex reg("([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})");
        std::cmatch cm;
        std::string buffer;
        while(getline(receive, buffer))
        {
            if(std::regex_match(buffer.c_str(), cm, reg))
            {
                if(answer.find(cm[1]) != std::string::npos)
                {
                    cout << cm[3];
                }

            }
        }
        // PERFECTLY WORKS)

    }
    
>>>>>>> tmp

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