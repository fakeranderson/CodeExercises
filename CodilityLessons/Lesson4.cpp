#include "Lesson4.h"
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
#include <iostream>

namespace Lesson4
{
	int FrogRiverOne::solution(int X, std::vector<int>& A)
	{
		//Use an std::set for efficiency.
		int answer = -1;
		std::set<int> leafPosSet;
		for (int i = 0; i < A.size(); ++i)
		{
			//The index is the time, the value is the position of the leaf
			leafPosSet.insert(A[i]);

			//If the last element is Xand the siize is X, then were done, return i
			if (*leafPosSet.rbegin() == X && leafPosSet.size() == X)
			{
				answer = i;
				break;
			}
		}
		return answer;
	}

	std::vector<int> MaxCounters::solution(int N, std::vector<int>& A)
	{
		//Defintion is large, check the website
			//For loop to go through all vector elements
			//if A[i] <= N, increment the i - th value in the outvector
				//if A[i] == N + 1, increase the counter, assign it to all vector members
		std::vector<int> results(N, 0);

		int minCount = 0;
		int maxCounter = 0;
		for (unsigned int i = 0; i < A.size(); ++i)
		{
			if (A[i] != N + 1)
			{
				results[A[i] - 1] = std::max(minCount, results[A[i] - 1]) + 1;
				maxCounter = std::max(maxCounter, results[A[i] - 1]);
			}
			else
			{
				minCount = maxCounter;
			}
		}

		for (int i = 0; i < N; i++)
		{
			if (results[i] < minCount)
			{
				results[i] = minCount;
			}
		}
		return results;
	}

	int MissingInteger::solution(std::vector<int>& A)
	{
		//Use containers to sort, then strip out all the junk we don't need: negatives, duplicates.
		std::sort(A.begin(), A.end()); // Sort the vector
		auto firstDup = std::unique(A.begin(), A.end()); // Move dups to back
		A.erase(firstDup, A.end()); // Strip dups
		auto it = std::remove_if(A.begin(), A.end(), [](const int i) {return i < 0; }); // Shuffle down negatives and 0
		A.erase(it, A.end()); // Remove negatives and 0

		//Given an array A of N integers, return the smallest positive integer that does not occur in A
		if (A.empty())
		{
			return 1;
		}
		else if (A.size() == 1)
		{
			if (A[0] == 1)
				return 2;
			else
				return 1;
		}
		else if (A[0] > 1) // Missing the first number. 
			return 1;

		for (int i = 0; i < A.size(); ++i)
		{
			if (i == A.size() - 1) // If at end, next number is missing
				return A[i] + 1;

			const int currentInt = A[i];
			const int nextInt = A[i + 1];
			if (currentInt != nextInt - 1)
			{
				return currentInt + 1;
			}
		}
		return -1;
	}
}
