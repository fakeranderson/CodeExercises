#include "CodilityLessons/Lesson1.h"
#include "CodilityLessons/Lesson2.h"
#include "CodilityLessons/Lesson3.h"
#include "CodilityLessons/Lesson4.h"
#include "CodilityLessons/Lesson5.h"
#include "CodilityLessons/Lesson6.h"
#include "AdventOfCode2020/Problems.h"

#include "Utilities.h"
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

	return 0;
}