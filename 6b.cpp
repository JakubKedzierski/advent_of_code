#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <cmath>
#include <array>
#include <sstream>

std::vector<int> fishes;

void printarray()
{
    std::cout << std::endl;
    for (int i = 0; i < fishes.size(); i++)
    {
        std::cout << fishes[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::ifstream file("input.txt");

    int number = -1;
    char temp;
    while (true)
    {
        file >> number;
        fishes.push_back(number);
        if (file.peek() == EOF)
        {
            break;
        }
        file >> temp;
    }
    constexpr int days = 2;
    int sum = 0;
    int fish_counter = 0;
    for (int j = 0; j < fishes.size(); j++)
    {
        sum += (days - fishes[j]) / 6;
    }
    std::cout << sum + fishes.size();
}