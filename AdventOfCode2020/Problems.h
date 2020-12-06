#pragma once

#include <vector>
#include <map>
#include <string>
namespace AdventOfCode2020
{

	class ProblemOne
	{
	public:
		static int multOfSums(std::vector<int>& A, int targetSum);
		static int multOfThreeSums(std::vector<int>& A, int targetSum);
	};

	class DayTwo
	{
	public:
		typedef std::map<char, std::vector<std::pair<std::pair<int, int>, int>>> PasswordStructure;
		static int partOne(std::string path);
		static int partTwo(std::string path);
	};
}