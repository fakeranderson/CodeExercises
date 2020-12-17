#include <vector>
#include <string>


namespace CodilityLessons
{

namespace Lesson1
{
	class BinaryGap
	{
	public:
		static int solution(int N);
	};
}

namespace Lesson2
{
	class CyclicRotation
	{
	public:
		static std::vector<int> solution(std::vector<int>& A, int K);
	private:
		static std::vector<int> leftRotate(std::vector<int>& arr, int d);
		static int gcd(int a, int b);
	};

	class OddOccurencesInArray
	{
	public:
		static int solution(std::vector<int>& A);
	};
}


namespace Lesson3
{
	class FrogJump
	{
	public:
		static int solution(int X, int Y, int D);
	};

	class PermMissingElem
	{
	public:
		static int solution(std::vector<int>& A);
	};

	class TapeEquilibrium
	{
	public:
		static int solution(std::vector<int>& a);
	};

}

namespace Lesson4
{
	class FrogRiverOne
	{
	public:
		static int solution(int X, std::vector<int>& A);
	};

	class MaxCounters
	{
	public:
		static std::vector<int> solution(int N, std::vector<int>& A);
	};

	class MissingInteger
	{
	public:
		static int solution(std::vector<int>& A);
	};
}

namespace Lesson5
{
	class CountDiv
	{
	public:
		static int solution(int A, int B, int K);
	};
	class GenomicRangeQuery
	{
	public:
		static std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q);
	};
	class MinAvgTwoSlice
	{
	public:
		static int solution(std::vector<int>& A);
	};
	class PassingCars
	{
	public:
		static int solution(std::vector<int>& A);
	};

}

namespace Lesson6
{
	class Distinct
	{
	public:
		static int solution(std::vector<int>& A);
	};
	class MaxProductOfThree
	{
	public:
		static int solution(std::vector<int>& A);
	};
	class NumberOfDiscIntersections
	{
	public:
		static int solution(std::vector<int>& A);
	};
	class Triangle
	{
	public:
		static int solution(std::vector<int>& A);
	};
}

namespace Lesson7
{
	class Brackets
	{
	public:
		static int solution(std::string& S);
	};
}

}