//#include <iostream>
//#include <vector>
//#include <algorithm>
//
// CyclicRotation
//void print_vector(std::vector<int>& a)
//{
//    std::for_each(a.begin(), a.end(), [](int i) { std::cout << i << " "; });
//    std::cout << std::endl;
//}

//int gcd(int a, int b)
//{
//    if (b == 0)
//        return a;
//
//    else
//        return gcd(b, a % b);
//}
//
//std::vector<int> leftRotate(std::vector<int>& arr, int d)
//{
//    int n = arr.size();
//    /* To handle if d >= n */
//    d = d % n;
//    int g_c_d = gcd(d, n);
//    for (int i = 0; i < g_c_d; i++) {
//        /* move i-th values of blocks */
//        int temp = arr[i];
//        int j = i;
//
//        while (1) {
//            int k = j + d;
//            if (k >= n)
//                k = k - n;
//
//            if (k == i)
//                break;
//
//            arr[j] = arr[k];
//            j = k;
//        }
//        arr[j] = temp;
//    }
//    return arr;
//}
//
//std::vector<int> solution(std::vector<int>& A, int K)
//{
//    return leftRotate(A, K);
//}
//
//
//OddOccurencesInArray
//int solution(std::vector<int>& A)
//{
//     Find the first element that does not have a pair
//     Assume that :
//     N is an odd integer within the range[1..1, 000, 000];
//     each element of array A is an integer within the range[1..1, 000, 000, 000];
//     all but one of the values in A occur an even number of times.  ** THIS IS IMPORTANT
//
//
//     My code start
//     First check the array sizes for edge cases.
//    int retVal = 0;
//    if (A.size() == 1)
//    {
//        retVal = A[0];
//    }
//    else 
//    {
//         Sort the array, then XOR it all. Why? 
//        X XOR Y == Z, then Z XOR Y = X. retVal will flip back and forth when iterating through the vector's pairs, and 
//         all the remaining bits will be from the single number that has no pair. 
//        std::sort(A.begin(), A.end());
//        for(int i : A)
//        {
//            retVal ^= i;
//        }
//    }
//    return retVal;
//}
//
//int main()
//{
//    std::vector<int> a;
//    a.push_back(9);
//    a.push_back(3);
//    a.push_back(9);
//    a.push_back(3);
//    a.push_back(9);
//    a.push_back(9);
//    a.push_back(7);
//
//    solution(a);
//
//    return 0;
//}
//
//int main()
//{
//    std::vector<int> a;
//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(3);
//    a.push_back(4);
//    a.push_back(5);
//    a.push_back(6);
//    a.push_back(7);
//    a.push_back(8);
//    a.push_back(9);
//    a.push_back(10);
//    a.push_back(11);
//    a.push_back(12);
//    a.push_back(13);
//    a.push_back(14);
//    a.push_back(15);
//    a.push_back(16);
//
//    print_vector(a);
//    std::vector<int> outVector = solution(a, 4);
//
//    print_vector(outVector);
//
//    int oddCount = std::count_if(a.begin(), a.end(), [](int i) {return i % 2 == 1; });
//    std::cout << oddCount << std::endl;
//    
//    std::sort(a.begin(), a.end(), [](const int& a, const int& b) {return b > a; });
//    print_vector(a);
//
//    auto lastUnique = std::unique(a.begin(), a.end(), [](int a, int b) {return a == b; });
//    print_vector(a);
//    std::cout << std::distance(a.begin(), lastUnique) << std::endl;
//}