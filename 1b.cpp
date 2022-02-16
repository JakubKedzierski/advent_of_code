#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream file("input.txt");

    int temp = 0;

    int counter = 0;
    std::vector<int> vec;
    while (file >> temp)
    {
        vec.push_back(temp);
    }
    for (int i = 3; i < vec.size(); i++)
    {
        if (vec[i] > vec[i - 3])
        {
            counter++;
        }
    }
    std::cout << counter;
}