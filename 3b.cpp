#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <cmath>

int main()
{
    std::ifstream file("input.txt");

    std::string temp;
    std::vector<std::string> vec1, vec2;
    std::vector<std::string> tempvec1;
    std::vector<std::string> tempvec2;

    while (file >> temp)
    {
        vec1.push_back(temp);
    }

    vec2.resize(vec1.size());
    std::copy(vec1.begin(), vec1.end(), vec2.begin());
    int bit = 0;

    //oxygen generator rating
    int counter = 0;
    char bit_num = ' ';
    while (true)
    {
        counter = 0;
        for (int i = 0; i < vec1.size(); i++)
        {
            if (vec1[i][bit] == '1')
            {
                counter++;
            }
        }
        auto siz = vec1.size();
        auto half = float(vec1.size()) / 2;
        if (counter >= half)
        {
            bit_num = '1';
        }
        else
        {
            bit_num = '0';
        }

        auto it = vec1.erase(
            std::remove_if(vec1.begin(), vec1.end(), [&bit_num, &bit](std::string s)
                           { return s[bit] != bit_num; }),
            vec1.end());

        if (vec1.size() == 1)
        {
            break;
        }

        bit++;

    }
    std::cout << vec1[0] << std::endl;

    bit = 0;
    while (true) // co scrubber
    {
        counter = 0;
        for (int i = 0; i < vec2.size(); i++)
        {
            if (vec2[i][bit] == '1')
            {
                counter++;
            }
        }
        auto siz = vec2.size();
        auto half = float(vec2.size()) / 2;
        if (counter >= half)
        {
            bit_num = '1'; // more 1
        }
        else
        {
            bit_num = '0'; // more 0
        }

        auto it = vec2.erase(
            std::remove_if(vec2.begin(), vec2.end(), [&bit_num, &bit](std::string s)
                           { return s[bit] == bit_num; }),
            vec2.end());

        if (vec2.size() == 1)
        {
            break;
        }

        bit++;

    }
    std::cout << vec2[0] << std::endl;
}