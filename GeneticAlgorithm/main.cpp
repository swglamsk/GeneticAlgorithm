// GeneticAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GeneticAlgorithm.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(std::time(nullptr));
	GeneticAlgorithm test(10, 0.1, 0.1);
 	for(int i = 0; i < 10; i++)
	std::cout << test.run(10) << std::endl;
	std::getchar();

}

