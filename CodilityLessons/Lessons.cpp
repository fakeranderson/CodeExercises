#include "Lessons.h"
#include <bitset>
#include <iostream>
#include <random>
#include <set>
#include <string>

namespace CodilityLessons
{
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
					for (; (j < bitStream.size()) && (bitStream[j] != 1); ++j)
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

	// CyclicRotation
	namespace Lesson2
	{
		int CyclicRotation::gcd(int a, int b)
		{
			if (b == 0)
				return a;

			else
				return gcd(b, a % b);
		}

		std::vector<int> CyclicRotation::leftRotate(std::vector<int>& arr, int d)
		{
			int n = arr.size();
			/* To handle if d >= n */
			d = d % n;
			int g_c_d = gcd(d, n);
			for (int i = 0; i < g_c_d; i++) {
				/* move i-th values of blocks */
				int temp = arr[i];
				int j = i;

				while (1) {
					int k = j + d;
					if (k >= n)
						k = k - n;

					if (k == i)
						break;

					arr[j] = arr[k];
					j = k;
				}
				arr[j] = temp;
			}
			return arr;
		}

		std::vector<int> CyclicRotation::solution(std::vector<int>& A, int K)
		{
			return CyclicRotation::leftRotate(A, K);
		}

		int OddOccurencesInArray::solution(std::vector<int>& A)
		{
			//Find the first element that does not have a pair
			//Assume that :
			//N is an odd integer within the range[1..1, 000, 000];
			//each element of array A is an integer within the range[1..1, 000, 000, 000];
			//all but one of the values in A occur an even number of times.  ** THIS IS IMPORTANT


			//My code start
			//First check the array sizes for edge cases.
			int retVal = 0;
			if (A.size() == 1)
			{
				retVal = A[0];
			}
			else
			{
				// Sort the array, then XOR it all. Why? 
				// X XOR Y == Z, then Z XOR Y = X. retVal will flip back and forth when iterating through the vector's pairs, and 
				// all the remaining bits will be from the single number that has no pair. 
				std::sort(A.begin(), A.end());
				for (int i : A)
				{
					retVal ^= i;
				}
			}
			return retVal;
		}
	}

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

	namespace Lesson4
	{
		int FrogRiverOne::solution(int X, std::vector<int>& A)
		{
			//Use an std::set for efficiency.
			int answer = -1;
			std::set<int> leafPosSet;
			for (unsigned int i = 0; i < A.size(); ++i)
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

			for (unsigned int i = 0; i < A.size(); ++i)
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
	namespace Lesson6
	{

		int Distinct::solution(std::vector<int>& A)
		{
			//Given array of N integers, find unique
			//Use a set so worst case is O(nlogn)
			//Option 1 use a set(automatically unique) O(nlogn)
			//std::set<int> intSet;
			//for (unsigned int i = 0; i < A.size(); ++i)
			//{
			//	intSet.insert(A[i]);
			//}

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

		// https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
		int NumberOfDiscIntersections::solution(std::vector<int>& A)
		{
			// Give an int array of "circles" where the index is the center along the x axis and the value is the radius, 
			// return the number of unique intersections
			// If A[1] = 5, then the center is at point 1, the left edge is at -4, and the right edge is at 6
			// We need to iterate across the X axis starting at the lowest left edge, ending at the highest left edge
			// We also need to know which circles are "active" so we can tally the intersections when we reach a new left edge
			// We can use intersection logic to sum the previous intersections with the new intersections at each index from X = 0 -> N. (I'm not a mathematition so I got a lil hint online for this one)

			int intersections = 0;
			// Edge case size 0
			if (!A.empty())
			{
				const unsigned int circleCount = A.size();
				const unsigned int back = circleCount - 1;
				std::vector<long> startPoints(circleCount, 0); // Can be negative INT32_MAX
				std::vector<unsigned long> endPoints(circleCount, 0); // Never negative, but using an int will flip if radius is INT32_MAX

				// This stores the count of start and stops of each circle at each index on the x axis, index 0 is activations <= X = 0
				for (unsigned int i = 0; i < circleCount; ++i)
				{
					const unsigned int center = A[i];
					const long leftEdge = i - A[i];
					const unsigned long rightEdge = i + A[i];
					if (i < center)
					{
						startPoints[0]++;
					}
					else
					{
						startPoints[leftEdge]++;
					}

					if (rightEdge >= circleCount)
					{
						endPoints[back]++;
					}
					else
					{
						endPoints[rightEdge]++;
					}
				}

				int activeCircles = 0;
				for (unsigned int i = 0; i < circleCount; ++i)
				{
					// Local vars for readability
					const int startingCircles = startPoints[i];
					const int endingCircles = endPoints[i];
					// We add the intersections of the [active and starting circles] with the intersections of the [new circles]
					// Intersections of active circles with starting circles
					const int currentCircleIntersections = activeCircles * startingCircles;

					// Intersections of starting circles with themselves
					// Combination equation for set size N choose 2 n*(n-1)/2 -> from n!/k!(n-k)! where k = 2
					const int newCircleIntersections = (startingCircles * (startingCircles - 1)) / 2;

					// Now sum the combos
					const int newIntersections = currentCircleIntersections + newCircleIntersections;
					intersections += newIntersections;

					// From problem description
					if (intersections > 10000000)
					{
						intersections = -1;
						break;
					}

					// Refresh our count of active circles
					activeCircles += startingCircles - endingCircles;
				}
			}

			return intersections;
		}


		int Triangle::solution(std::vector<int>& A)
		{
			// Convert whatever we have to longs, otherwise we'll overflow max int
			std::vector<long> B;
			for (int i : A)
			{
				if (i > 0) // Skip <= 0
					B.push_back(i);
			}

			if (B.size() < 3)
			{
				return 0;
			}

			// Find if there is or not a triangle in the given vector
			// N > R > Q > P >= 0
			// 0 <= P < Q < R < N
			// Condition 1: Ar + Aq > Ap
			// Condition 2: Aq + Ap > Ar
			// Condition 3: Ar + Ap > Aq

			// Once we sort the array, condition 1 and condition 2 are always true
			std::sort(B.begin(), B.end());

			// We just need to check for condition 3, starting at the largest
			bool triangleFound = false;
			for (unsigned int i = B.size() - 1; i >= 2; --i)
			{
				int P = B[i - 2];
				int Q = B[i - 1];
				int R = B[i];

				if (Q + P > R)
				{
					triangleFound = true;
					break;
				}
			}

			return (int)triangleFound;
		}
	}

}
