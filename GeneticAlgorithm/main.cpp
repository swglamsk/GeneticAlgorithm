// GeneticAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneticAlgorithm.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(std::time(nullptr));
	GeneticAlgorithm test(4, 0.1, 0.1);
	std::cout << test.run(10000) << std::endl;
	std::getchar();

}

