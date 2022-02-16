#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <cmath>
#include <array>
using array2d = std::array<std::array<int, 5>, 5>;

std::vector<array2d> bingo_tables;
std::vector<array2d> bingo_counter_tables;
std::vector<int> bingo_vec;

void print_bingo(int arr)
{
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << bingo_tables[arr][i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void print_bingo_counter(int arr)
{
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << bingo_counter_tables[arr][i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void read()
{
    std::ifstream file("input.txt");

    int x;
    char temp;
    while (file >> x)
    {
        bingo_vec.push_back(x);
        if (file.peek() == '\n')
        {
            break;
        }
        file >> temp;
    }

    auto bingo_size = 5;
    int it = 0;
    while (true)
    {
        bingo_tables.push_back(array2d());
        bingo_counter_tables.push_back(array2d());
        for (int i = 0; i < bingo_size; i++)
        {
            for (int j = 0; j < bingo_size; j++)
            {
                if (!(file >> x))
                {
                    bingo_tables.pop_back();
                    bingo_counter_tables.pop_back();
                    return;
                }
                bingo_tables[it][i][j] = x;
                bingo_counter_tables[it][i][j] = 0;
            }
        }
        std::string t;
        std::getline(file, t);
        it++;
    }
}

int main()
{
    read();

    int it = 0;
    int bingo_size = 5;
    bool bingo_flag = false;
    int bingo_table = -1;
    int bingo_number = -1;
    int bingos_tables_counter = 0;
    std::vector<int> bingos_tables_done;
    while (true)
    {
        auto bingo_num = bingo_vec[it];
        for (int i = 0; i < bingo_tables.size(); i++)
        {
            for (int j = 0; j < bingo_size; j++)
            {
                for (int k = 0; k < bingo_size; k++)
                {
                    if (bingo_tables[i][j][k] == bingo_num && bingo_counter_tables[i][j][k] == 0)
                    {
                        bingo_counter_tables[i][j][k] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < bingo_tables.size(); i++)
        {
            // check rows
            for (int j = 0; j < bingo_size; j++)
            {
                int cont = 0;
                for (int k = 0; k < bingo_size; k++)
                {
                    if (bingo_counter_tables[i][j][k] == 1)
                    {
                        cont++;
                    }
                }
                bool found = std::find(bingos_tables_done.begin(), bingos_tables_done.end(), i) != bingos_tables_done.end();
                if (cont == bingo_size && !found)
                {
                    bingos_tables_done.push_back(i);
                    if (bingos_tables_done.size() == bingo_tables.size())
                    {
                        bingo_flag = true;
                        bingo_table = i;
                        bingo_number = bingo_num;
                    }

                    break;
                }
            }

            // check columns
            for (int j = 0; j < bingo_size; j++)
            {
                int cont = 0;
                for (int k = 0; k < bingo_size; k++)
                {
                    if (bingo_counter_tables[i][k][j] == 1)
                    {
                        cont++;
                    }
                }

                bool found = std::find(bingos_tables_done.begin(), bingos_tables_done.end(), i) != bingos_tables_done.end();
                if (cont == bingo_size && !found)
                {
                    bingos_tables_done.push_back(i);
                    if (bingos_tables_done.size() == bingo_tables.size())
                    {
                        bingo_flag = true;
                        bingo_table = i;
                        bingo_number = bingo_num;
                    }

                    break;
                }
            }
        }
        if (bingo_flag)
        {
            break;
        }
        it++;
    }

    int sum = 0;
    for (int i = 0; i < bingo_size; i++)
    {
        for (int j = 0; j < bingo_size; j++)
        {
            if (bingo_counter_tables[bingo_table][i][j] == 0)
            {
                sum += bingo_tables[bingo_table][i][j];
            }
        }
    }
    std::cout << sum * bingo_number;
}