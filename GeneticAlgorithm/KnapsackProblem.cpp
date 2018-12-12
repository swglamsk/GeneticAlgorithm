#include "stdafx.h"
#include "KnapsackProblem.h"


KnapsackProblem::KnapsackProblem()
{
}

KnapsackProblem::KnapsackProblem(std::string wFile, std::string vFile, int weight, int number)	
{
	max_weight = weight;
	std::fstream fileW(wFile, std::ios_base::in);
	std::fstream fileV(vFile, std::ios_base::in);

	weights = new int[number];
	values = new int[number];

	for (int i = 0; i < number; i++)
	{
		fileW >> weights[i];
		fileV >> values[i];
		std::cout << i << ". Waga: " << weights[i] << " Wartosc: " << values[i] << std::endl;
	}


}


KnapsackProblem::~KnapsackProblem()
{
	delete[] values;
	delete[] weights;
}
