#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <cmath>
#include <array>
#include <sstream>
constexpr int size = 1000;
using array2d = std::array<std::array<int, size>, size>;
array2d array = {};

void printarray()
{
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream file("input.txt");

    int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
    char temp;
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        ss >> x1 >> temp >> y1 >> temp >> temp >> x2 >> temp >> y2;
        
        if (x1 != x2 && y1==y2)
        {
            auto bigger = x1 > x2 ? x1 : x2;
            auto lower = x1 > x2 ? x2 : x1;
            for (int i = lower; i <= bigger; i++)
            {
                array[y1][i]++;
            }
        }
        else if(x1 == x2 && y1!=y2)
        {
            auto bigger = y1 > y2 ? y1 : y2;
            auto lower = y1 > y2 ? y2 : y1;
            for (int i = lower; i <= bigger; i++)
            {
                array[i][x1]++;
            }
        }else if(abs(x1 - x2) == abs(y1 - y2))
        {
            auto diff = abs(x1 - x2);
            auto lower_x = x1 > x2 ? x2 : x1;
            auto bigger_x = x1 > x2 ? x1 : x2;
            auto lower_y = y1 > y2 ? y2 : y1;
            auto bigger_y = y1 > y2 ? y1 : y2;

            for (int i = 0; i <= diff; i++)
            {
                if(y2 > y1 && x2 > x1)
                {
                    array[lower_y+i][lower_x+i]++;
                }else if(y2 > y1 && x2 < x1)
                {
                    array[lower_y+i][bigger_x-i]++;
                }else if(y2 < y1 && x2 < x1)
                {
                    array[bigger_y-i][bigger_x-i]++;
                }else{
                    array[bigger_y-i][lower_x+i]++;
                }
                
            }

        }
    }

    int sum = 0;
    //printarray();
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(array[i][j] > 1)
            {
                sum++;
            }
        }
    }
    std::cout << sum;
}