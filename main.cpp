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

std::vector<int> fileOfIntsToVector(std::string path)
{
    std::fstream file(path, std::ios_base::in);
    std::vector<int> outVector;
    int number;
    while (file >> number)
    {
        outVector.push_back(number);
    }

    return outVector;
}

int main()
{
    // Day One
    std::vector<int> problemOnePartOneInput = fileOfIntsToVector("AdventOfCode2020\\InputFiles\\1-1.txt");
    int answer = AdventOfCode2020::ProblemOne::multOfSums(problemOnePartOneInput, 2020);
    std::vector<int> problemOnePartTwoInput = fileOfIntsToVector("AdventOfCode2020\\InputFiles\\1-2.txt");
    answer = AdventOfCode2020::ProblemOne::multOfThreeSums(problemOnePartTwoInput, 2020);
    // Day Two
    answer = AdventOfCode2020::DayTwo::partOne("AdventOfCode2020\\InputFiles\\2-1.txt");
    answer = AdventOfCode2020::DayTwo::partTwo("AdventOfCode2020\\InputFiles\\2-2.txt");

	return 0;
}