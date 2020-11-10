#include <vector>
#include <algorithm>
#include <string>

// CountDiv
//int solution(int A, int B, int K)
//{
//    // Give range A - B, return the number of those integers divisible by K
//    // For each integer i in range, if i % k == 0, increment counter
//    // A & B are within 0 - 2 million
//    // K is within 1 - 2 million
//    // A <= B
//    int counter = 0;
//    if (A == B)
//    {
//        return (A % K == 0); // 1 divisor if true, 0 divisor if false
//    }
//    else if (K == 1)
//    {
//        return B - A + 1;
//    }
//    else if (K == B) // Edgy edge case if our divisor is our upper bound, that's the only one (unless A is 0).
//    {
//        return (A == 0) ? 2 : B;
//    }
//    else
//    {
//        // Key insight to avoid a bajillion loops:
//        // We only need the first divisor, THEN we can use that to figure out the remaining number
//        // of divisible answers by seeing how many loops we can stay in range A -> B while adding the divisor to our count
//        int firstDivisor = 0;
//        for (int i = A; i <= B; ++i)
//        {
//            if (i % K == 0)
//            {
//                firstDivisor = i;
//                break;
//            }
//        }
//        for (int i = firstDivisor; i <= B; i += K)
//        {
//            ++counter;
//        }
//    }
//    return counter;
//}

// GenomicRangeQuery
std::vector<int> solution(std::string& S, std::vector<int>& F, std::vector<int>& Q)
{

}

int main()
{

    // CountDiv
    //int A = 0, B = 2000000000, K = 2000000000;
    //int divs = solution(A, B, K);

    // GenomicRangeQuery

    return 0;

}