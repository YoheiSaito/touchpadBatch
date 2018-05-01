#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

int main(void)
{
    std::string buffer;
    int padmode = -1;
   
    std::ifstream state("dev-state.log");
  
    while (state && std::getline(state, buffer))
    {
        std::cout << buffer << std::endl;
        for (int i = 0; i < buffer.size(); i++)
        {
            std::string tmp = buffer.substr(i, 7);
            if (tmp == "disable")
            {
                padmode = 0;
                break;
            }
            if (tmp == "running")
            {
                padmode = 1;
                break;
            }
        }
    }
    state.close();
    if(padmode == 1)
        system("sheduleDisableTouchPad.bat");
    else if (padmode == 0)
        system("sheduleEnableTouchPad.bat");
    else{
        std::cout <<"There are no touchpad" << std::endl;
        system("pause");
    } 
        
}