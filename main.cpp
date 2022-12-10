#include "integrations/meBot.h"


int main()
{
    setlocale(LC_ALL, ".1251");

    std::string answer;

    cin >> answer;

    std::ifstream receive("db.meb");
    if(receive.is_open())
    {
        std::regex reg("([\\w\\s]{0,1024})" "(:)" "([\\w\\s]{0,1024})");
        std::cmatch cm;
        std::string buffer;
        while(getline(receive, buffer))
        {
            if(std::regex_match(buffer.c_str(), cm, reg))
            {
                std::string thequestion = cm[1];
                std::string theanswer = cm[3];
                std::transform(answer.begin(), answer.end(),answer.begin(), ::toupper); // to UPPERCASE the answer

                if(thequestion.find(answer) != std::string::npos)
                {
                    cout << theanswer;
                }
            }
        }
        // PERFECTLY WORKS)
    }
    

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