#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>

int main()
{
    std::ifstream file("input.txt");

    std::string temp;
    int value = 0;
    int hoz=0;
    int depth=0;

    while (file >> temp >> value)
    {
        if(temp.find("forward")!=std::string::npos)
        {
            hoz+=value;
        }
        
        if(temp.find("down")!=std::string::npos)
        {
            depth+=value;
        }
        
        if(temp.find("up")!=std::string::npos)
        {
            depth-=value;
        }
    }

    std::cout << depth*hoz;
}