#include "Problems.h"
#include "../Utilities.h"
#include <algorithm>
#include <set>
#include <fstream>
#include <regex>
#include <bitset>
#include <map>

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
	int DayFour::partOne(std::string path)
	{
		int validCount = 0;
		std::vector<std::map<std::string, std::string>> passportVector = makePassportVector(path);
		const int MAX_PASSPORT_FIELDS = 8;
		for (auto passport : passportVector)
		{
			// Now check our success conditions
			if (passport.size() == MAX_PASSPORT_FIELDS ||
				((passport.size() == (MAX_PASSPORT_FIELDS - 1)) && (passport.find("cid") == passport.end())))
			{
				validCount++;
			}
		}
		return validCount;
	}

	int DayFour::partTwo(std::string path)
	{
		int validCount = 0;
		std::vector<std::map<std::string, std::string>> passportVector = makePassportVector(path);
		const int MAX_PASSPORT_FIELDS = 8;

		// Go through one passport at a time
		for (auto passportIt = passportVector.begin(); passportIt != passportVector.end(); ++passportIt)
		{
			bool isValid = true;
			if (passportIt->size() == MAX_PASSPORT_FIELDS || // If we have all the fields
				((passportIt->size() == (MAX_PASSPORT_FIELDS - 1)) && (passportIt->find("cid") == passportIt->end()))) // If we're missing ONLY cid
			{
				// Data validation
				// byr - must be 4 digits between 1920 and 2002
				isValid &= (passportIt->find("byr") != passportIt->end())
					&& std::regex_search(passportIt->find("byr")->second.cbegin(), passportIt->find("byr")->second.cend(), std::regex("^\\d{4}$")) // 4 digits 
					&& ((std::stoi(passportIt->find("byr")->second) >= 1920) && (std::stoi(passportIt->find("byr")->second) <= 2002));
				// iry - between 2010 & 2020
				isValid &= (passportIt->find("iyr") != passportIt->end())
					&& std::regex_search(passportIt->find("iyr")->second.cbegin(), passportIt->find("iyr")->second.cend(), std::regex("^\\d{4}$")) // 4 digits 
					&& ((std::stoi(passportIt->find("iyr")->second) >= 2010) && (std::stoi(passportIt->find("iyr")->second) <= 2020));
				// eyr - between 2020 & 2030
				isValid &= (passportIt->find("eyr") != passportIt->end())
					&& std::regex_search(passportIt->find("eyr")->second.cbegin(), passportIt->find("eyr")->second.cend(), std::regex("^\\d{4}$")) // 4 digits 
					&& ((std::stoi(passportIt->find("eyr")->second) >= 2020) && (std::stoi(passportIt->find("eyr")->second) <= 2030));
				// hgt - number followed by "cm" or "in"
				isValid &= ((passportIt->find("hgt") != passportIt->end()) && isHeightValid(passportIt->find("hgt")->second));
				// hcl - a # followed by exactly six characters 0-9 or a-f
				isValid &= (passportIt->find("hcl") != passportIt->end())
					&& std::regex_search(passportIt->find("hcl")->second.cbegin(), passportIt->find("hcl")->second.cend(), std::regex("^#[a-f0-9]{6}$"));
				// ecl - exactly one of: amb blu brn gry grn hzl oth
				isValid &= (passportIt->find("ecl") != passportIt->end()) && (isEyeColorValid(passportIt->find("ecl")->second));
				// a nine digit number, including leading zeroes
				isValid &= (passportIt->find("pid") != passportIt->end())
					&& std::regex_search(passportIt->find("pid")->second.cbegin(), passportIt->find("pid")->second.cend(), std::regex("^\\d{9}$"));
			}
			else
			{
				isValid = false;
			}

			validCount += (int)isValid;
		}
		return validCount;
	}

	std::vector<std::map<std::string, std::string>> DayFour::makePassportVector(std::string path)
	{
		std::fstream file(path, std::ios_base::in);
		std::string line;
		std::vector<std::map<std::string, std::string>> passportVector;
		std::map<std::string, std::string> passport;

		std::regex keyValueRegex("(...):(\\S*)");
		std::smatch matches;

		while (std::getline(file, line))
		{
			if (line.empty()) // End of passport matching, push back what the deets and clear it for reuse
			{
				passportVector.push_back(passport);
				passport.clear();
			}

			std::string::const_iterator searchStart(line.cbegin());
			while (std::regex_search(searchStart, line.cend(), matches, keyValueRegex))
			{
				std::string key = matches[1];
				std::string value = matches[2];
				passport[key] = value;
				searchStart = matches.suffix().first;
			}
		}
		return passportVector;
	}

	bool DayFour::isHeightValid(std::string heightString)
	{
		bool isValid = false;
		std::smatch matches;
		if (std::regex_search(heightString.cbegin(), heightString.cend(), matches, std::regex("^([0-9]*)(in|cm)$")))
		{
			const std::string unit = matches[2];
			const int height = std::stoi(matches[1]);
			if (unit == "in")
			{
				isValid = height >= 59 && height <= 76;
			}
			else if (unit == "cm")
			{
				isValid = height >= 150 && height <= 193;
			}
		}
		return isValid;
	}

	// exactly one of: amb blu brn gry grn hzl oth
	bool DayFour::isEyeColorValid(std::string eyeColorString)
	{
		return (eyeColorString == "amb")
			|| (eyeColorString == "blu")
			|| (eyeColorString == "brn")
			|| (eyeColorString == "gry")
			|| (eyeColorString == "grn")
			|| (eyeColorString == "hzl")
			|| (eyeColorString == "oth");
	}

	int DayFive::partOne(std::string path)
	{
		std::fstream file(path, std::ios_base::in);
		std::string line;
		int maxSeatId = 0;
		while (file >> line)
		{
			std::bitset<7> rowBitset;
			int lineIdx = 6;
			for (int bitIdx = 0; bitIdx < 7; ++bitIdx)
			{
				rowBitset[bitIdx] = (int)(line[lineIdx--] == 'B');
			}
			int row = (int)rowBitset.to_ulong();

			std::bitset<3> colBitset;
			lineIdx = 9;
			for (int bitIdx = 0; bitIdx < 3; ++bitIdx)
			{
				colBitset[bitIdx] = (int)(line[lineIdx--] == 'R');
			}
			int col = colBitset.to_ulong();

			int seatId = (row * 8) + col;
			maxSeatId = std::max(seatId, maxSeatId);
		}
		return maxSeatId;
	}

	int DayFive::partTwo(std::string path)
	{
		std::fstream file(path, std::ios_base::in);
		std::string line;
		std::set<int> occupancyList;
		while (file >> line)
		{
			std::bitset<7> rowBitset;
			int lineIdx = 6;
			for (int bitIdx = 0; bitIdx < 7; ++bitIdx)
			{
				rowBitset[bitIdx] = (int)(line[lineIdx--] == 'B');
			}
			int row = (int)rowBitset.to_ulong();

			std::bitset<3> colBitset;
			lineIdx = 9;
			for (int bitIdx = 0; bitIdx < 3; ++bitIdx)
			{
				colBitset[bitIdx] = (int)(line[lineIdx--] == 'R');
			}
			int col = colBitset.to_ulong();

			int seatId = (row * 8) + col;
			occupancyList.insert(seatId);
		}
		// Ok this part is bullshit. Just literally find the missing seat from the list of all seats. 
		// There was some mumbo jumbo in the problem about how seats are missing from the front and back of the aircraft.. whatever ok. 
		int mySeat = 0;
		for (auto prevSeatIt = occupancyList.begin(), seatIt = std::next(occupancyList.begin()); seatIt != occupancyList.end(); ++seatIt, ++prevSeatIt)
		{
			const int currentSeat = *seatIt, previousSeat = *prevSeatIt;
			if ((previousSeat + 1) != currentSeat)
			{
				mySeat = previousSeat + 1;
			}
		}
		return mySeat;
	}
	int DaySix::partOne(std::string path)
	{
		std::fstream file(path, std::ios_base::in);
		std::string line;
		std::set<char> answerCounts;
		int totalUniques = 0;
		while (std::getline(file, line))
		{
			if (line.empty()) // Done collecting a group, store the answers
			{
				totalUniques += answerCounts.size();
				answerCounts.clear();
			}
			else
			{
				// Throw all the letters into a set.
				for (char answerLetter : line)
				{
					answerCounts.insert(answerLetter);
				}
			}
		}
		return totalUniques;
	}
	int DaySix::partTwo(std::string path)
	{
		std::fstream file(path, std::ios_base::in);
		std::string line;
		// Everyone in the group must share a common answer for it to count.
		std::set<char> personAnswers;
		std::map<int, std::set<char>> groupAnswers;
		int group = 0, person = 0;
		int totalUniques = 0;
		while (std::getline(file, line))
		{
			if (line.empty()) // Done collecting a group, store the answers
			{
				// If every person in this group shares a letter, store it.
				int sharedYeses = 0;
				for (char letter = 'a'; letter <= 'z'; ++letter)
				{
					bool agreedAnswer = true;
					for (auto personIt : groupAnswers)
					{
						agreedAnswer &= personIt.second.find(letter) != personIt.second.end();
					}
					if (agreedAnswer)
					{
						++sharedYeses;
					}

				}
				// Accumulate the number total shared letters 
				totalUniques += sharedYeses;
				// Reset our counters
				person = 0;
				groupAnswers.clear();
				personAnswers.clear();
			}
			else
			{
				// New person, log their yeses
				for (char yes : line)
				{
					personAnswers.insert(yes);
				}
				// Finished logging this persons yeses, store it in the map
				groupAnswers[person] = personAnswers;
				personAnswers.clear();
				++person;
			}
		}
		return totalUniques;
	}
}