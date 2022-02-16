#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <cmath>
#include <array>
#include <sstream>

std::vector<int> start_position;

int main()
{
    std::ifstream file("input.txt");

    int number = -1;
    char temp;
    while (true)
    {
        file >> number;
        start_position.push_back(number);
        if (file.peek() == EOF)
        {
            break;
        }
        file >> temp;
    }

    auto max = *(std::max_element(start_position.begin(), start_position.end()))*2;

    std::vector<int> results;
    for(int i=0;i<max;i++)
    {
        int fuel = 0;
        for(auto &elem:start_position)
        {
            fuel += abs(i-elem);
        }
        results.push_back(fuel);
    }
    std::cout << *(std::min_element(results.begin(),results.end()));
    
}