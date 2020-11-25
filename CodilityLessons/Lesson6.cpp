#include "Lesson6.h"
#include <vector>
#include <set>
#include <algorithm>
namespace Lesson6
{

	int Distinct::solution(std::vector<int>& A)
	{
		//Given array of N integers, find unique
		//Use a set so worst case is O(nlogn)
		//Option 1 use a set(automatically unique) O(nlogn)
		std::set<int> intSet;
		for (unsigned int i = 0; i < A.size(); ++i)
		{
			intSet.insert(A[i]);
		}

		//Option 2 make two arrays of bools no greater than possible max int(bounds are given in problem assumptions)
		//to lookup whether or not the number is seen or not.
		//O(n) if we're not counting initialization (we're not)
		bool* uniquesPositive = new bool[100000002];
		bool* uniquesNegative = new bool[100000001];
		for (unsigned int i = 0; i < A.size(); ++i)
		{
			uniquesNegative[i] = false;
			uniquesPositive[i] = false;
		}

		int uniqueCount = 0;
		for (unsigned int i = 0; i < A.size(); ++i)
		{
			int currentValue = A[i];
			//If negative, flip to positiveand add to negative list counter
				//If positive, add to positive list counter
			if (currentValue < 0)
			{
				currentValue *= -1;
				if (!uniquesNegative[currentValue])
				{
					uniquesNegative[currentValue] = true;
					++uniqueCount;
				}
			}
			else if (currentValue >= 0)
			{
				if (!uniquesPositive[currentValue])
				{
					uniquesPositive[currentValue] = true;
					++uniqueCount;
				}
			}
		}

		delete[] uniquesNegative;
		delete[] uniquesPositive;
		return uniqueCount;
	}

	int MaxProductOfThree::solution(std::vector<int>& A)
	{
		//Rather than sort the A vectorand grab the values from it, I wanted to try
		//minimizing storageand sorting on this one... so it's a bit wordy.
		//Complexity is O(n), even though codility thinks it's nlogn -_-
		//To find our product, we need the 3 hgighest positives and the two lowest negative
		int negativeLowest = 0; // The lowest number we find
		int negativeSecondLowest = 0; // The second from the lowest number we find
		int positiveHighest = -1; // The highest number we find.
		int positiveSecondHighest = -1; // The second highest number we find.
		int positiveThirdHighest = -1; // The third highest number we find

		//In the event that we have no positive numbers, our answer is the product of these
		int negativeHighest = -1001; // The negative number closest to 0
		int negativeSecondHighest = -1001; // The negative number second-closest to 0 
		int negativeThirdHighest = -1001;// The negative number third-closest to 0

		if (A.size() == 3) // Bail early, no need to work
		{
			return A[0] * A[1] * A[2];
		}

		//Iterate through the array one time, storing only the values that we need at the end.
		for (unsigned int i = 0; i < A.size(); ++i)
		{
			int currentValue = A[i];
			//If it's negative, and the new greatest, assign it and reassign the last greatest
			if (currentValue < 0)
			{
				//Shuffle the values depending on where this value is
				if (currentValue < negativeLowest)
				{
					negativeSecondLowest = negativeLowest;
					negativeLowest = currentValue;
				}
				else if (currentValue < negativeSecondLowest)
				{
					negativeSecondLowest = currentValue;
				}

				if (currentValue > negativeHighest)
				{
					negativeThirdHighest = negativeSecondHighest;
					negativeSecondHighest = negativeHighest;
					negativeHighest = currentValue;
				}
				else if (currentValue > negativeSecondHighest)
				{
					negativeThirdHighest = negativeSecondHighest;
					negativeSecondHighest = currentValue;
				}
				else if (currentValue > negativeThirdHighest)
				{
					negativeThirdHighest = currentValue;
				}

			}
			else // Positive number
			{
				//Shuffle the values down
				if (currentValue > positiveHighest)
				{
					positiveThirdHighest = positiveSecondHighest;
					positiveSecondHighest = positiveHighest;
					positiveHighest = currentValue;
				}
				else if (currentValue > positiveSecondHighest)
				{
					positiveThirdHighest = positiveSecondHighest;
					positiveSecondHighest = currentValue;
				}
				else if (currentValue > positiveThirdHighest)
				{
					positiveThirdHighest = currentValue;
				}
			}
		}

		int answer = -1;
		//We have no positive numbers.
			//Minmize that answer by taking the the product of the three highest negatives
		if (positiveHighest == -1)
		{
			answer = negativeHighest * negativeSecondHighest * negativeThirdHighest;
		}
		else
		{
			//Answer is the greatest positive multipled by either the two greatest negatives or the second and third highest positives
			int positiveProduct = positiveThirdHighest * positiveSecondHighest * positiveHighest;
			int negativeProduct = negativeLowest * negativeSecondLowest * positiveHighest;
			answer = std::max(positiveProduct, negativeProduct);
		}
		return answer;
	}

	int NumberOfDiscIntersections::solution(std::vector<int>& A)
	{

		return 0;
	}
	int Triangle::solution(std::vector<int>& A)
	{
		return 0;
	}
}