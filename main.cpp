#include "CodilityLessons/Lesson1.h"
#include "CodilityLessons/Lesson2.h"
#include "CodilityLessons/Lesson3.h"
#include "CodilityLessons/Lesson4.h"
#include "CodilityLessons/Lesson5.h"
#include "CodilityLessons/Lesson6.h"
#include <algorithm>
#include <iostream>

void print_vector(std::vector<int>& a)
{
    std::for_each(a.begin(), a.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;
}

int main()
{

	return 0;
}