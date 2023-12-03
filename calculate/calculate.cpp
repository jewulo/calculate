// calculate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// https://www.youtube.com/watch?v=wGCWlI4A5z4
// https://www.youtube.com/watch?v=Z_ahq2h9Xxg

#include <iostream>
#include <numeric>
#include <ranges>


namespace v1
{
    int calculate(int bottom, int top) {
        if (top > bottom) {
            int sum = 0;
            for (int number = bottom; number <= top; number++)
            {
                if (number % 2 == 0) {
                    sum += number;
                }
            }
            return sum;
        }
        else {
            return 0;
        }
    }
}

namespace v2
{
    int calculate(int bottom, int top) {
        if (top > bottom) {
            int sum = 0;
            for (int number : std::views::iota(bottom, top + 1))
            {
                if (number % 2 == 0) {
                    sum += number;
                }
            }
            return sum;
        }
        else {
            return 0;
        }
    }
}

namespace v3
{
    int calculate(int bottom, int top) {
        if (top > bottom) {
            int sum = 0;
            auto even = [](auto e) { return e % 2 == 0; };
            for (int number : std::views::iota(bottom, top + 1)
                               | std::views::filter(even)) {
                sum += number;
            }
            return sum;
        }
        else {
            return 0;
        }
    }
}

namespace v4
{
    int calculate(int bottom, int top) {
        if (top > bottom) {
            int sum = 0;
            auto even = [](auto e) { return e % 2 == 0; };
            auto evens = std::views::iota(bottom, top + 1)
                        | std::views::filter(even);
            return std::accumulate(evens.begin(), evens.end(), 0);
        }
        else {
            return 0;
        }
    }
}

namespace v5
{
    int calculate(int bottom, int top) {
        return 0;
    }
}

int main()
{
    std::cout << v1::calculate(0, 10) << '\n';
    std::cout << v2::calculate(0, 10) << '\n';
    std::cout << v3::calculate(0, 10) << '\n';
    std::cout << v4::calculate(0, 10) << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
