#include "Problems.h"
#include "../Utilities.h"
#include <algorithm>
#include <set>
#include <fstream>
namespace AdventOfCode2020
{
	int ProblemOne::partOne(std::string path, int targetSum)
	{
		std::fstream file(path, std::ios_base::in);
		std::vector<int> intVec;
		int number;
		while (file >> number)
		{
			intVec.push_back(number);
		}

		// Sort the array
		std::sort(intVec.begin(), intVec.end());

		// Use a high and low, add them each loop
		// If the sum is over the target sum, then we need to reduce our sum, so decrement the high
		// If the sum is under the target sum, then we need to increase our sum, so increment the low
		int answer = 0;
		unsigned int low = 0, high = (intVec.size() - 1);
		unsigned int mid = intVec.size() / 2;
		while (low < high)
		{
			const int currentSum = intVec[low] + intVec[high];
			if (currentSum == targetSum)
			{
				answer = intVec[low] * intVec[high];
				break;
			}
			else if (currentSum < targetSum)
			{
				++low;
			}
			else if (currentSum > targetSum)
			{
				--high;
			}
		}
		return answer;
	}

	int ProblemOne::partTwo(std::string path, int targetSum)
	{
		std::fstream file(path, std::ios_base::in);
		std::vector<int> intVec;
		int number;
		while (file >> number)
		{
			intVec.push_back(number);
		}
		// Best we can do is hash to get O(n^2)
		const unsigned int n = intVec.size();
		int answer = 0;
		for (unsigned int i = 0; i < n - 2; ++i)
		{
			std::set<int> sumSet;
			// We have our "current" sum, aka part 1 of the triplet (intVec + B + C). Search for (B + C) such that when added to intVec it equals our target.
			const int currentSum = targetSum - intVec[i];
			for (unsigned int j = i + 1; j < n; ++j)
			{
				const int currentSubSum = currentSum - intVec[j];
				if (sumSet.find(currentSubSum) != sumSet.end())
				{
					answer = intVec[i] * intVec[j] * currentSubSum;
					return answer;
				}
				sumSet.insert(intVec[j]);
			}
		}
		return answer;
	}

	int DayTwo::partOne(std::string path)
	{
		// Given a big list of passwords and their rules, return how many passwords are valid.
		std::fstream file(path, std::ios_base::in);
		std::string line;
		int successes = 0;
		// Eating one line at a time, format ##-## m: mmamammdmdmama
		while (std::getline(file, line))
		{
			int failuresThisChar = 0;
			int index = 0;
			char currChar = line[0];
			std::string firstNumber;

			// First we need to grab the minimum necessary occurrences of our char
			while (currChar != '-')
			{
				firstNumber += currChar;
				currChar = line[++index];
			}
			int min = std::stoi(firstNumber);
			currChar = line[++index];

			// Next we need to find the maximum allowed occurrences of our char
			std::string secondNumber;
			while (currChar != ' ')
			{
				secondNumber += currChar;
				currChar = line[++index];
			}
			int max = std::stoi(secondNumber);

			// Now grab the char that we will test against
			char key = line[++index];
			index += 3;

			// Now walk through the screen and count the occurrences of the char we are looking for
			int keyCharCount = 0;
			bool failedCriteria = false;
			while (currChar != '\0')
			{
				currChar = line[index];
				keyCharCount += (int)(currChar == key);
				// If we go over the max allowed, automatic fail
				if (keyCharCount > max)
				{
					failedCriteria = true;
					break;
				}
				++index;
			}
			// If we've finished, and are below the minumum, that's a fail
			if (keyCharCount < min)
			{
				failedCriteria = true;
			}

			// If not failed, success!
			if (!failedCriteria)
			{
				successes++;
			}
		}
		return successes;
	}

	int DayTwo::partTwo(std::string path)
	{
		std::fstream file(path, std::ios_base::in);
		std::string line;
		int successes = 0;
		// Eating one line at a time, format ##-## m: mmamammdmdmama
		while (std::getline(file, line))
		{
			int failuresThisChar = 0;
			int index = 0;
			char currChar = line[0];
			std::string firstNumber;

			// First we need to grab the first index to check
			while (currChar != '-')
			{
				firstNumber += currChar;
				currChar = line[++index];
			}
			int firstIndex = std::stoi(firstNumber);
			currChar = line[++index];

			// Next we need to find the second index to check
			std::string secondNumber;
			while (currChar != ' ')
			{
				secondNumber += currChar;
				currChar = line[++index];
			}
			int secondIndex = std::stoi(secondNumber);

			// Now grab the char that we will test against
			char key = line[++index];
			// Now move the index to the character before the password, which will be offset by our give indices
			index += 2;

			// Now we have to check the two given indices. One must be the desired char, but not both
			int offsetFirstIndex = index + firstIndex;
			int offsetSecondIndex = index + secondIndex;
			const bool neitherAreKey = (line[offsetFirstIndex] != key) && (line[offsetSecondIndex] != key);
			const bool bothMatch = (line[offsetFirstIndex] == line[offsetSecondIndex]);
			const bool failedCriteria = neitherAreKey || bothMatch; // Either of these means a fail. If both are false that means that one IS the key, and one is NOT

			// If not failed, success!
			if (!failedCriteria)
			{
				successes++;
			}
		}
		return successes;
	}


	int DayThree::partOne(std::string path)
	{
		int treeCount = 0;
		std::fstream file(path, std::ios_base::in);
		std::vector<std::string> grid;
		{
			std::string line;
			while (file >> line) // Matrix up our input file, so we can calculate the wraps easier
			{
				grid.push_back(line);
			}
		}
		const int MAX_COLS = grid[0].size();
		const int yShift = 3;
		int y = 0;
		for (std::string line : grid)
		{
			treeCount += (int)(line[y] == '#');
			y = ((y + yShift) % MAX_COLS);
		}
		return treeCount;
	}

	int DayThree::partTwo(std::string path, std::vector<std::pair<int, int>> shiftPairs)
	{
		int treeCountsProduct = 1;
		std::fstream file(path, std::ios_base::in);
		std::vector<std::string> grid;
		std::string line;
		while (file >> line) // Matrix up our input file, so we can calculate the wraps easier
		{
			grid.push_back(line);
		}
		const unsigned int MAX_ROWS = grid.size();
		const unsigned int MAX_COLS = grid[0].size();
		for (unsigned int pairIdx = 0; pairIdx < shiftPairs.size(); ++pairIdx)
		{
			int treeCount = 0;
			const int xShift = shiftPairs[pairIdx].first;
			const int yShift = shiftPairs[pairIdx].second;
			unsigned int y = 0;
			for (unsigned int x = 0; x < MAX_ROWS; x += xShift)
			{
				treeCount += (int)(grid[x][y] == '#');
				y = ((y + yShift) % MAX_COLS);
			}
			treeCountsProduct *= treeCount;
		}
		return treeCountsProduct;
	}
}