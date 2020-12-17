#include "CodilityLessons/Lessons.h"
#include "AdventOfCode2020/Problems.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>

void print_vector(std::vector<int>& a)
{
	std::for_each(a.begin(), a.end(), [](int i) { std::cout << i << " "; });
	std::cout << std::endl;
}

int main()
{
	int answer = 0;
	// Day One
	answer = AdventOfCode2020::ProblemOne::partOne("AdventOfCode2020\\InputFiles\\1-1.txt", 2020);
	answer = AdventOfCode2020::ProblemOne::partTwo("AdventOfCode2020\\InputFiles\\1-2.txt", 2020);
	// Day Two
	answer = AdventOfCode2020::DayTwo::partOne("AdventOfCode2020\\InputFiles\\2-1.txt");
	answer = AdventOfCode2020::DayTwo::partTwo("AdventOfCode2020\\InputFiles\\2-2.txt");

	// Day Three
	answer = AdventOfCode2020::DayThree::partOne("AdventOfCode2020\\InputFiles\\3-1.txt");
	std::vector<std::pair<int, int>> shiftPairs = { {1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1} }; // From 3-2 web page
	answer = AdventOfCode2020::DayThree::partTwo("AdventOfCode2020\\InputFiles\\3-2.txt", shiftPairs);

	// Day Four
	answer = AdventOfCode2020::DayFour::partOne("AdventOfCode2020\\InputFiles\\4-1.txt");
	answer = AdventOfCode2020::DayFour::partTwo("AdventOfCode2020\\InputFiles\\4-2.txt");

	// Day Five
	answer = AdventOfCode2020::DayFive::partOne("AdventOfCode2020\\InputFiles\\5-1.txt");
	answer = AdventOfCode2020::DayFive::partTwo("AdventOfCode2020\\InputFiles\\5-1.txt"); // Same input file

	answer = AdventOfCode2020::DaySix::partOne("AdventOfCode2020\\InputFiles\\6-1.txt");
	answer = AdventOfCode2020::DaySix::partTwo("AdventOfCode2020\\InputFiles\\6-1.txt");

	answer = AdventOfCode2020::DayEight::partOne("AdventOfCode2020\\InputFiles\\8-1.txt");
	answer = AdventOfCode2020::DayEight::partTwo("AdventOfCode2020\\InputFiles\\8-1.txt");
	return 0;
}