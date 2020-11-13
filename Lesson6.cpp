#include <vector>
#include <set>

// Distinct
// Given array of N integers, find unique
// Use a set so worst case is O(nlogn)
//int solution (std::vector<int>& A)
//{
//	// Option 1 use a set (automatically unique) O(nlogn)
//	//std::set<int> intSet;
//	//for (unsigned int i = 0; i < A.size(); ++i)
//	//{
//	//	intSet.insert(A[i]);
//	//}
//
//	// Option 2 make two arrays of bools no greater than possible max int (bounds are given in problem assumptions) 
//	// to lookup whether or not the number is seen or not. 
//	// O(n) if we're not counting initialization (we're not)
//	//bool* uniquesPositive = new bool[100000002];
//	//bool* uniquesNegative = new bool[100000001];
//	//for (unsigned int i = 0; i < A.size(); ++i)
//	//{
//	//	uniquesNegative[i] = false;
//	//	uniquesPositive[i] = false;
//	//}
//
//	//int uniqueCount = 0;
//	//for (unsigned int i = 0; i < A.size(); ++i)
//	//{
//	//	int currentValue = A[i];
//	//	// If negative, flip to positive and add to negative list counter
//	//	// If positive, add to positive list counter
//	//	if (currentValue < 0)
//	//	{
//	//		currentValue *= -1;
//	//		if (!uniquesNegative[currentValue])
//	//		{
//	//			uniquesNegative[currentValue] = true;
//	//			++uniqueCount;
//	//		}
//	//	}
//	//	else if (currentValue >= 0)
//	//	{
//	//		if (!uniquesPositive[currentValue])
//	//		{
//	//			uniquesPositive[currentValue] = true;
//	//			++uniqueCount;
//	//		}
//	//	}
//	//}
//
//	//delete[] uniquesNegative;
//	//delete[] uniquesPositive;
//	//return uniqueCount;
//}

int main()
{
	// Distinct
	//std::vector<int> A;
	//for (int i = -10; i <= 10; ++i)
	//{
	//	A.push_back(i);
	//}
	return 0;
}