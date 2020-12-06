#include "Lesson3.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

namespace Lesson3
{

	int FrogJump::solution(int X, int Y, int D)
	{
		// Find the total distance needed to jump
		const int diff = Y - X;
		int jumpsRequired = (diff % D == 0) ? (diff / D) : ((diff / D) + 1);
		return jumpsRequired;
	}

	int PermMissingElem::solution(std::vector<int>& a)
	{
		int missingNumber = 1;
		// A number N is missing from this vector. The vector is sized 0 - (N+1).
		// This missing number will be between 1 and N + 1
		if (!a.empty())
		{
			std::sort(a.begin(), a.end());
			const int firstNumber = a[0];
			if (firstNumber != 1)
			{
				missingNumber = 1;
			}
			else
			{
				for (unsigned int i = 0; i < a.size(); ++i)
				{
					if (i == a.size() - 1) // reached the end, so missing number is the next one
					{
						missingNumber = a[i] + 1;
						break;
					}

					const int currentNumber = a[i];
					const int nextNumber = a[i + 1];
					if (currentNumber != (nextNumber - 1))
					{
						missingNumber = a[i] + 1;
						break;
					}
				}

			}
		}
		return missingNumber;
	}

	int TapeEquilibrium::solution(std::vector<int>& a)
	{
		int answer = 0;
		const unsigned int vecSize = a.size();
		if (vecSize != 0)
		{
			// First take the sum of the entire vector
			long sumAllElements = 0;
			for (unsigned int i = 0; i < vecSize; ++i)
			{
				sumAllElements += a[i];
			}

			int minDiff = INT32_MAX;
			int currentDiff = INT32_MAX;
			long sumFirstPart = 0;
			long sumSecondPart = 0;

			// Now the cool part: we go through the array (again) and tally the sum (again) each time, BUT
			// THEN we back that sum out of the ENTIRE sum, so we know the second part of the vector's sum
			// Then take the min diff
			for (unsigned int p = 0; p < vecSize - 1; ++p)
			{
				sumFirstPart += a[p];
				sumSecondPart = sumAllElements - sumFirstPart;
				currentDiff = std::abs(sumFirstPart - sumSecondPart);
				minDiff = (currentDiff < minDiff) ? currentDiff : minDiff;
			}

			answer = minDiff;
		}
		return answer;
	}
}