#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

// FrogJmp
//int solution(int X, int Y, int D)
//{
//    // Find the total distance needed to jump
//    const int diff = Y - X;
//    int jumpsRequired = (diff % D == 0) ? (diff / D) : ((diff / D) + 1);
//    return jumpsRequired;
//}


// PermMissingElem
//int solution(std::vector<int>& a)
//{
//    int missingNumber = 1;
//    // A number N is missing from this vector. The vector is sized 0 - (N+1).
//    // This missing number will be between 1 and N + 1
//    if (!a.empty())
//    {
//        std::sort(a.begin(), a.end());
//        const int firstNumber = a[0];
//        if (firstNumber != 1)
//        {
//            missingNumber = 1;
//        }
//        else
//        {
//            for (unsigned int i = 0; i < a.size(); ++i)
//            {
//                if (i == a.size() - 1) // reached the end, so missing number is the next one
//                {
//                    missingNumber = a[i] + 1;
//                    break;
//                }
//
//                const int currentNumber = a[i];
//                const int nextNumber = a[i + 1];
//                if (currentNumber != (nextNumber - 1))
//                {
//                    missingNumber = a[i] + 1;
//                    break;
//                }
//            }
//
//        }
//    }
//    return missingNumber;
//}

// TapeEquilibrium
//int solution(std::vector<int>& a)
//{
//    int answer = 0;
//    const unsigned int vecSize = a.size();
//    if (vecSize != 0)
//    {
//        // First take the sum of the entire vector
//        long sumAllElements = 0;
//        for (unsigned int i = 0; i < vecSize; ++i)
//        {
//            sumAllElements += a[i];
//        }
//
//        int minDiff = INT32_MAX;
//        int currentDiff = INT32_MAX;
//        long sumFirstPart = 0;
//        long sumSecondPart = 0;
//
//        // Now the cool part: we go through the array (again) and tally the sum (again) each time, BUT
//        // THEN we back that sum out of the ENTIRE sum, so we know the second part of the vector's sum
//        // Then take the min diff
//        for (int p = 0; p < vecSize - 1; ++p)
//        {
//            sumFirstPart += a[p];
//            sumSecondPart = sumAllElements - sumFirstPart;
//            currentDiff = std::abs(sumFirstPart - sumSecondPart);
//            minDiff = (currentDiff < minDiff) ? currentDiff : minDiff;
//        }
//
//        answer = minDiff;
//    }
//    return answer;
//}


//int main()
//{
//     FrogJmp
//    int currentPos = 10;
//    int goalPos = 85;
//    int jumpDistance = 30;
//    int distance = solution(currentPos, goalPos, jumpDistance);
//
//     PermMissingElem
//    std::vector<int> a;
//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(1);
//    a.push_back(5);
//    int missingNumber = solution(a);
//
//     TapeEquilibrium
//    std::vector<int> a;
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_int_distribution<int> dist(-1, 1); // Problem calls for random up to 2147483647, so use the macro
//    for (int i = 0; i < 100000; ++i)
//    {
//        a.push_back(dist(mt));
//    }
//    a.push_back(1);
//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(4);
//    a.push_back(3);
//    int sum = solution(a);
//}