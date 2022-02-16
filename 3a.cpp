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
    std::string out;
    out.resize(12);
    std::vector<int> stats(12);

    int counter = 0;
    auto size = 12;
    while (file >> temp)
    {
        counter++;
        for (int i = 0; i < size; i++)
        {
            if (temp[i] == '0')
            {
                stats[i]++;
            }
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        if (stats[i] >= int(counter/2))
        {
            out[i] = '0';
        }else{
            out[i] = '1';
        }
    }
    std::cout << out;
}