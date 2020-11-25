#include <iostream>
#include <vector>
#include <algorithm>
#include "Lesson2.h"


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