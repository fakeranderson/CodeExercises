#include <vector>

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