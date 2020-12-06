#include "Problems.h"
#include "../Utilities.h"
#include <algorithm>
#include <set>
#include <fstream>
namespace AdventOfCode2020
{

	int ProblemOne::multOfSums(std::vector<int>& A, int targetSum)
	{
		// Sort the array
		std::sort(A.begin(), A.end());

		// Use a high and low, add them each loop
		// If the sum is over the target sum, then we need to reduce our sum, so decrement the high
		// If the sum is under the target sum, then we need to increase our sum, so increment the low

		int answer = 0;
		unsigned int low = 0, high = (A.size() - 1);
		unsigned int mid = A.size() / 2;
		while (low < high)
		{
			const int currentSum = A[low] + A[high];
			if (currentSum == targetSum)
			{
				answer = A[low] * A[high];
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

	int ProblemOne::multOfThreeSums(std::vector<int>& A, int targetSum)
	{
		// Best we can do is hash to get O(n^2)
		const unsigned int n = A.size();
		int answer = 0;
		for (unsigned int i = 0; i < n - 2; ++i)
		{
			std::set<int> sumSet;
			// We have our "current" sum, aka part 1 of the triplet (A + B + C). Search for (B + C) such that when added to A it equals our target.
			const int currentSum = targetSum - A[i];
			for (unsigned int j = i + 1; j < n; j++)
			{
				const int currentSubSum = currentSum - A[j];
				if (sumSet.find(currentSubSum) != sumSet.end())
				{
					answer = A[i] * A[j] * currentSubSum;
					return answer;
				}
				sumSet.insert(A[j]);
			}
		}
		return answer;
	}

	int DayTwo::partOne(std::string path)
	{
		// Given a big list of passwords and their rules, return how many passwords are valid.
		// Password structure is a map{char][vector<min/max allowed of 'char', password string>]

		std::fstream file(path, std::ios_base::in);
		std::string line;
		AdventOfCode2020::DayTwo::PasswordStructure ps;
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
		AdventOfCode2020::DayTwo::PasswordStructure ps;
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
			// No move the index to the character before the password, which will be offset by our give indices
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

}
