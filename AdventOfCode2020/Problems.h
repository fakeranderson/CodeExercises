#pragma once

#include <vector>
#include <map>
#include <string>
namespace AdventOfCode2020
{
	class ProblemOne
	{
	public:
		static int partOne(std::string path, int targetSum);
		static int partTwo(std::string path, int targetSum);
	};

	class DayTwo
	{
	public:
		static int partOne(std::string path);
		static int partTwo(std::string path);
	};

	class DayThree
	{
	public:
		static int partOne(std::string path);
		static int partTwo(std::string path, std::vector<std::pair<int, int>> shiftPairs);
	};
}