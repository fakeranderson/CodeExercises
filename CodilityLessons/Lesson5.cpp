#include "Lesson5.h"
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

namespace Lesson5
{

	// CountDiv
	int CountDiv::solution(int A, int B, int K)
	{
		// Give range A - B, return the number of those integers divisible by K
		// For each integer i in range, if i % k == 0, increment counter
		// A & B are within 0 - 2 million
		// K is within 1 - 2 million
		// A <= B
		int counter = 0;
		if (A == B)
		{
			return (A % K == 0); // 1 divisor if true, 0 divisor if false
		}
		else if (K == 1)
		{
			return B - A + 1;
		}
		else if (K == B) // Edgy edge case if our divisor is our upper bound, that's the only one (unless A is 0).
		{
			return (A == 0) ? 2 : B;
		}
		else
		{
			// Key insight to avoid a bajillion loops:
			// We only need the first divisor, THEN we can use that to figure out the remaining number
			// of divisible answers by seeing how many loops we can stay in range A -> B while adding the divisor to our count
			int firstDivisor = 0;
			for (int i = A; i <= B; ++i)
			{
				if (i % K == 0)
				{
					firstDivisor = i;
					break;
				}
			}
			for (int i = firstDivisor; i <= B; i += K)
			{
				++counter;
			}
		}
		return counter;
	}

	// GenomicRangeQuery
	// Read the website for the description
	std::vector<int> GenomicRangeQuery::solution(std::string& S, std::vector<int>& P, std::vector<int>& Q)
	{
		int** genomPrefixSums = new int* [3];
		for (int i = 0; i < 3; ++i)
		{
			genomPrefixSums[i] = new int[S.size() + 1];
			for (unsigned int j = 0; j < S.size() + 1; ++j)
				genomPrefixSums[i][j] = 0;
		}
		// First build an array of occurrences of each letter. We can ignore T because it's the max.
		// ASCII interpretation for the string CAGCCTA (2132241)... and indexes 0 = A, 1 = C, 2 = G
		//     0 1 2 3 4 5 6 7
		// 0 | 0 0 1 1 1 1 1 2 -> Between 2 and 6 there were 0 occurrence of A, because the value was not incremented
		// 1 | 0 1 1 1 2 3 3 3 -> Between 4 and 7 there was 1 occurrence of C, because the value was incremented
		// 2 | 0 0 0 1 1 1 1 1 -> Between 0 and 7 there was 1 occurrence of G
		// Reading verically, at index 7 there were 2 A's, 3 C's, and 1 G.
		int a, c, g;
		for (unsigned int i = 0; i < S.size(); ++i)
		{
			a = 0, c = 0, g = 0;
			if (S[i] == 'A')
				a = 1;
			else if (S[i] == 'C')
				c = 1;
			else if (S[i] == 'G')
				g = 1;
			genomPrefixSums[0][i + 1] = genomPrefixSums[0][i] + a;
			genomPrefixSums[1][i + 1] = genomPrefixSums[1][i] + c;
			genomPrefixSums[2][i + 1] = genomPrefixSums[2][i] + g;
		}

		std::vector<int> outVec(P.size(), 0);
		for (unsigned int i = 0; i < P.size(); i++)
		{
			int startIdx = P[i], stopIdx = Q[i] + 1; // Set our search bounds
			// Now we check our "occurrence matrix." So for each set of ranges given by P and Q...
			// If, between our start and stop Idx's, there is NO CHANGE (difference = 0), then we know that that letter did NOT OCCUR.
			// We order the if-blocks by min value, so the first occurring letter is the guaranteed min. Then store it. 
			// We didn't need to store T's in the occurrence matrix because of given assumptions that 
			// we will only get A, C, G, T. So if not the first three, then T. 
			const bool occurrenceOfA = (genomPrefixSums[0][stopIdx] - genomPrefixSums[0][startIdx] > 0);
			const bool occurrenceOfC = (genomPrefixSums[1][stopIdx] - genomPrefixSums[1][startIdx] > 0);
			const bool occurrenceOfG = (genomPrefixSums[2][stopIdx] - genomPrefixSums[2][startIdx] > 0);
			if (occurrenceOfA)
				outVec[i] = 1;
			else if (occurrenceOfC)
				outVec[i] = 2;
			else if (occurrenceOfG)
				outVec[i] = 3;
			else
				outVec[i] = 4;
		}
		return outVec;
	}

	// MinAvgTwoSlice
	// Array of N integers, return the index of start of the slice (between P and Q) containing the lowest avg
	// This is actually a mathematical induction problem. P and Q is irrelevant. Why?
	// The key insight is that the min average will be inside of a range either size 2 or size 3, so 
	// we linearly traverse the vector checking 2 and 3 elements at a time. I didn't discover this on my own, sadly.
	// Proof: https://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/
	int MinAvgTwoSlice::solution(std::vector<int>& A)
	{
		int minAvgIdx = 0;
		double minAvg = (A[0] + A[1]) / 2; // Take the average of the first two as an initialization
		double currentAvg;
		// For terminates 2 spots before the end. We check the last two spots' average afterwards
		for (unsigned int i = 0; i < A.size() - 2; ++i)
		{
			// Get the averages of slice size 2 and slice size 3.
			const double currentAvg2 = (A[i] + A[i + 1]) / 2.0;
			const double currentAvg3 = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
			currentAvg = (currentAvg2 < currentAvg3) ? currentAvg2 : currentAvg3; // Min
			// If the avg is lower than previous, store the avg and the index
			if (currentAvg < minAvg)
			{
				minAvg = currentAvg;
				minAvgIdx = i;
			}
		}
		// Now check our last 2 elements
		currentAvg = (A[A.size() - 2] + A[A.size() - 1]) / 2.0;
		if (currentAvg < minAvg)
		{
			minAvg = currentAvg;
			minAvgIdx = A.size() - 2;
		}
		return minAvgIdx;
	}

	// PassingCars
	// Given size N array consisting of only 0's and 1's, return the number of opposing pairs (cars)
	// O(N) thanks to key insight: each 0 car serves as a multiplier for the following sequence of continuous 1 cars.
	// All 1's falling between the first and second 0 have a multiplier of 1, because they will only pass a single 0
	// All 1's between the second and third 0 have a multiplier of 2, because they will pass two 0's
	// Then when we reach the end, treat it the same as if it was a 0, that way those final consecutive 1's is counted.
	int PassingCars::solution(std::vector<int>& A)
	{
		unsigned long int pairCount = 0; // big numbers just in case
		unsigned long int zeroMultiplier = 0;
		unsigned long int onesCounter = 0;
		for (unsigned int i = 0; i <= A.size(); ++i)
		{
			if (i == (A.size()) || A[i] == 0)
			{
				pairCount += onesCounter * zeroMultiplier;
				zeroMultiplier++;
				onesCounter = 0;
			}
			else
			{
				onesCounter++;
			}
			// Assumptions section says > a billion should return -1, and never negatives (apparently this happens sometimes)
			if (pairCount > 1000000000 || pairCount < 0)
			{
				pairCount = -1;
				break;
			}
		}
		return (int)pairCount;
	}
}
