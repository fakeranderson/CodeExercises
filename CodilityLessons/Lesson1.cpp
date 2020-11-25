#include "Lesson1.h"
#include <bitset>
#include <iostream>
#include <random>


namespace Lesson1
{
    int BinaryGap::solution(int N)
    {
        std::bitset<32> bitStream(N);
        int maxConsecutive = 0;
        for (unsigned int i = 0; i < bitStream.size(); ++i)
        {
            if (bitStream[i] == 1) // If we hit the first 1, start the second loop
            {    
                int zeroCounter = 0; // counts consecutive zeros
                unsigned int j = (i + 1); // Begin at the next value
                for (;(j < bitStream.size()) && (bitStream[j] != 1); ++j)
                {
                    ++zeroCounter;
                }
                // Edge (literally) case to prevent storing the count when the for loop breaks from j hit the end of the array at 0.
                const bool consecutiveTerminated = (bitStream[j] == 1);
                if (consecutiveTerminated && (zeroCounter > maxConsecutive))
                {
                    maxConsecutive = zeroCounter;
                }
            }
        }
        return maxConsecutive;
    }
}

//int main()
//{

//}