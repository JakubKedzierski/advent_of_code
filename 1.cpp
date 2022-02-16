#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("input.txt");

    int a = 0;
    int b = 0;
    int it = 0;
    int counter = 0;
    while (file >> a)
    {

        if (it == 0)
        {
            b = a;
            it++;
            continue;
        }

        if (a > b)
        {
            counter++;
        }
        b = a;
    }
    std::cout << counter;
}